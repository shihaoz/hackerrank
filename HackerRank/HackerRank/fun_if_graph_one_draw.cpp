//
//  fun_if_graph_one_draw.cpp
//  HackerRank
//
//  Created by Shihao Zhang on 7/1/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "fun_if_graph_one_draw.hpp"
#include <fstream>


deque<string> GraphState::message_queue;
int GraphState::edge_id = 0;
int GraphState::node_id = 0;
int GraphState::total_edge = 0;
int GraphState::total_node = 0;
unordered_set<int> GraphState::edge_have_been;

void Node::drawNext(){

    if (GraphState::ifFinished()) {
        ofstream outfile("/Users/DavidZhang/Desktop/Programming Practice/HackerRank/HackerRank/HackerRank/sol.txt", std::ofstream::app);
        outfile << "Solution:\n";
        for (string msg : GraphState::message_queue) {
            outfile << msg;
        }
        outfile << "Solved\n";
        return;
    }
    for (Edge* ed : list_edge) {
        if (GraphState::edge_have_been.find(ed->edge_id) == GraphState::edge_have_been.end()) {
            // never visited
            GraphState::edge_have_been.insert(ed->edge_id);
            string msg = to_string(this->node_id+1) + " -> " + to_string(ed->otherSide(this)->node_id+1) + "\n";
            cout << msg;
            GraphState::message_queue.push_back(msg);
            ed->otherSide(this)->drawNext();
            GraphState::edge_have_been.erase(ed->edge_id);
            GraphState::message_queue.pop_back();
            cout << this->node_id+1 << " -> " << ed->otherSide(this)->node_id+1 << " Revoked\n";
        }
    }
}


GraphState graphState;
int main(){
    ifstream infile("/Users/DavidZhang/Desktop/Programming Practice/HackerRank/HackerRank/HackerRank/test.txt");
    int num;    infile >> num;  infile.get();
    vector<Node*> vertices(num, nullptr);
    vector<Edge*> edges;
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] = new Node(graphState.getNodeId());
    }
    int a, b;   string holder;
    while (getline(infile, holder)) {
        a = atoi(holder.substr(0, holder.find(' ')).c_str());
        b = atoi(holder.substr(holder.find(' ')+1).c_str());
        edges.push_back(new Edge(vertices[a-1], vertices[b-1], graphState.getEdgeId()));
    }
    GraphState::total_edge = edges.size();
    GraphState::total_node = vertices.size();
    for (Node* node : vertices) {
        node->drawNext();
    }
    return 0;
}