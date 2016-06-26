class node {
private:
    /* data */
    long value; long sum_left, sum_right, sum_here;

public:
    node* left, *right, *parent; int which_child;   // 1==right child, -1==left child
    int height;
    node (long value){
        this->value = value;
        sum_left = sum_right = 0;  sum_here = 1;
        left = right = parent = nullptr;
        which_child = 0;
        height = 1;
    }

    int cmp(int val){
        if (val > this->value) {return 1;}
        else if(val == this->value){return 0;}
        else{return -1;}
    }
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
    int get_value(){return this->value;}

    int get_balance(){
        int left_height = (this->left) ? this->left->get_height() : 0;
        int right_height = (this->right) ? this->right->get_height() : 0;
        return right_height - left_height;
    }
    void rotate_left(){
        node* new_root = this->right;
        if (this->parent) {
            if (which_child == 1) {
                this->parent->go_right() = new_root;
            }
            else{
                this->parent->go_left() = new_root;
            }
            new_root->which_child = which_child;
        }
        this->right = new_root->go_left();
        if(this->right){
            this->right->which_child = 1;
        }
        this->parent = new_root;    this->which_child = -1;
        new_root->left = this;

        /* set sum
            1. parent sum doesn't change; total # children same
            2. new root left_sum changes
            3. this right_sum changes
         */
        if (this->right) {
            this->right_sum = this->right->get_left_sum() +
                              this->right->get_right_sum() +
                              this->right->get_here_sum();
        }
        new_root->left_sum = this->get_here_sum() + this->get_right_sum() + this->get_left_sum();
    }

    void rotate_right(){
        node* new_root = this->left;
        if (this->parent) {
            if (which_child == 1) {
                this->parent->go_right() = new_root;
            }
            else{
                this->parent->go_left() = new_root;
            }
            new_root->which_child = which_child;
        }
        this->left = new_root->go_right();
        if(this->left){
            this->left->which_child = -1;
        }
        this->parent = new_root;    this->which_child = 1;
        new_root->right = this;

        /* set sum
            1. parent sum doesn't change; total # children same
            2. new root left_sum changes
            3. this right_sum changes
         */
        if (this->left) {
            this->left_sum = this->left->get_left_sum() +
                              this->left->get_right_sum() +
                              this->left->get_here_sum();
        }
        new_root->right_sum = this->get_here_sum() + this->get_right_sum() + this->get_left_sum();
    }
    bool balance(){
        int bal = this->get_balance();
        if (bal >= -1 && bal <= 1) {
            return true;
        }
        if (bal > 1) {
            /* need rotation */
            // check right sub child balance
            int child_bal = this->right->get_balance();
            if(child_bal == -1 || child_bal == 0){
                /* right rotate child */
                this->right->rotate_right();
            }
            this->rotate_left();
            return false;
        }
        else{
            // check left sub child balance
            int child_bal = this->left->get_balance();
            if (child_bal == 1 || child_bal == 0) {
                this->left->rotate_left();
            }
            this->rotate_right();
            return false;
        }
    }
};





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
    curr_node = curr_node->get_parent();
    while(curr_node && (curr_node->get_balance() <= 1 && curr_node->get_balance() >= -1)){
        curr_node = curr_node->get_parent();
    }
    if (curr_node) {
        curr_node->balance();
    }

    int height = 1;
    while(parent){
        height += 1;
        if (parent->height >= height) {
            /* stop */
            break;
        }
        parent->height = height;    parent = parent->get_parent();
    }
    return count;
}
