#include <stdio.h>
#include <cmath>
using namespace std;

struct Position {
  int x, y;
  double distance_p(const Position &a) {
    double x_ = (double) (x - a.x);
    double y_ = (double) (y - a.y);
    return (x_*x_ + y_*y_);
  }
};

Position poss[101];

int main()
{
  int times;
  while (scanf("%d", &times)) {
    if (times == 0) break;
    for (int i = 0; i < times; ++i) {
      scanf ("%d %d", &poss[i].x, &poss[i].y);
    }
    double max_v_len = 0.0;
    int max_v_pos_1;
    int max_v_pos_2;
    for (int i = 0; i < times - 1; ++i) {
      for (int j = i; j < times; ++j) {
        if (max_v_len < poss [i].distance_p (poss [j])) {
          printf ("new %lf %lf\n", poss [i].distance_p (poss [j]), sqrt(poss [i].distance_p (poss [j])));
          max_v_len = poss [i].distance_p (poss [j]);
          max_v_pos_1 = i;
          max_v_pos_2 = j;
        }
      }
    }
    bool t = true;
    double max_r;
    scanf ("%lf", &max_r);
    double d_a, d_b, d_c, r;

    if (times == 2) {
      if (sqrt (max_v_len) < 2 * max_r)
        printf ("The polygon can be packed in the circle.\n");
      else
        printf ("There is no way of packing that polygon.\n");
      continue;
    }
    for (int i = 0; i < times; ++i) {
      if (max_v_pos_1 == i || max_v_pos_2 == i) continue;
      d_a = max_v_len;
      d_b = poss [max_v_pos_1].distance_p (poss [i]);
      d_c = poss [max_v_pos_2].distance_p (poss [i]);
      r = sqrt (d_a) / (2 * sqrt(1.0 - ((d_b + d_c - d_a) /
                                        2 * (sqrt (d_b)) * (sqrt (d_c)))));
      if (r > max_r) {
        t = false;
        break;
      }
    }
    if (!t) {
      printf ("There is no way of packing that polygon.\n");
      continue;
    }
    
  }
  return 0;
}
