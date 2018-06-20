#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Position {
  int x, y;
  Position () {}
  Position (int x_, int y_) :x (x_), y (y_) {}
  bool operator<(const Position& a) const {
    return x > a.x;
  }
};

vector<Position> v;

int main()
{
  int times;
  scanf("%d",&times);
  while (times--) {
    v.clear ();
    int num, n;
    scanf("%d", &num);
    n = num;
    while (num--) {
      Position p;
      scanf("%d %d", &p.x, &p.y);
      v.push_back (p);
    }
    v.push_back (Position (0,0));
    sort (v.begin (), v.end ());
    int max_height = 0;
    double sum_len = 0.0;
    for (int i = 0; i < v.size (); ++i) {
      if (v [i].y > max_height) {
        sum_len +=
          sqrt (((double)
                 (((v [i].x - v [i-1].x) * (v [i].x - v [i-1].x))
                  + ((v [i].y - v [i-1].y) * (v [i].y - v [i-1].y)))))
          * ((double (v [i].y - max_height)) / (double (v [i].y - v [i - 1].y)));
        max_height = v [i].y;
      }
    }
    printf ("%.2lf\n", sum_len);
  }
  return 0;
}
