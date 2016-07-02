//
//  search_connected_cell.cpp
//  HackerRank
//
//  Created by Shihao Zhang on 6/30/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "search_connected_cell.hpp"
#include <unordered_map>
#include <queue>
#include <fstream>

int have_been_to = 0;
int total_cells = 0;
unordered_map<int, int> count_map;
queue<arguments> arg_queue;
int total_rows, total_columns;

void checkHere(vector<vector<bool>>& map, int x, int y, int group){
    map[x][y] = true;
    have_been_to ++;
    count_map[group]++;

    int left = x-1, upper = y-1;
    while (left < 0) {
        left++;
    }
    while (upper < 0) {
        upper++;
    }
    for (; left <= x+1 && left < total_rows; left++) {
        for (int j = upper; j <= y+1 && j < total_columns; j++ ) {
            if (!map[left][j]) {
                checkHere(map, left, j, group);
            }
        }
    }
}

//int main(){
//    cin >> total_rows >> total_columns;
//    int group = 1;
//    total_cells = total_columns * total_rows;
//    
//    vector<vector<bool>> map(total_rows, vector<bool>(total_columns, false));
//    vector<vector<int>> cell(total_rows, vector<int>(total_columns, 0));
//    for (int i = 0; i < total_rows; i++) {
//        for (int j = 0; j < total_columns; j++) {
//            cin >> cell[i][j];
//        }
//    }
//    
//    // starts at point 0,0
//    checkHere(map, cell, 0, 0, group);
//    int largest = 0;
//    auto it = count_map.begin();
//    while (it != count_map.end()) {
//        largest = max(it->second, largest);
//        it++;
//    }
//    cout << largest << "\n";
//    return 0;
//}

int main(){
    ifstream infile("/Users/DavidZhang/Desktop/Programming Practice/HackerRank/HackerRank/HackerRank/test.txt");
    if (!infile.is_open()) {
        return -1;
    }
    infile >> total_rows >> total_columns;
    int group = 1;
    total_cells = total_columns * total_rows;

    vector<vector<bool>> map(total_rows, vector<bool>(total_columns, false));
    vector<vector<int>> cell(total_rows, vector<int>(total_columns, 0));
    for (int i = 0; i < total_rows; i++) {
        for (int j = 0; j < total_columns; j++) {
            infile >> cell[i][j];
            if (cell[i][j] == 0) {
                map[i][j] = true;   have_been_to++;
            }
        }
    }

    // starts at point 0,0

    while (have_been_to < total_cells) {
        int x = 0, y = 0;
        for (int i = total_rows-1; i >= 0; i--) {
            for (int j = total_columns-1; j >= 0; j--) {
                if (!map[i][j]) {
                    x = i;  y = j;  break;
                }
            }
        }
        checkHere(map, x, y, group++);
    }

    int largest = 0;
    auto it = count_map.begin();
    while (it != count_map.end()) {
        largest = max(it->second, largest);
        it++;
    }
    cout << largest << "\n";
    return 0;
}