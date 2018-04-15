#include <iostream>
using namespace std;

unsigned int* check (unsigned int*, unsigned int*);
unsigned int loop (unsigned int, unsigned int);
unsigned int c;
int main() {
  unsigned int first, second;
  while (1) {
    cin >> first >> second;
    if (cin.eof ()) break;
    cout << first << " " << second << " ";
    if (first < second) {
      first = *(check (&first, &second));
    } else {
      first = *(check (&second, &first));
    }
    cout << first << endl;
  }
  return 0;
}
unsigned int* check (unsigned int* a, unsigned int* b) {
  c = 0;
  unsigned int t;
  for (; *a <= *b; ++(*a)) {
    if ((t = loop (*a, 1)) > c)
      c = t;
  }
  return &c;
}
unsigned int loop (unsigned int n, unsigned int c) {
  if (n == 1) {
    return c;
  } else if (n % 2 == 1) {
    return loop (3 * n + 1, c + 1);
  } else {
    return loop (n / 2, c + 1);
  }
}
