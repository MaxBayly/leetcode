#!/usr/bin/env python3

from pathlib import Path
import re
import sys


def normalize_slug(text: str) -> str:
    text = text.strip().lower().replace(" ", "_").replace("-", "_")
    text = re.sub(r"[^a-z0-9_]", "", text)
    text = re.sub(r"_+", "_", text)
    return text.strip("_")


def main() -> int:
    if len(sys.argv) != 3:
        print("Usage: python3 scripts/new_problem.py <domain> <problem_slug>")
        return 1

    domain = normalize_slug(sys.argv[1])
    problem = normalize_slug(sys.argv[2])

    if not domain or not problem:
        print("Domain and problem slug must contain letters or numbers.")
        return 1

    root = Path(__file__).resolve().parent.parent
    problem_dir = root / "problems" / domain / problem
    solution_path = problem_dir / "solution.hpp"
    test_path = problem_dir / "test.cpp"

    if problem_dir.exists():
        print(f"Already exists: {problem_dir}")
        return 1

    problem_dir.mkdir(parents=True, exist_ok=False)

    solution_path.write_text(
        """#pragma once

class Solution {
 public:
  // Implement your solution method here.
};
""",
        encoding="utf-8",
    )

    test_path.write_text(
        """#include \"solution.hpp\"
#include \"../../../include/lc_test.hpp\"

void test_placeholder() {
  EXPECT_TRUE(true);
}

int main() {
  test_placeholder();
  return lc_test::summary();
}
""",
        encoding="utf-8",
    )

    rel = problem_dir.relative_to(root)
    print(f"Created: {rel}")
    print(f"Run: make test PROBLEM={domain}/{problem}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
