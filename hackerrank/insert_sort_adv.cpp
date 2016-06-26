#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node {
private:
    /* data */
    int value, sum_left, sum_right, sum_here;
    node* left, *right, *parent;
public:
    node (int value){
        this->value = value;
        sum_left = sum_right = 0;  sum_here = 1;
        left = right = parent = nullptr;
    }
    
    int cmp(int val){
        if (val > this->value) {return 1;}
        else if(val == this->value){return 0;}
        else{return -1;}
    }
    void set_left(node* input){this->left = input;}
    void set_right(node* input){this->right = input;}
    void set_parent(node* input){this->parent = input;}
    node* go_left(){return this->left;}
    node* go_right(){return this->right;}
    void add_left(){this->sum_left++;}
    void add_right(){this->sum_right++;}
    void add_here(){this->sum_here++;}
    int get_right_sum(){return this->sum_right;}
    int get_left_sum(){return this->sum_left;}
    int get_here_sum(){return this->sum_here;}
    int get_value(){return this->value;}
};

void add_value(int value, node* root){
    int count = 0;
    node* curr_node = root, *parent = nullptr;
    while(curr_node != nullptr){
        /* do counting + increment sum */
        count += curr_node->get_right_sum();
        parent = curr_node;                     // record parent
        int cmp = curr_node->cmp(value);
        if(cmp == 0){
            // found it
            curr_node->add_here();
            cout << count << "\n";
            return;
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
    cout << count << "\n";
    curr_node = new node(value);
    curr_node->set_parent(parent);
}

int main(){
    vector<int> test = {2, 1, 3, 1, 2};
    node* root = new node(test[0]);
    for(int i = 1; i < test.size(); i++){
        add_value(test[i], root);
    }
    return 0;
}