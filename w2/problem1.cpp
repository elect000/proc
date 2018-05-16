// The Dragon of Loowater
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> heads;
vector<int> knights;
void check(int, int);
void check(int nh, int nk) {
  if (nh > nk) {
    cout << "Loowater is doomed!" << endl;
  } else {
    int sum = 0, i = 0, j = 0;
    while (true) {
      if (i >= nh) {
        cout << sum << endl;
        break;
      }
      if (j >= nk) {
        cout << "Loowater is doomed!" << endl;
        return;
      }
      if (heads [i] <= knights [j]) {
        sum += knights [j];
        i++;
        j++;
      } else {
        j++;
        continue;
      }
    }
    return;
  }

}
int main()
{
  int n_head;
  int n_knight;
  int t, nh, nk;
  while (1) {
    cin >> n_head >> n_knight;
    if (n_head == 0 && n_knight == 0) {
      break;
    }
    nh = n_head;
    nk = n_knight;
    while (n_head--) {
      cin >> t;
      heads.push_back(t);
    }
    while (n_knight--) {
      cin >> t;
      knights.push_back(t);
    }
    sort(heads.begin(),heads.end());
    sort(knights.begin(),knights.end());
    check(nh, nk);
    heads.clear ();
    knights.clear ();
  }
  return 0;
}
//
// 12
// 10
// 8
// 
// vs
//
// 10
// 18
// 10
