// 8 Queens Chess Problem
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int strict_x, strict_y;
// it's inputted position
void printer (int); // OK!
void rec(int, int); // ...?
bool check(int, int, int); // OK!
// int state
// x 1 2 3 4 5 6 7 8
// y  {1 to 8}
// if y_seq is 8,2,1,3,4,5,6,7
// then state is 82134567

int r;
void printer (int state) {
  int count = 7;
  printf ("%2d      ", r);
  for (int i = 0; i < 8; ++i) {
    printf ("%d", (state / (int)(pow(10,count))) % 10);
    count--;
    if (i != 7) {
      printf (" ");
    }
  }
  printf ("\n");
  r++;
}

bool check (int y, int state, int stage) {
  // state = 82000000
  //  then stage = 2
  // y = 3
  // : this means {x, y} = {3, 3}
  stage--;
  for (int i = 0; i < stage; ++i) {
    int y_ = ((state / (int) pow(10, 7 - i)) % 10);
    // y = y'
    if (y == y_) {
      return false;
    }
    // |x - x'| = |y - y'|
    if ((abs((stage + 1) - (i + 1)))
        == (abs(y - y_))) {
      return false;
    }
  }
  return true;
}

void rec (int state, int stage) {
  if (stage == 9) {
    printer (state);
    return;
  } else if (strict_x == stage) {
    if (check (strict_y, state, stage)) {
      rec (state
           + (strict_y * ((int) pow (10, 8 - stage))),
           stage + 1);
    } else return;
  } else {
    for (int y = 1; y < 9; ++y) {
      if (check (y, state, stage)) {
        rec (state + (y * ((int) pow (10, 8 - stage))), stage + 1);
      }
    }
  }
}

int main()
{
  int times;
  string dummy;
  scanf ("%d",&times);
  while (times--) {
    getline (cin, dummy);
    r = 1;
    scanf ("%d %d", &strict_y, &strict_x);
    printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
    rec (0, 1);
    if (times != 0) {
      printf ("\n");
    }}
  return 0;
}
