#include <cstddef>
#include <iostream>
#include <vector>

typedef std::size_t usize;

void print_filter_vec(std::vector<bool> &);
void print_index_vec_biggest(std::vector<usize>, usize num);

std::vector<usize> count_gaps(std::vector<bool> &vec);

std::vector<bool> sieve(usize);

template <typename T> void inc_index(std::vector<T> &, usize);

int main(int argc, char *argv[]) {
  std::cout << "Enter limit: ";
  usize limit;
  std::cin >> limit;

  std::vector<bool> primes = sieve(limit);

  // print_filter_vec(primes);

  std::vector<usize> anzahl = count_gaps(primes);

  print_index_vec_biggest(anzahl, 3);
  return 0;
}

std::vector<usize> count_gaps(std::vector<bool> &vec) {
  std::vector<usize> gaps{};
  usize last = 2;
  for (usize i = 2; i < vec.size(); i++) {
    if (!vec[i])
      continue; // If not prime continue
    usize gap = i - last;
    inc_index(gaps, gap);
    last = i;
  }

  return gaps;
}

auto sieve(usize limit) -> std::vector<bool> {
  std::vector<bool> primes(limit, true); // Assume all numbers are prime
  primes[0] = false;                     // 0 is not prime
  primes[1] = false;                     // 1 is not prime
  for (usize i = 2; i < limit; i++) {
    if (!primes[i])
      continue; // If not prime, go next
    for (usize j = 2 * i; j < limit; j += i) {
      primes[j] = false; // Set all multiplies of i to false
    }
  }

  return primes;
}

void print_filter_vec(std::vector<bool> &vec) {
  std::cout << "{";
  for (usize i = 0; i < vec.size(); i++) {
    if (vec[i]) {
      std::cout << i << ", ";
    }
  }
  std::cout << "}" << std::endl;
}

void print_index_vec_biggest(std::vector<usize> vec, usize num) {
  num = num < vec.size() ? num : vec.size(); // == max(vec.size(), num)
  for (usize i = 0; i < num; i++) {
    usize max{};
    usize max_index{};
    for (usize j = 0; j < vec.size(); j++) {
      if (vec[j] > max) {
        max = vec[j];
        max_index = j;
      }
    }
    std::cout << "Am " << i + 1 << ". haeufigsten ist " << max_index << " mit "
              << max << " Luecken\n";
    vec[max_index] = 0;
  }
}

template <typename T> void inc_index(std::vector<T> &vec, usize index) {
  if (vec.size() <= index) {
    vec.resize(index + 1, T{});
  }
  vec[index]++;
}
