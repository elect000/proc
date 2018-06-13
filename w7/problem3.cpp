#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

struct Position {
  int x, y;
  double distance_p(const Position &a) {
    double x_ = (double) (x - a.x);
    double y_ = (double) (y - a.y);
    return (x_*x_ + y_*y_);
  }
  double distance_d (const double &p, const double &q) {
    double x_ = (double) x - p;
    double y_ = (double) y - q;
    return (x_ * x_ + y_ * y_);
  }
};


Position poss[101];

int main()
{
  bool exit = false;
  bool eexit = false;
  int times;
  while (scanf("%d", &times)) {
    if (times == 0) break;
    for (int i = 0; i < times; ++i) {
      scanf ("%d %d", &poss[i].x, &poss[i].y);
    }
    double max_r;
    scanf ("%lf", &max_r);
    if (times == 1) {
      printf ("The polygon can be packed in the circle.\n");
      continue;
    }
    if (times == 2) {
      if (sqrt (poss [0].distance_p (poss [1])) < 2 * max_r)
        printf ("The polygon can be packed in the circle.\n");
      else
        printf ("There is no way of packing that polygon.\n");
      continue;
    }
    bool c_ = false;
    exit = false;
    eexit = false;
    double r = 100000000000000.0;
    double p, q, A, B, C, S, a, b, c;
    for (int i = 0; i < times - 2; ++i) {
      if (exit || eexit) break;
      for (int j = i + 1; j < times - 1; ++j) {
        if (exit || eexit) break;
        for (int k = j + 1; k < times ; ++k) {
          if (exit || eexit) break;
          c = false;
          A = poss [j].distance_p (poss [k]);
          B = poss [k].distance_p (poss [i]);
          C = poss [i].distance_p (poss [j]);
          a = sqrt (A);
          b = sqrt (B);
          c = sqrt (C);
          // cout << a << " " << " " << b << " " << c << endl;
          if (a > 2 * max_r || b > 2 * max_r || c > 2 * max_r) {
            eexit = true;
            break;
          }
          if (A + B < C) {
            if (r > c) {
              p = (double) (poss [i].x + poss [j].x) / 2.0;
              q = (double) (poss [i].y + poss [j].y) / 2.0;
              c_ = true;
            }
          } else if (B + C < A) {
            if (r > a) {
              p = (double) (poss [j].x + poss [k].x) / 2.0;
              q = (double) (poss [j].y + poss [k].y) / 2.0;
              c_ = true;
            }
          } else if (C + A < B) {
            if (r > b) {
              p = (double) (poss [k].x + poss [i].x) / 2.0;
              q = (double) (poss [k].y + poss [i].y) / 2.0;
              c_ = true;
            }
          } else {
            S = 0.5 *
              (abs ((poss [i].x - poss [k].x) * (poss [j].y - poss [k].y)
                    - (poss [j].x - poss [k].x) * (poss [i].y - poss [k].y)));
            p =
              (A * (B + C - A)* poss [i].x
               + B * (C + A - B) * poss [j].x
               + C * (A + B - C) * poss [k].x)
              / (16 * S * S);
            q =
              (A * (B + C - A)* poss [i].y
               + B * (C + A - B) * poss [j].y
               + C * (A + B - C) * poss [k].y)
              / (16 * S * S);
            if (r > sqrt (poss [i].distance_d (p, q))) {
              r = sqrt (poss [i].distance_d (p, q));
              c_ = true;
            }
          }
          if (c_) {
            exit = true;
            for (int h = 0; h < times; ++h) {
              if (sqrt(poss [h].distance_d (p, q)) > max_r) {
                exit = false;
                break;
              }
            }
          }}
      }
    }
    if (exit) {
      printf ("The polygon can be packed in the circle.\n");
    } else {
      printf ("There is no way of packing that polygon.\n");
    }
  }
  return 0;
}
