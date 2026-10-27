#include <iostream>

bool is_prime(int);

int prime_twins = 0;

int main(void) {
  for (int lower = 3; lower < 1000000; lower = lower + 2) {
    // Denesting: Wie waere es mit if (!is_prime(lower)) continue;
    if (is_prime(lower)) {
      int upper = lower + 2;
      // Denesting: Wie waere es mit if (!is_prime(upper)) continue;
      if (is_prime(upper)) {
        std::cout << "(" << lower << "|" << upper << "),";
        prime_twins++;
      }
    }
  }
  std::cout << "\nEs gibt " << prime_twins << " Primzahlzwillinge <= pow(10, 6)"
            << std::endl;

  return 0;
}

bool is_prime(int num) {
  for (int factor = 2; factor * factor <= num; factor++) {
    if (num % factor == 0) {
      return false;
    }
  }
  return true;
}
