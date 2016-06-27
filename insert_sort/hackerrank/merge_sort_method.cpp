//
//  merge_sort_method.cpp
//  insert_sort
//
//  Created by Shihao Zhang on 6/26/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<long> readvector(){
    int num_tests = 0;  cin >> num_tests;
    vector<long> arr;
    for(int i = 0; i < num_tests; i++){
        long hold;   cin >> hold;    arr.push_back(hold);
    }
    return arr;
}

vector<long> merge(vector<long>& left, vector<long>& right, long& count){
    vector<long> ret;    ret.reserve(left.size() + right.size());
    int idx_left = 0, idx_right = 0;
    while (idx_left < left.size() && idx_right < right.size()) {
        if (left[idx_left] <= right[idx_right]) {
            ret.push_back(left[idx_left++]);
        }
        else{
            ret.push_back(right[idx_right++]);
            count += (left.size() - idx_left);
        }
    }
    while (idx_left < left.size()) {
        ret.push_back(left[idx_left++]);
    }
    while(idx_right < right.size()){
        ret.push_back(right[idx_right++]);
    }

    return ret;
}


// @require: end is the end index, not one-past-end
void merge_sort(vector<long>& arr, long& count){
    if (arr.size()==1) {
        return;
    }
    int start = 0;  long end = arr.size()-1;
    long mid = start + (end-start)/2;
    vector<long> left(arr.begin(), arr.begin()+mid+1);
    vector<long> right(arr.begin()+mid+1, arr.end());
    merge_sort(left, count);
    merge_sort(right, count);
    arr = merge(left, right, count);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num = 0;    cin >> num;
    for(int i = 0; i < num; i++){
        vector<long> arr = readvector();
        long count = 0;
        merge_sort(arr, count);
        cout << count << endl;
    }
    return 0;
}

//int main(){
//    vector<long> arr = {1,7,2,9,6,4,5,3};
//    long count = 0;
//    merge_sort(arr, count);
//    cout << count << endl;
//    return 0;
//}