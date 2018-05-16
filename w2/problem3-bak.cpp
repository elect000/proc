// 8 Queens Chess Problem
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int r;
int pos[8];
int x_s, y_s;
// 11 88
// xy xy
void rec (int);
void printer ();
bool check (int, int);

void printer () {
  cout << " " << r << "      ";
  for (int i = 0; i < 8; ++i) {
    cout << pos [i] % 10 + 1;
    if (i != 7) {
      cout << " ";
    }
  }
  cout << endl;
  r++;
}

bool check (int y, int state) {
  for (int i = 0; i < state; ++i) { // y = pos[i] % 10
    if ((pos [i] % 10 == y) ||
        ((abs (pos [i] % 10 - y))
         == (abs ((pos [i] / 10) - state))))
      return false;
  }
  return true;
}

void rec (int state) {
  if (state == 8) {
    printer ();
    return;
  } else if (strict == x) {
    
  }
  else {
    for (int y = 0; y < 8; ++y) {
      // [0 0] [0 1] ... // [0 2 4]
      if (check (y, state)) {
        pos [state] = state * 10 + y;
        rec (1 + state, strict);
      }
    }
  }
}

int main()
{
  int times;
  string dummy;
  scanf("%d", &times);
  while (times--) {
    getline (cin, dummy);
    r = 1;
    int x, y;
    scanf("%d %d", &x, &y);
    --x; --y;
    pos[x] = x * 10 + y;
    x_s = s;
    y_s = s;
    cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
    rec (0, x, y);
    if (times != 0) {
      cout << "\n";
    }
  }
  return 0;
}


