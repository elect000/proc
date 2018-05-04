// Grid Successors
#include <stdio.h>
using namespace std;

int g[5][5];
int f[5][5];

void init ();
void func ();
bool isnotfinite ();

void init ()
{
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      g [i] [j] = 0;
      f [i] [j] = 0;
    }
  }
}
void func ()
{
  // calculate
  for (int i = 1; i < 4; ++i) {
    for (int j = 1; j < 4; ++j) {
      f [i] [j] =
        (g [i] [j + 1]
         + g [i + 1] [j]
         + g [i - 1] [j]
         + g [i] [j - 1]) ;
    }
  }
  // update
  for (int i = 1; i < 4; ++i) {
    for (int j = 1; j < 4; ++j) {
      g [i] [j] = (f [i] [j] % 2);
    }
  }
}
bool isnotfinite ()
{
  // calculate
  for (int i = 1; i < 4; ++i) {
    for (int j = 1; j < 4; ++j) {
      if (g [i] [j] > 0) return true;
    }
  }
  return false;
}

int main()
{
  init ();
  int times;
  scanf ("%d", &times);

  while (times--) {
    // input data
    for (int i = 1; i <= 3; ++i) {
      for (int j = 1; j <= 3; ++j) {
        scanf ("%1d", &g [i] [j]);
      }
    }
    int res = -1;
    while (isnotfinite ()) {
      func ();
      ++res;
    }
    printf ("%d\n", res);
  }
  return 0;
}
