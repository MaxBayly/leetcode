
#include "car_fleet.h++"
#include "daily_temp.h++"
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

TEST(DailyTempTest, One) {
    daily_temp soln;
    vector temps = {30,38,30,36,35,40,28};
    vector expected = {1,4,1,2,1,0,0};
    EXPECT_EQ(soln.dailyTemperatures(temps), expected);
}

TEST(DailyTempTest, Dynamic) {
    daily_temp soln;
    vector temps = {30,38,30,36,35,40,28};
    vector expected = {1,4,1,2,1,0,0};
    EXPECT_EQ(soln.dailyTempDynamic(temps), expected);
}

TEST(FleetTest, One) {
    car_fleet soln;
    vector position = {1, 4};
    vector speed = {3, 2};
    int target = 10;
    int expected = 1;
    EXPECT_EQ(soln.carFleet(target, position, speed), expected);
}

TEST(FleetTest, Two) {
    car_fleet soln;
    vector position = {4,1,0,7};
    vector speed = {2, 2, 1, 1};
    int target = 10;
    int expected = 3;
    EXPECT_EQ(soln.carFleet(target, position, speed), expected);
}