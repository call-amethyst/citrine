// fraction.h (Class Fraction)

#include <stdexcept>

class Fraction {
public:
  Fraction(int n, int d) { // constructor
    if (d < 1) {
      throw std::runtime_error("Denominator < 1 not allowed.");
    }
    _numerator = n;
    _denominator = d;
  }

  int numerator() const { // return numerator
    return _numerator;
  }

  int denominator() const { // return denominator
    return _denominator;
  }

  Fraction add(const Fraction &x) const { // returns the sum with x
    return Fraction(_numerator * x.denominator() + x.numerator() * _denominator,
                    _denominator * x.denominator());
  }

  Fraction add_safe(const Fraction &x) const {
    int a, b, c, sum;

    if (__builtin_mul_overflow(_numerator, x.denominator(), &a) ||
        __builtin_mul_overflow(x.numerator(), _denominator, &b) ||
        __builtin_mul_overflow(_denominator, x.denominator(), &c) ||
        __builtin_add_overflow(a, b, &sum)) {
      throw std::overflow_error("Integer overflow in Fraction::add_safe.");
    }

    return Fraction(sum, c);
  }

  void reciprocal() { // replaces a/b by b/a
    if (_numerator == 0) {
      throw std::runtime_error("Cannot invert the fraction 0.");
    }
    int tmp = _numerator;
    _numerator = _denominator;
    _denominator = tmp;
    if (_denominator < 0) { // keep the denominator positive
      _numerator = -_numerator;
      _denominator = -_denominator;
    }
  }

  // further operations may be added here

private:
  int _numerator;
  int _denominator;
};
