// How Many Trees?
#include <stdio.h>
#include <iostream>
using namespace std;

unsigned long long tree [1001];
void create_tree () {
  unsigned long long sum = 0;
  tree[0] = tree[1] = 1;
  for (int i = 2; i < 1001; ++i) {
    sum = 0;
    for (int j = 0; j < i; ++j) {
      // (i - 1) - j + j = i - 1
      sum += tree[j] * tree[(i - 1) - j];
    }
    tree[i] = sum;
  }
}

int main()
{
  create_tree ();
  int c;
  while (cin >> c) {
    printf ("%d\n", tree [c]);
  }
  return 0;
}
