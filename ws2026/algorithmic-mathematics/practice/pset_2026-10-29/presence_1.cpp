#include <cstddef>
#include <iostream>

typedef std::size_t usize;

int main(int argc, char *argv[]) {
  usize n;
  std::cin >> n;

  usize total{};
  for (usize i = 1; i <= n; i++) {
    total += i * i;
  }

  std::cout << total;
  return 0;
}
