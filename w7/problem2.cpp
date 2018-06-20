#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
  int x, y;
  Point () {};
  Point (int x_, int y_)
    :x (x_), y (y_) {};
};

struct Line {
  int x1, y1, x2, y2;
  Line () {};
  Line (int x1_, int y1_, int x2_, int y2_)
    : x1(x1_), y1(y1_), x2(x2_), y2(y2_)
  {};
  Point fall (Point p) {
    if (p.x > (x1>x2?x2:x1) && p.x < (x1>x2?x1:x2)) {
      if ((float) p.y >=
               (((float) (y2 - y1) / (float) (x2 - x1)) *
                (float) (p.x  - x1)) + (float) y1) {
        return Point ((y1>y2?x2:x1), (y1>y2?y2:y1));
      }
    }
    return p;
  }
  bool operator<(const Line& l) const {
    return (y2>y1?y2:y1)>(l.y2>l.y1?l.y2:l.y1);
  }
};

vector<Line> ls;

int main()
{
  int times;
  scanf ("%d", &times);
  while (times--) {
    ls.clear ();
    int lt;
    scanf ("%d", &lt);
    while (lt--) {
      Line l;
      scanf ("%d %d %d %d", &l.x1, &l.y1, &l.x2, &l.y2);
      ls.push_back (l);
    }
    sort (ls.begin (), ls.end ());
    int pt;
    Point p;
    scanf ("%d", &pt);
    while (pt--) {
      scanf ("%d %d", &p.x, &p.y);
      for (Line l: ls) {
        p = l.fall (p);
      }
      printf ("%d\n", p.x);
    }
    if(times != 0) {
      printf ("\n");
    }
  }
  return 0;
}
