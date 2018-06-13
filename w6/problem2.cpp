#include <stdio.h>
unsigned long long dt[25][151];
unsigned long long max[25];

unsigned long long gcd (unsigned long long x, unsigned long long y) {
  unsigned long long g = y % x;
  if (g) {
    return gcd (g, x);
  } else
    return x;
}

void dtset () {
  for (int i = 1; i < 25; ++i) {
    for (int j = i; j <= i * 6; ++j) {
      for (int k = 1; k <= 6 && j >= k; ++k) {
        dt [i] [j] += dt [i - 1] [j - k];
      }
    }
  }
}

int main()
{
  dt[0][0] = max[0] = 1;
  for (int i = 1; i < 25; ++i) {
    max [i] = max[i - 1] * 6;
  }
  dtset ();
  int m, n;
  while (scanf ("%d %d", &n, &m)) {
    if (n == 0 && m == 0) break;
    unsigned long long x = 0;
    unsigned long long y = max [n];
    for (int i = m; i < 151; ++i) {
      x += dt [n] [i];
    }
    if (x == 0) {
      printf ("0\n");
      continue;
    }
    unsigned long long g = gcd (x, y);
    x /= g;
    y /= g;
    if (y == 1) {
      printf("%llu\n", x);
    } else {
      printf("%llu/%llu\n", x, y);

    }
  }
  return 0;
}
