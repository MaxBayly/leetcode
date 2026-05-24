#include "encode_decode.hpp"

#include <gtest/gtest.h>

#include "longest_consecutive.h++"
#include "top_k.h++"
#include "valid_sudoku.h++"

TEST(EncodeDecodeTests, HelloWorld) {
    encode_decode soln;
    vector<string> input = {"Hello","World"};
    string encoded = soln.encode(input);
    vector<string> decoded = soln.decode(encoded);
    EXPECT_EQ(decoded, input);
}

TEST(LongestConsecutiveTest, TestOne) {
    longest_consecutive soln;
    vector input = {2,20,4,10,3,4,5};

    EXPECT_EQ(soln.longestConsecutive(input), 4);
}

TEST(LongestConsecutiveTest, TestTwo) {
    longest_consecutive soln;
    vector input = {0,3,2,5,4,6,1,1};
    EXPECT_EQ(soln.longestConsecutive(input), 7);
}

TEST(TopKTest, TestOne) {
    top_k solution;
    vector<int> input = {1,2,2,3,3,3};
    vector<int> expected = {3, 2};
    EXPECT_EQ(solution.topKFrequent(input,  2), expected);
}

TEST(TopKTest, TestTwo) {
    top_k solution;
    vector<int> input = {7,7};
    vector<int> expected = {7};
    EXPECT_EQ(solution.topKFrequent(input,  1), expected);
}

TEST(SudokuTest, TestOne) {
    valid_sudoku soln;
    vector<vector<char>> board = {{'1', '2', '.', '.', '3', '.', '.', '.', '.'},
                              {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
                              {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
                              {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
                              {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                              {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
                              {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    EXPECT_TRUE(soln.isValidSudoku(board));
}

TEST(SudokuTest, TestTwo) {
    valid_sudoku soln;
    vector<vector<char>> board = {
        { '1', '2', '.', '.', '3', '.', '.', '.', '.' },
        { '4', '.', '.', '5', '.', '.', '.', '.', '.' },
        { '.', '9', '1', '.', '.', '.', '.', '.', '3' },
        { '5', '.', '.', '.', '6', '.', '.', '.', '4' },
        { '.', '.', '.', '8', '.', '3', '.', '.', '5' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '.', '.', '.', '.', '.', '2', '.', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '8' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };

    EXPECT_TRUE(!soln.isValidSudoku(board));
}