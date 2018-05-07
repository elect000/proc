#include <iostream>
#include <stdio.h>
using namespace std;

int jack_list [1000000];

int main()
{
  while (true) {
    int jack_num, jill_num;
    scanf("%d %d", &jack_num, &jill_num);
    if (jack_num == 0 && jill_num == 0)
      break;
    int count = 0;
    int s = jack_num;
    while (jack_num--) {
      int t;
      scanf("%d", &t);
      jack_list [count] = t;
      count++;
    }
    int sum = 0;
    int pos = 0;
    while (jill_num--) {
      int t;
      scanf("%d", &t);
      if (s < pos)
        break;
      while (s > pos) {
        if (jack_list [pos] == t) {
          ++sum;
          ++pos;
          break;
        } else if (jack_list [pos] > t) break;
         else ++pos;
      }
    }
    printf ("%d\n", sum);
  }
  return 0;
}
