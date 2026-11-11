#include <iostream>

int main() {
  int n;
  std::cin >> n;

  bool prime = (n >= 2);
  int i = 2;

  while (i <= n / 2 && prime) {
    if (n % i == 0) {
      prime = false;
    }
    i++;
  }

  if (prime) {
    std::cout << "prim" << std::endl;
  } else {
    std::cout << "nicht prim" << std::endl;
  }

  return 0;
}
