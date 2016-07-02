//
//  search_missing_number.cpp
//  HackerRank
//
//  Created by Shihao Zhang on 6/29/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "search_missing_number.hpp"


Solution::Solution(){
    this->frequency = vector<long>(this->range, 0);
}

void Solution::firstIn(vector<int>& arr){
    for (int i : arr) {
        this->frequency[i]++;
    }
}


void Solution::secondIn(vector<int> &arr){
    for (int i : arr) {
        this->frequency[i]--;
    }
}

void Solution::printDiff(){
    for (int i = 0; i < this->frequency.size(); i++) {
        if (this->frequency[i]) {
            cout << i << " ";
        }
    }
}

int main(){
    long first;  cin >> first;
    vector<int> arr1(first, 0);
    for (long i = 0; i < first; i++) {
        cin >> arr1[i];
    }
    long second;    cin >> second;
    vector<int> arr2(second, 0);
    for (long i = 0; i < second; i++) {
        cin >> arr2[i];
    }
    
    Solution *dz = new Solution();
    dz->firstIn(arr1);
    dz->secondIn(arr2);
    dz->printDiff();
    return 0;
}

/*
 10
 203 204 205 206 207 208 203 204 205 206
 13
 203 204 204 205 206 207 205 208 203 206 205 206 204
*/
int main(){
    vector<int> arr1 = {203, 204, 205, 206, 207, 208, 203, 204, 205, 206};
    vector<int> arr2 = {203, 204, 204, 205, 206, 207, 205, 208, 203, 206, 205, 206, 204};
    Solution *dz = new Solution();
    dz->firstIn(arr1);
    dz->secondIn(arr2);
    dz->printDiff();
    return 0;
}