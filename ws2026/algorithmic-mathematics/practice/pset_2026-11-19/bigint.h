#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <expected>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "rust.h"

enum class BigIntError : u8 { EmptyInput, InvalidDigit };

class BigInt final {
private:
  std::vector<u8> digits;

  explicit BigInt(std::vector<u8> data) noexcept : digits(std::move(data)) {}

public:
  explicit BigInt(u64 value = 0) {
    do {
      digits.push_back(static_cast<u8>(value % 10));
      value /= 10;
    } while (value != 0);
  }

  [[nodiscard]]
  static auto parse(str input) -> Result<BigInt, BigIntError> {
    if (input.empty())
      return Err(BigIntError::EmptyInput);

    std::vector<u8> data;
    data.reserve(input.size());

    for (auto it = input.rbegin(); it != input.rend(); ++it) {

      const auto digit = static_cast<unsigned>(*it - '0');

      if (digit > 9)
        return Err(BigIntError::InvalidDigit);

      data.push_back(static_cast<u8>(digit));
    }

    while (data.size() > 1 && data.back() == 0)
      data.pop_back();

    return Ok(BigInt(std::move(data)));
  }

  [[nodiscard]]
  auto add(const BigInt &other) const -> BigInt {
    const auto *a = &digits;
    const auto *b = &other.digits;

    if (a->size() < b->size())
      std::swap(a, b);

    std::vector<u8> result;
    result.reserve(a->size() + 1);

    const usize n = a->size();
    const usize m = b->size();

    u64 carry = 0;
    usize i = 0;

    for (; i < m; ++i) {
      const u64 sum = (*a)[i] + (*b)[i] + carry;

      carry = sum >= 10;

      result.push_back(static_cast<u8>(sum - 10 * carry));
    }

    for (; i < n && carry; ++i) {
      const u64 sum = (*a)[i] + carry;

      carry = sum >= 10;

      result.push_back(static_cast<u8>(sum - 10 * carry));
    }

    result.insert(result.end(), a->begin() + i, a->end());

    if (carry)
      result.push_back(1);

    return BigInt(std::move(result));
  }

  [[nodiscard]]
  auto get_digit(usize index) const noexcept -> Option<u8> {
    if (index >= digits.size())
      return None;

    return Some(digits[index]);
  }

  [[nodiscard]]
  auto len() const noexcept -> bool {
    return digits.size();
  }

  [[nodiscard]]
  auto is_zero() const noexcept -> bool {
    return digits.size() == 1 && digits[0] == 0;
  }

  [[nodiscard]]
  auto to_string() const -> String {
    String result;
    result.resize(digits.size());

    std::transform(digits.rbegin(), digits.rend(), result.begin(),
                   [](u8 digit) { return static_cast<char>('0' + digit); });

    return result;
  }

  [[nodiscard]]
  auto operator+(const BigInt &other) const -> BigInt {
    return add(other);
  }

  friend std::ostream &operator<<(std::ostream &os, const BigInt &value) {
    return os << value.to_string();
  }
};
