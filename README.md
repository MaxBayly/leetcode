# neet

Simple C++23 LeetCode workspace organized by domain with lightweight tests.

## Layout

```
include/
  lc_test.hpp                  # tiny assertion helpers
problems/
  arrays_and_hashing/
    two_sum/
      solution.hpp
      test.cpp
  binary_search/
    binary_search/
      solution.hpp
      test.cpp
scripts/
  new_problem.py               # scaffold a new problem folder
```

## Commands

- `make list` - list all available problem paths
- `make test PROBLEM=arrays_and_hashing/two_sum` - build and run one problem's tests
- `make test-all` - build and run every `test.cpp`
- `make clean` - delete build artifacts

## Add a new problem

```
python3 scripts/new_problem.py arrays_and_hashing contains_duplicate
```

Then run:

```
make test PROBLEM=arrays_and_hashing/contains_duplicate
```

## Notes on editor workflow (Zed or others)

- Keep tests next to each solution as `test.cpp`.
- Run current problem tests with:
  - `make test PROBLEM=<domain>/<problem_slug>`
- Or compile a single file directly with:
  - `clang++ -std=c++23 -Iinclude problems/<domain>/<problem_slug>/test.cpp -o build/tmp && ./build/tmp`
# leetcode
