#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> readvector(){
    int num_tests = 0;  cin >> num_tests;
    vector<int> arr;
    for(int i = 0; i < num_tests; i++){
        int hold;   cin >> hold;    arr.push_back(hold);
    }
    return arr;
}
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

int add_value(int value, node* root){
    int count = 0;
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
    curr_node->set_parent(parent);
    if (cmp == 1) {
        parent->set_right(curr_node);
    }
    else if(cmp == -1){
        parent->set_left(curr_node);
    }
    return count;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num = 0;    cin >> num;
    for(int i = 0; i < num; i++){
        vector<int> arr = readvector();
        int count = 0;
        node* root = new node(arr[0]);
        for(int idx = 1; idx < arr.size(); idx++){
            count += add_value(arr[idx], root);
        }
        cout << count << endl;
        delete root;    root = nullptr;
    }
    return 0;
}
