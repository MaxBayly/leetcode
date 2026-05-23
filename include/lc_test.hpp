#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

namespace lc_test {

namespace detail {

template <typename T, typename = void>
struct is_streamable : std::false_type {};

template <typename T>
struct is_streamable<
    T,
    std::void_t<decltype(std::declval<std::ostream&>() << std::declval<const T&>())>>
    : std::true_type {};

template <typename T>
struct is_vector : std::false_type {};

template <typename T, typename Allocator>
struct is_vector<std::vector<T, Allocator>> : std::true_type {};

template <typename T>
inline std::string to_string_value(const T& value) {
  if constexpr (is_vector<T>::value) {
    std::ostringstream oss;
    oss << '[';
    for (std::size_t i = 0; i < value.size(); ++i) {
      if (i > 0) {
        oss << ", ";
      }
      oss << to_string_value(value[i]);
    }
    oss << ']';
    return oss.str();
  } else if constexpr (is_streamable<T>::value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
  } else {
    return "<unprintable>";
  }
}

}  // namespace detail

inline int assertions = 0;
inline int failures = 0;

inline void expect_true(bool condition, const char* expression, const char* file, int line) {
  ++assertions;
  if (!condition) {
    ++failures;
    std::cerr << file << ':' << line << " EXPECT_TRUE failed: " << expression << '\n';
  }
}

template <typename A, typename B>
inline void expect_eq(const A& actual,
                      const B& expected,
                      const char* actual_expr,
                      const char* expected_expr,
                      const char* file,
                      int line) {
  ++assertions;
  if (!(actual == expected)) {
    ++failures;
    std::cerr << file << ':' << line << " EXPECT_EQ failed: " << actual_expr << " != " << expected_expr
              << '\n'
              << "  actual:   " << detail::to_string_value(actual) << '\n'
              << "  expected: " << detail::to_string_value(expected) << '\n';
  }
}

inline int summary() {
  if (failures == 0) {
    std::cout << "PASS (" << assertions << " assertions)" << '\n';
    return 0;
  }
  std::cerr << "FAIL (" << failures << " of " << assertions << " assertions failed)" << '\n';
  return 1;
}

}  // namespace lc_test

#define EXPECT_TRUE(condition) lc_test::expect_true((condition), #condition, __FILE__, __LINE__)
#define EXPECT_EQ(actual, expected) \
  lc_test::expect_eq((actual), (expected), #actual, #expected, __FILE__, __LINE__)
