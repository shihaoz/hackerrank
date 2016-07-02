//
//  search_cut_tree.cpp
//  HackerRank
//
//  Created by Shihao Zhang on 7/1/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "search_cut_tree.hpp"
#include <fstream>


long Node::min_diff = numeric_limits<long>::max();

void Node::addChild(Node *child){
    children.push_back(child);
}

long Node::DFS(unordered_set<Node*>& node_visited){
    node_visited.insert(this);
    sum = this->value;
    for (Node* i : children) {
        if (node_visited.find(i) == node_visited.end()) {
            sum += i->DFS(node_visited);
            real_children.push_back(i);
        }
    }
    return this->sum;
}

void Node::calcDiff(long parent){
    for (auto i : real_children) {
        min_diff = min(abs(parent + this->sum - 2*i->sum), min_diff);
        i->calcDiff(this->sum - i->sum + parent);
    }
}


int main(){
    ifstream infile("/Users/DavidZhang/Desktop/Programming Practice/HackerRank/HackerRank/HackerRank/test.txt");
    int num, holder;    infile >> num;
    vector<Node*> vertices(num, 0);
    unordered_set<Node*> nodes_visited;
    
    for (int i = 0; i < num; i++) {
        infile >> holder;
        vertices[i] = new Node(holder);
    }
    for (int i = 1; i < num; i++) {
        int a, b;   infile >> a >> b;
        vertices[a-1]->addChild(vertices[b-1]);
        vertices[b-1]->addChild(vertices[a-1]);
    }
    // call dfs on root
    vertices[0]->DFS(nodes_visited);
    vertices[0]->calcDiff(0);
    Node::printDiff();
    return 0;
}