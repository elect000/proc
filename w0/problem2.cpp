#include <iostream>
using namespace std;

unsigned int* check (unsigned int*, unsigned int*, unsigned int*);

int main()
{
  unsigned int n, first, second, third;
  cin >> n;
  for (unsigned i = 0; i < n; ++i) {
    cin >> first >> second >> third;
    cout << "Case " << (i + 1) << ": " << *(check (&first, &second, &third)) << endl;
  }
  return 0;
}
unsigned int* check (unsigned int* a, unsigned int* b, unsigned int* c) {
  if (*a > *b) {
    if (*a > *c) {
      if (*b > *c) {
        return b;
      } else {
        return c;
      }
    } else {
      return a;
    }
  } else {
    if (*b > *c) {
      if (*a > *c) {
        return a;
      } else {
        return c;
      }
    } else {
      return b;
    }
  }
}
