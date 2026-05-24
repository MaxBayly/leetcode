

#ifndef LEETCODEC_VALID_SUDOKU_H
#define LEETCODEC_VALID_SUDOKU_H

#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <fmt/ranges.h>


using namespace std;

class valid_sudoku {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<set<char>> rows(9), cols(9);
        vector<vector<set<char>>> sqrs(3, vector<set<char>>(3));
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char element = board[row][col];
                if (element == '.') {
                    continue;
                }
                if (!rows[row].insert(element).second) {
                    cout << "found duplicate in row " << row << endl;
                    fmt::println("{}", rows);
                    return false;
                }
                if (!cols[col].insert(element).second) {
                    cout << "found duplicate in column " << col << endl;
                    fmt::println("{}", cols);
                    return false;
                }
                if (!sqrs[row/3][col/3].insert(element).second) {
                    cout << "found duplicate in square " << row/3 << "," << col/3 << endl;
                    fmt::println("{}", sqrs);
                    return false;
                }
            }
        }
        return true;
    }
};


#endif //LEETCODEC_VALID_SUDOKU_H
