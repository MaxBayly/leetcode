
#include "min_stack.h++"
#include "rpn.h++"
#include "valid_parentheses.h++"
#include "gtest/gtest.h"

TEST(ValidParens, One) {
    valid_parentheses soln;
    string input = "[]";
    EXPECT_TRUE(soln.isValid(input));
}

TEST(ValidParens, Two) {
    valid_parentheses soln;
    string input = "([{}])";
    EXPECT_TRUE(soln.isValid(input));
}

TEST(ValidParens, Three) {
    valid_parentheses soln;
    string input = "([(])";
    EXPECT_TRUE(!soln.isValid(input));
}

TEST(ValidParens, Four) {
    valid_parentheses soln;
    string input = "]";
    EXPECT_TRUE(!soln.isValid(input));
}

TEST(MinStackTest, One) {
    MinStack min_stack;
    min_stack.push(1);
    min_stack.push(2);
    min_stack.push(0);
    EXPECT_EQ(min_stack.getMin(), 0);
    min_stack.pop();
    EXPECT_EQ(min_stack.top(), 2);
    EXPECT_EQ(min_stack.getMin(), 1);
}

TEST(RPNTest, One) {
    RPN soln;
    vector<string> tokens = {"1", "2", "+", "3", "*", "4", "-"};
    EXPECT_EQ(soln.evalRPN(tokens), 5);
}