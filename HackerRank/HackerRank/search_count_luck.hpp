//
//  search_count_luck.hpp
//  HackerRank
//
//  Created by Shihao Zhang on 7/1/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#ifndef search_count_luck_hpp
#define search_count_luck_hpp

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


vector<vector<bool>> grid_been_to;

class Step {

    
public:
    static int max_row, max_column;
    int x, y;
    int wave;   // number of wave at this point
    Step(int in_x, int in_y, int in_w) : x(in_x), y(in_y), wave(in_w){
        // constructor
    }
    vector<Step*> getSurrounds();
};

#endif /* search_count_luck_hpp */
