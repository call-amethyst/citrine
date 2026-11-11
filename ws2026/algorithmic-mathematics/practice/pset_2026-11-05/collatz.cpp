#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;

  if (n < 1) {
    return 0;
  }

  for (; n != 1;) {
    cout << n << endl;

    if (n % 2 == 0) {
      n = n / 2;
    } else {
      n = 3 * n + 1;
    }
  }

  cout << n << endl;
  return 0;
}
