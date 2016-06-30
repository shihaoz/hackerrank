//
//  maximum_sum.hpp
//  interview_2016
//
//  Created by Shihao Zhang on 6/29/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#ifndef maximum_sum_hpp
#define maximum_sum_hpp

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;


/*
 maximum subarray之类的问题，先construct出一个rolling summation array.
 往往累积的calculation有助于解答（因为可以将大问题逐步变成小问题）
 关键在于，modulo: (a+b)%M = a%M + b%M; subarray的
 */

class Solution {
    
    
public:
    vector<long> array;
    vector<long> prefix;
    set<long> tree;
    long size, modulo;
    long largest_sum;
    
    Solution();
    void readVector();
    void readVector(vector<long>& arr, long modulo);
    void constructPrefix();
    /*
     R: index in range [0, size-1]
     E: find the largest subarray sum%modulo at this index
     */
    void checkIndex(long idx);
    
    long getSize() const {return array.size();}
    long getAnswer() const {return largest_sum;}
};
#endif /* maximum_sum_hpp */
