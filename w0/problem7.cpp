#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

static int five_hour = 5 * 60 * 60;
vector<int> v;
vector<int> n;
int max;
int i, j, times, kil;
bool t;

void reader ();
void check (int);

int main()
{
  kil = 0;
  while (kil < 3) {
    reader ();
    if (v.size ()) {
      sort (v.begin (), v.end ());
      for (times = (v [0]) * 2;
           times <= five_hour;
           ++times) {
        t = true;
        for (i = 0; i < v.size (); ++i) {
          check (i);
          if (!t) break;
        }
        if (t)
          break;
      }
      if (times <= five_hour) {
        int c = times % 60;
        int b = (times - c) / 60;
        int a = b / 60;
        b -= a * 60;
        cout  << setw (2) << setfill ('0') << right << a << ":"
              << setw (2) << setfill ('0') << right << b << ":"
              << setw (2) << setfill ('0') << right << c << endl;
      } else {
        cout << "Signals fail to synchronise in 5 hours\n";
      }
      n.clear ();
      v.clear ();
    }
  }
  return 0;
}

void reader ()
{
  while (1) {
    cin >> i;
    if (i) {
      kil = -1;
      v.push_back (i);
      n.push_back (0);
    } else {
      kil++;
      break;
    }
  }
}

void check (int l) {
  int s = n [l];
  for (; (2 * n [l] * v [l] <= times); n [l] += 1) {}
  n [l] -= 1;
  if  (times >= (2 * n [l] * v [l] - 5 + v [l])) {
      t = false;
  }
}
