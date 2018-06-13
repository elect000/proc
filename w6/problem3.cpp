#include <stdio.h>
using namespace std;

unsigned int a[673366];
// f(2000000000) = 673365
int main()
{
  a[1] = 1;
  for (int i = 1; i < 673366 - 1; ++i) {
    a[i + 1] = 1 + a[i + 1 - a[a[i]]];
  }
  unsigned int t;
  unsigned int place;
  int i;
  while (scanf("%d", &t)) {
    if (t == 0) break;
    place = 0;
    i = 0;
    while (place < t) {
      place += a[++i];
    }
    printf("%d\n", i);
  }
  return 0;
}

// a(n + 1) = 1 + a(n + 1 - a(a(n)))
// a(2) = 1 + a(2 - a(a(1)))
//    a(1) = 1
//    a(a(1)) = 1
//    1 + a(2 - a(a(1)))
//    1 + a(1)
//    1 + 1
// a(2) = 2
