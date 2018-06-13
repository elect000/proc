#include <stdio.h>
#include <iostream>
#include <vector>
#define MAX_N 1000
#define MAX_M 2000
using namespace std;

void init (int, int);

struct edge {
  // 0 -> 1 's cost is 1000
  int from, to, cost;
};

int weights[MAX_N];
edge edges[MAX_M];

void init (int n, int m) {
  int f, t, c; // from, to, cost
  for (int i = 0; i < m; ++i) {
    scanf ("%d %d %d", &f, &t, &c);
    edges [i] = (edge){f,t,c};
  }
  for (int i = 0; i < n; ++i) {
    weights [i] = 0;
  }
}

int main(){
  int times;
  scanf("%d", &times);
  while (times--) {
    int n, m;
    bool flag;
    scanf ("%d %d", &n, &m);
    init (n, m);
    for (int n_ = 0; n_ < n; ++n_) {
      flag = false;
      for (int m_ = 0; m_ < m; ++m_) {
        // -----------------------
        // Fig.
        //     1000     15
        //   0  ->   1  ->   2
        //              <-
        //              -42
        // --------------------------
        // costs = (weights[0]: 0)
        //          +(edges[0].cost: 1000)
        // if costs < (weights[1]: 0) //false
        //   weights[1] = costs; 
        //   flag = true
        // ---------------------------
        // costs = (weights[2]: 0)
        //         +(edges[2].cost: -42)
        // if costs < (weights[1]: 0) // true
        //            ...
        // ---------------------------
        int costs = weights [edges [m_].from] + edges [m_].cost;
        if (costs < weights [edges [m_].to]) {
          weights [edges [m_].to] = costs;
          flag = true;
        }
      }
      if (!flag) break;
    }
    if (flag) {
      printf ("possible\n");
    } else {
      printf ("not possible\n");
    }
  }
  return 0;
}
