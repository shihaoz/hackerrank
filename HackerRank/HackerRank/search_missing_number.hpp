//
//  search_missing_number.hpp
//  HackerRank
//
//  Created by Shihao Zhang on 6/29/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#ifndef search_missing_number_hpp
#define search_missing_number_hpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    
    int range = 10000;
public:
    vector<long> frequency;
    Solution();
    void firstIn(vector<int>& arr);
    void secondIn(vector<int>& arr);
    void printDiff();
};

#endif /* search_missing_number_hpp */
