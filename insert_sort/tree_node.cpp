//
//  tree_node.cpp
//  insert_sort
//
//  Created by Shihao Zhang on 6/26/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include <stdio.h>
#include "tree_node.h"

node* root;
int node::cmp(int val){
    if (val > this->value) {return 1;}
    else if(val == this->value){return 0;}
    else{return -1;}
}
long node::get_balance(){
    long left_height = (this->left) ? this->left->height : 0;
    long right_height = (this->right) ? this->right->height : 0;
    return right_height - left_height;
}
bool node::if_balance(){
    return abs(get_balance()) <= 1;
}
void node::rotate_left(){
    node* new_root = this->right;
    /* 1. parent property */
    if (this->parent) {
        if (which_child == 1) {
            this->parent->right = new_root;
        }
        else{
            this->parent->left= new_root;
        }
        new_root->which_child = which_child;
        new_root->parent = this->parent;
    }
    else{
        new_root->parent = nullptr;
        root = new_root;
    }
    /* 2. child left/right property */
    this->right = new_root->go_left();
    if(this->right){
        this->right->which_child = 1;   this->right->parent = this;
    }
    this->parent = new_root;    this->which_child = -1;
    new_root->left = this;
    
    /* 3. set sum
     1. parent sum doesn't change; total # children same
     2. new root left_sum changes
     3. this right_sum changes
     */
    if (this->right) {
        this->sum_right = this->right->get_left_sum() +
                            this->right->get_right_sum() +
                            this->right->get_here_sum();
    }
    else{
        this->set_right_sum(0);
    }
    new_root->sum_left = this->get_here_sum() + this->get_right_sum() + this->get_left_sum();
    /* set height */
    this->calculate_height();
    new_root->calculate_height();
}

void node::rotate_right(){
    node* new_root = this->left;
    /* 1. parent property */
    if (this->parent) {
        if (which_child == 1) {
            this->parent->right = new_root;
        }
        else{
            this->parent->left = new_root;
        }
        new_root->which_child = which_child;
        new_root->parent = this->parent;
    }
    else{
        new_root->parent = nullptr;
        root = new_root;
    }
    /* 2. child left/right */
    this->left = new_root->go_right();
    if(this->left){
        this->left->which_child = -1;   this->left->parent = this;
    }
    this->parent = new_root;    this->which_child = 1;
    new_root->right = this;
    
    /* 3. set sum
     1. parent sum doesn't change; total # children same
     2. new root left_sum changes
     3. this right_sum changes
     */
    if (this->left) {
        this->sum_left = this->left->get_left_sum() +
                            this->left->get_right_sum() +
                            this->left->get_here_sum();
    }
    else{
        this->sum_left = 0;
    }
    new_root->sum_right = this->get_here_sum() + this->get_right_sum() + this->get_left_sum();
    /* set height */
    this->calculate_height();
    new_root->calculate_height();
    
}

bool node::balance(){
    long bal = this->get_balance();
    if (bal >= -1 && bal <= 1) {
        return true;
    }
    if (bal > 1) {
        /* need rotation */
        // check right sub child balance
        long child_bal = this->right->get_balance();
        if(child_bal < 0){
            /* right rotate child */
            this->right->rotate_right();
        }
        this->rotate_left();
        return false;
    }
    else{
        // check left sub child balance
        long child_bal = this->left->get_balance();
        if (child_bal > 0) {
            this->left->rotate_left();
        }
        this->rotate_right();
        return false;
    }
}