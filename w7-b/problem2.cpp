#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int gcd (int a, int b) {
  int t;
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  while (a) {
    t = a;
    a = b % a;
    b = t;
  }
  return b;
}

struct Point {
  int x, y, z;
  bool operator<(const Point &a) const {
    return (long long)x*x + (long long)y*y
      < (long long)a.x*a.x + (long long)a.y*a.y;
  }
};

bool comp (const Point &a, const Point &b) {
  if (a.x < b.x) return true;
  if (a.x > b.x) return false;
  if (a.y < b.y) return true;
  return false;
}

vector<Point> v;
map<pair<int, int>, int> m;
vector<Point> res;
Point pl [100001];

int main() {
  int len;
  int times = 0;
  while (scanf("%d", &len)) {
    if (len == 0) break;
    v.clear();
    m.clear();
    res.clear();
    for (int i = 0; i < len; ++i)
      scanf("%d %d %d", &pl [i].x, &pl [i].y, &pl [i].z);
    sort(pl, pl + len);
    for (int i = 0 ; i < len ; i++) {
      pair<int, int> pa;
      if (pl [i].x == 0) {
        if (pl [i].y < 0) pa = make_pair(0 , -1);
        else pa = make_pair(0 , 1);
      } else if (pl [i].y == 0) {
        if (pl [i].x < 0) pa = make_pair (-1, 0);
        else pa = make_pair (1, 0);
      } else {
        int g = gcd (pl [i].x, pl [i].y);
        pa = make_pair (pl [i].x/g, pl [i].y/g);
      }
      if (m.count(pa)) {
        if (pl [i].z <= m [pa]) {
          res.push_back(pl [i]);
        } else {
          m [pa] = pl [i].z;
        }
      } else {
        m [pa] = pl [i].z;
      }
    }
    printf ("Data set %d:\n", ++times);
    if (res.empty ())
      printf ("All the lights are visible.\n");
    else {
      printf ("Some lights are not visible:\n");
      sort (res.begin (), res.end (), comp);
      for (int i = 0 ; i < res.size (); ++i) {
        printf ("x = %d, y = %d", res [i].x, res [i].y);
        if (i != res.size () - 1) printf (";\n");
        else printf (".\n");
      }
    }
  }
  return 0;
}
