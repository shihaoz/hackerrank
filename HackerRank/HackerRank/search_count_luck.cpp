//
//  search_count_luck.cpp
//  HackerRank
//
//  Created by Shihao Zhang on 7/1/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "search_count_luck.hpp"
#include <fstream>

int Step::max_row, Step::max_column;

vector<Step*> Step::getSurrounds(){
    vector<Step*> ret;
    vector<pair<int, int>> options;
    options.push_back(make_pair(x-1, y));   // left
    options.push_back(make_pair(x+1, y));   // right
    options.push_back(make_pair(x, y+1));   // up
    options.push_back(make_pair(x, y-1));   // down
    for (auto p : options) {
        if (p.first >= 0 && p.first < max_row
            && p.second >= 0 && p.second < max_column
            && grid_been_to[p.first][p.second] == false) {
            ret.push_back(new Step(p.first, p.second, 0));
        }
        else{
            // don't create
        }
    }
    return ret;
}


// use stack instead of recursive call
stack<Step*> stack_crosses;

int main(){

    int num;    cin >> num;
    while (num--) {
        int row, column, startX, startY, endX, endY;    cin >> row >> column;
        Step::max_row = row;    Step::max_column = column;
        grid_been_to = vector<vector<bool>>(row, vector<bool>(column, false));
        char holder;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cin >> holder;
                if (holder == 'X') {
                    grid_been_to[i][j] = true;
                }
                else if(holder == 'M'){
                    startX = i; startY = j;
                }
                else if(holder == '*'){
                    endX = i;   endY = j;
                }
            }
        }
        int ron;    cin >> ron;
        Step *here = new Step(startX, startY, 0);
        grid_been_to[startX][startY] = true;
        while (true) {
            
            // 0. check if == destination
            if (here->x == endX && here->y == endY) {
                cout << ((here->wave == ron)? "Impressed\n" : "Oops\n");
                delete here;
                break;
            }
            // 1. get surroundings
            vector<Step*> options = here->getSurrounds();
            // 2. get # options
            int numOpts = options.size();
            int wave = here->wave;
            delete here;
            // 3.1 #opt == 0, pop from stack
            if (numOpts == 0) {
                here = stack_crosses.top(); stack_crosses.pop();
            }
            // 3.2 #opt == 1, keep moving
            else if (numOpts == 1) {
                here = options[0];
                here->wave = wave;
                grid_been_to[here->x][here->y] = true;
            }
            // 3.3 #opt > 1, get one option, stores the rest to stack with current wave
            else{
                for (auto i : options) {
                    i->wave = wave+1;
                    grid_been_to[i->x][i->y] = true;
                }
                here = options[0];
                for (int i = 1; i < options.size(); i++) {
                    stack_crosses.push(options[i]);
                }
            }
        }
    }
    return 0;
}


int main(){
    ifstream infile("/Users/DavidZhang/Desktop/Programming Practice/HackerRank/HackerRank/HackerRank/test.txt");
    int num;    infile >> num;
    while (num--) {
        int row, column, startX, startY, endX, endY;    infile >> row >> column;
        Step::max_row = row;    Step::max_column = column;
        grid_been_to = vector<vector<bool>>(row, vector<bool>(column, false));
        char holder;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                infile >> holder;
                if (holder == 'X') {
                    grid_been_to[i][j] = true;
                }
                else if(holder == 'M'){
                    startX = i; startY = j;
                }
                else if(holder == '*'){
                    endX = i;   endY = j;
                }
            }
        }
        int ron;    infile >> ron;
        Step *here = new Step(startX, startY, 0);
        grid_been_to[startX][startY] = true;
        while (true) {
            
            // 0. check if == destination
            if (here->x == endX && here->y == endY) {
                cout << ((here->wave == ron)? "Impressed\n" : "Oops\n");
                delete here;
                break;
            }
            // 1. get surroundings
            vector<Step*> options = here->getSurrounds();
            // 2. get # options
            int numOpts = options.size();
            int wave = here->wave;
            delete here;
            // 3.1 #opt == 0, pop from stack
            if (numOpts == 0) {
                here = stack_crosses.top(); stack_crosses.pop();
            }
            // 3.2 #opt == 1, keep moving
            else if (numOpts == 1) {
                here = options[0];
                here->wave = wave;
                grid_been_to[here->x][here->y] = true;
            }
            // 3.3 #opt > 1, get one option, stores the rest to stack with current wave
            else{
                for (auto i : options) {
                    i->wave = wave+1;
                    grid_been_to[i->x][i->y] = true;
                }
                here = options[0];
                for (int i = 1; i < options.size(); i++) {
                    stack_crosses.push(options[i]);
                }
            }
        }
    }
    return 0;
}