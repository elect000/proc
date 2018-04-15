#include <iostream>
using namespace std;

int main()
{
  unsigned int N, B, H, W;
  unsigned int P, a, t;
  int res;
  while (cin >> N >> B >> H >> W) {
    res = 500001;
    while (H > 0) {
      a = 0;
      cin >> P;
      for (int i = 0; i < W; ++i) {
        cin >> t;
        if (t > a)
          a = t;
      }
      if (a >= N) {
        t = P * N;
        if (t <= B && t < res) {
          res = t;
        }
      }
      H--;
    }
    if (res != 500001) {
      cout << res << endl;
    } else {
      cout << "stay home" << endl;
    }
  }
  return 0;
}

