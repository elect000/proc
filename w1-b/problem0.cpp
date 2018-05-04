
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v, w;
int points[2000][2];

void read_base_triangle () {
  int a1, a2, b1, b2, c1, c2;
  cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
  v.push_back (pow((a1 - b1), 2) + pow ((a2 - b2), 2));
  v.push_back (pow((b1 - c1), 2) + pow ((b2 - c2), 2));
  v.push_back (pow((c1 - a1), 2) + pow ((c2 - a2), 2));
  sort (v.begin (), v.end ());
}

bool check () {
  bool c = true;
  for (int i = 0; i < 2; ++i) {
    if (v [i] != w [i]) c = false;
  }
  return c;
}

void ssort (int a1, int a2, int b1, int b2, int c1, int c2) {
  if (a1 < b1) {
    if (b1 < c1) {
      cout << a1 << " " << a2 << "\n"
           << b1 << " " << b2 << "\n"
           << c1 << " " << c2 << "\n";
    } else {
      ssort (a1, a2, c1, c2, b1, b2);
    }
  }
  else {
    ssort (b1, b2, a1, a2, c1, c2);
  }
}

int main()
{
  read_base_triangle();
  int a1, a2, b1, b2, c1, c2;
  int j, k;
  int p;
  cin >> p;
  for (int i = 0; i < p ; ++i) {
    cin >> a1 >> a2;
    points [i] [0] = a1;
    points [i] [1] = a2;
    if (i < 2) {
      continue;
    }
    for (j = i - 1; j > 0; --j) {
      b1 = points [j] [0];
      b2 = points [j] [1];
      for (k = i - 2; k > -1; --k) {
        c1 = points [k] [0];
        c2 = points [k] [1];
        w.push_back (pow((a1 - b1), 2) + pow ((a2 - b2), 2));
        w.push_back (pow((b1 - c1), 2) + pow ((b2 - c2), 2));
        w.push_back (pow((c1 - a1), 2) + pow ((c2 - a2), 2));

        sort (w.begin (), w.end ());
        if (check ()) {
          // all true
          ssort (a1, a2, b1, b2, c1, c2);
          goto stop;
        }
        w.clear();
      }
    }
  }
 stop:
  return 0;
}
