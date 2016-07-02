//
//  search_connected_cell.hpp
//  HackerRank
//
//  Created by Shihao Zhang on 6/30/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#ifndef search_connected_cell_hpp
#define search_connected_cell_hpp

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class arguments {
    
public:
    int x, y, group;
    arguments(int x, int y, int group){
        this->x = x;    this->y = y;    this->group = group;
    }
};
#endif /* search_connected_cell_hpp */
