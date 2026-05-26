cmake_minimum_required(VERSION 4.2)
project(leetcode)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
)
FetchContent_MakeAvailable(googletest)

find_package(fmt CONFIG REQUIRED)

add_executable(leetcode main.cpp
        problems/arrays_and_hashing/encode_decode.hpp
        problems/arrays_and_hashing/arrays_hashing_test.cpp
        problems/arrays_and_hashing/longest_consecutive.h++
        problems/arrays_and_hashing/product_except_self.h++
        problems/arrays_and_hashing/top_k.h++
        problems/arrays_and_hashing/valid_sudoku.h++
        problems/sliding_window/sliding_window_test.cpp
        problems/sliding_window/buy_sell.h++
        problems/sliding_window/longest_substring.h++
        problems/sliding_window/min_window.h++
        problems/sliding_window/permutation.h++
        problems/sliding_window/replacement.h++
        problems/sliding_window/max_window.h++
        problems/two_pointers/container.h++
        problems/two_pointers/two_pointers_test.cpp
        problems/two_pointers/three_sum.h++
        problems/two_pointers/trapping_water.h++
        problems/two_pointers/two_sum_ii.h++
        problems/two_pointers/valid_palindrome.h++
        problems/stack/valid_parentheses.h++
        problems/stack/min_stack.h++
        problems/stack/rpn.h++
        problems/stack/stack_test.cpp
)
target_link_libraries(leetcode gtest_main fmt::fmt)

include(GoogleTest)
enable_testing()
gtest_discover_tests(leetcode)

