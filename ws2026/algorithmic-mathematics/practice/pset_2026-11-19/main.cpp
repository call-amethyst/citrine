#include "bigint.h"

int main() {
  const auto a_res = BigInt::parse("99999999999999999999");
  const auto b_res = BigInt::parse("123456789");

  if (!a_res || !b_res) {
    std::cerr << "Invalid BigInt\n";
    return 1;
  }

  const auto a = *a_res;
  const auto b = *b_res;

  const auto result = a + b;

  std::cout << result << '\n';

  if (const auto digit = result.get_digit(0)) {
    std::cout << "First digit: " << static_cast<u64>(*digit) << '\n';
  }

  return 0;
}
