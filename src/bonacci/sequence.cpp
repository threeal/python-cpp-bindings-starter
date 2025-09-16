#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

#include <algorithm>
#include <vector>

std::vector<int> fibonacci_sequence(int n) {
  std::vector<int> sequence(std::max(n, 0), 1);
  for (int i{2}; i < n; ++i) {
    sequence[i] = sequence[i - 2] + sequence[i - 1];
  }
  return sequence;
}

namespace nb = nanobind;

NB_MODULE(sequence, m) {
  m.doc() = "Example functions for generating Fibonacci sequences.";

  m.def(
      "fibonacci_sequence", &fibonacci_sequence,
      "Generate a Fibonacci sequence up to the given number of terms");
}
