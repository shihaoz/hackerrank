#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "tree_node.h"
using namespace std;
vector<long> readvector(){
    int num_tests = 0;  cin >> num_tests;
    vector<long> arr;
    for(int i = 0; i < num_tests; i++){
        long hold;   cin >> hold;    arr.push_back(hold);
    }
    return arr;
}




long add_value(long value, node* root){
    long count = 0;
    node* curr_node = root, *parent = nullptr;
    int cmp = 0;
    while(curr_node != nullptr){
        /* do counting + increment sum */
        count += curr_node->get_right_sum();
        parent = curr_node;                     // record parent
        cmp = curr_node->cmp(value);
        if(cmp == 0){
            // found it
            curr_node->add_here();
            return count;
        }
        else if(cmp == 1){
            // value > curr_node
            count -= curr_node->get_right_sum();    // reset count
            curr_node->add_right();                 // increment right sum
            curr_node = curr_node->go_right();      // move right
        }
        else{
            // value < curr_node
            curr_node->add_left();                  // increment left sum
            count += curr_node->get_here_sum();     // add the curr_node to count
            curr_node = curr_node->go_left();       // move left
        }
    }
    curr_node = new node(value);
    curr_node->set_parent(parent, cmp);
    if (cmp == 1) {
        parent->set_right(curr_node);
    }
    else if(cmp == -1){
        parent->set_left(curr_node);
    }
    /* increment height of parents */
    long height = 2;
    while(parent && parent->height < height){
        parent->height = height;
        height += 1;
        parent = parent->get_parent();
    }
    /* check balance */
    curr_node = curr_node->get_parent()->get_parent();
    int counter = 0;
    while(curr_node && (curr_node->if_balance()) && counter < 3){
        curr_node = curr_node->get_parent();
        counter++;
    }
    if (curr_node) {
        curr_node->balance();
    }

    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num = 0;    cin >> num;
    for(int i = 0; i < num; i++){
        vector<long> arr = readvector();
        long count = 0;
        root = new node(arr[0]);
        for(long idx = 1; idx < arr.size(); idx++){
            count += add_value(arr[idx], root);
        }
        cout << count << endl;
        delete root;    root = nullptr;
    }
    return 0;
}

//int main(){
//    vector<int> arr = {97, 69, 63, 74, 28};
//    long count = 0;
//    root = new node(arr[0]);
//    for(long idx = 1; idx < arr.size(); idx++){
//        count += add_value(arr[idx], root);
//    }
//    cout << count << endl;
//    delete root;    root = nullptr;
//    return 0;
//}