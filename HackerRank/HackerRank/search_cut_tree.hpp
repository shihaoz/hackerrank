//
//  search_cut_tree.hpp
//  HackerRank
//
//  Created by Shihao Zhang on 7/1/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#ifndef search_cut_tree_hpp
#define search_cut_tree_hpp

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <limits>
using namespace std;

class Node {
    int value;
    long sum;   // sum of subtree, given this is the root
    static long min_diff;
public:
    vector<Node*> real_children;
    vector<Node*> children;
    Node(int input): value(input), sum(0){
        // constructor
    }
    long DFS(unordered_set<Node*>& node_visited);
    void addChild(Node* child);
    void calcDiff(long parent);
    
    static void printDiff(){
        cout << min_diff << "\n";
    }
};
#endif /* search_cut_tree_hpp */
