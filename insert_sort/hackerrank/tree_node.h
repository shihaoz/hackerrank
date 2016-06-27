#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

#ifndef __NODE__
#define __NODE__
class node {
private:
    /* data */
    long value; long sum_left, sum_right, sum_here;

public:
    node* left, *right, *parent; int which_child;   // 1==right child, -1==left child
    long height;
    node (long value){
        this->value = value;
        sum_left = sum_right = 0;  sum_here = 1;
        left = right = parent = nullptr;
        which_child = 0;
        height = 1;
    }

    int cmp(int val);
    void set_left(node* input){this->left = input;}
    void set_left_sum(long input){this->sum_left = input;}
    void set_right(node* input){this->right = input;}
    void set_right_sum(long input){this->sum_right = input;}
    void set_parent(node* input, int cmp){this->parent = input; which_child=cmp;}
    node* go_left(){return this->left;}
    node* go_right(){return this->right;}
    node* get_parent(){return this->parent;}
    void add_left(){this->sum_left++;}
    void add_right(){this->sum_right++;}
    void add_here(){this->sum_here++;}
    long get_right_sum(){return this->sum_right;}
    long get_left_sum(){return this->sum_left;}
    long get_here_sum(){return this->sum_here;}
    long get_value(){return this->value;}
    void calculate_height(){
        long left_height = (this->left) ? this->left->height : 0;
        long right_height = (this->right) ? this->right->height : 0;
        this->height = max(left_height, right_height) + 1;
    }
    long get_balance();
    bool if_balance();
    void rotate_left();

    void rotate_right();
    
    bool balance();
};

extern node* root;
#endif