//
//  searching_max_sum.cpp
//  insert_sort
//
//  Created by Shihao Zhang on 6/28/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "searching_max_sum.hpp"


int main(){
    long num;    cin >> num;
    while (num--) {
        long long size, modulo;  cin >> size >> modulo;
        vector<long long> arr(size, 0);
        for (long long i = 0; i < size; i++) {
            cin >> arr[i];
        }
        // finish read in
        
        cout << methodn2(arr, modulo) << "\n";
        
    }
    return 0;
}

//int main(){
//    long modulo = 7;
//    vector<long> arr = {3, 3, 9, 9, 5};
//    cout << methodn2(arr, modulo) << "\n";
//    return 0;
//}


long long methodn2(vector<long long >& arr, long long modulo){
    long long record = 0;

    for(long long i = 0; i < arr.size(); i++){
        long long sum = 0, largest_remainder = 0;
        long long idx = i;
        while (idx < arr.size()) {
            sum += arr[idx++];
            long long remain = sum % modulo;

            if (remain > largest_remainder) {
                largest_remainder = (sum%modulo);
            }
            if (sum >= modulo) {
                sum -= modulo;
            }
        }
        record = max(record, largest_remainder);
    }
    
    return record;
}