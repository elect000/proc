#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> v;
int times;

void check ();

// v <- 1 3 2 -2
void check () {
  set<int> s;
  int t;
  for (int i = 0; i < times - 1; ++i) {
    t = abs(v[i] - v[i + 1]);
    if (t < 1 || times <= t) {
      cout << "Not jolly" << endl;
      return;
    } else if (s.count (t)) {
      cout << "Not jolly" << endl;
      return;
    } else {
      s.insert (t);
    }
  }
  cout << "Jolly" << endl;
  return;
}

int main()
{
  while (cin >> times) { // times <- 4
    int t;
    int s = times;
    // read
    while (s--){
      cin >> t;
      v.push_back(t);
    }
    check();
    v.clear();
  }
  return 0;
}
