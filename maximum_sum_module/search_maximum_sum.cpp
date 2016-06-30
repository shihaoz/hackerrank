
//
//  search_maximum_sum.cpp
//  HackerRank
//
//  Created by Shihao Zhang on 6/29/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "search_maximum_sum.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>


Solution::Solution(){
    this->largest_sum = this->modulo = this->size = 0;
    
}

void Solution::readVector(){
    cin >> size >> modulo;
    array = vector<long>(size, 0);
    this->largest_sum = 0;
    for(long i = 0; i < size; i++){
        cin >> array[i];
    }
}

void Solution::readVector(vector<long> &arr, long modulo){
    this->array = move(arr);
    this->size = this->array.size();
    this->modulo = modulo;
}

void Solution::constructPrefix(){
    tree.clear();
    prefix = vector<long>(size, 0);
    long sum = 0;
    for (long i = 0; i < array.size(); i++) {
        sum = (sum + array[i]) % modulo;
        prefix[i] = sum;
    }
}

void Solution::checkIndex(long idx){
    long largest = 0;
    try {
        largest = this->prefix[idx] % this->modulo;
    } catch (exception& e) {
        throw out_of_range("invalid index "+ to_string(idx));
    }
    
    set<long>::iterator it = this->tree.insert(largest).first;
    it++;   // find the next largest element
    if (it != this->tree.end()) {
        largest = max(largest, (largest - *it + this->modulo));
    }
    
    this->largest_sum = max(largest, this->largest_sum);
}


int main(){
    int num;    cin >> num;
    Solution *dz = new Solution();
    while (num--) {
        dz->readVector();
        dz->constructPrefix();
        long size = dz->getSize();
        for(long i = 0; i < size; i++){
            dz->checkIndex(i);
        }
        
        cout << dz->getAnswer() << "\n";
    }
}

int main(){
    long modulo = 13;
    vector<long> arr = {8, 5, 3, 3, 9, 9, 5};
    
    Solution* dz = new Solution();
    dz->readVector(arr, modulo);
    dz->constructPrefix();
    long size = dz->getSize();
    for(long i = 0; i < size; i++){
        dz->checkIndex(i);
    }

    cout << dz->getAnswer() << "\n";
    
    return 0;
}