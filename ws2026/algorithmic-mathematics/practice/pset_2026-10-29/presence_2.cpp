#include <cstddef>
#include <iostream>
typedef std::size_t usize;
bool is_prime(usize);

int main(int argc, char *argv[]) {
  usize num;
  std::cin >> num;

  std::cout << num << (is_prime(num) ? " ist prim." : " ist nicht prim")
            << std::endl;
  return 0;
}

bool is_prime(usize num) {
  for (usize factor = 2; factor * factor <= num; factor++) {
    if (num % factor == 0) {
      return false;
    }
  }
  return true;
}
