//
//  fun_if_graph_one_draw.hpp
//  HackerRank
//
//  Created by Shihao Zhang on 7/1/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#ifndef fun_if_graph_one_draw_hpp
#define fun_if_graph_one_draw_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
using namespace std;

class Edge;

class Node {
    
public:
    int node_id;
    vector<Edge*> list_edge;
    Node(int id) : node_id(id){
    }
    void addEdge(Edge* ed){
        list_edge.push_back(ed);
    }
    void drawNext();
};

class Edge {
    
public:
    int edge_id;
    Node *node1, *node2;
    Edge(Node* a, Node* b, int id):
    node1(a), node2(b), edge_id(id){
        // constructor
        a->addEdge(this);
        b->addEdge(this);
    }
    Node* otherSide(Node* node){
        if (node->node_id == node1->node_id) {
            return node2;
        }
        return node1;
    }
};

class GraphState{

public:
    static unordered_set<int> edge_have_been;
    static int edge_id;
    static int node_id;
    static int total_edge;
    static int total_node;
    static deque<string> message_queue;
    static bool ifFinished() {
        return total_edge == edge_have_been.size();
    }
    int getNodeId() const {return node_id++;}
    int getEdgeId() const {return edge_id++;}
};
#endif /* fun_if_graph_one_draw_hpp */
