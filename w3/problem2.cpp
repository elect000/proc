// Jill rides again
#include <iostream>
#include <stdio.h>
using namespace std;
int S[20001];

int main()
{
  int times;
  scanf("%d", &times);
  int T = times;
  while (times--) {
    int s;
    scanf("%d", &s);
    S[0] = 0;
    int start = -1, sum = 0, max = 0, max_start = 0, max_end = 0;
    for (int i = 0; i < s - 1; ++i) {
      int t;
      scanf("%d", &t);
      S[i] = t;
    }
    for (int i = 0; i < s - 1; ++i) {
      sum += S[i];
      if (sum < 0) {
        start = i;
        sum = 0;
      } else if ((sum > max) || ((sum == max) && ((max_end - max_start) < (i - start)))) {
        max = sum;
        max_end = i;
        max_start = start;
      }
    }
    if (max > 0) {
      printf ("The nicest part of route %d is between stops %d and %d\n", T - times, max_start + 2, max_end + 2);
    } else {
      printf ("Route %d has no nice parts\n", T - times);
    }
  }
  return 0;
}
