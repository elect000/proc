#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct Edge {
  int from, to, cost;
  Edge (int f, int t, int c)
    : from (f), to (t), cost (c) {}
};

struct Node {
  // place, remaining_fuel, costs
  int p, r_fuel, c;
  bool operator < (const Node &n) const {
    return c>n.c;
  }
};
// prevent returning : ex 1->2->1->2->1...
int mem [1000][101];

int prices [1000];
vector<Edge> ve;
vector<int> edges[1000];

int simulate (int, int, int);

int simulate (int cap, int s, int e) {
  memset(mem, -1, sizeof(mem));
  priority_queue<Node> pq;
  Node node, node2;
  // initialize
  node.p = s;
  node.r_fuel = 0;
  node.c = 0;
  mem[s][0] = 0;
  pq.push (node);
  while(pq.size()) {
    node = pq.top();
    pq.pop();
    // reached destination
    if (node.p == e) return node.c;
    for (int i : edges[node.p]) {
      Edge e = ve[i];
      if  ((node.r_fuel < cap)
           && ((mem [node.p] [node.r_fuel + 1] == -1)
               || (mem [node.p] [node.r_fuel + 1] > node.c + prices [node.p]))) {
        node2.p = node.p;
        node2.r_fuel = node.r_fuel + 1;
        node2.c = node.c + prices[node.p];
        mem[node2.p][node2.r_fuel] = node2.c;
        pq.push (node2);
      }

      node2.p = e.to;
      node2.r_fuel = node.r_fuel -  e.cost;
      node2.c = node.c;

      // can reach the city
      if (node2.r_fuel < 0) continue;
      if ((mem [node2.p] [node2.r_fuel] == -1)
             ||(mem [node2.p] [node2.r_fuel] > node2.c)) {
        pq.push (node2);
        mem [node2.p] [node2.r_fuel] = node2.c;
      }
    }
  }
  return -1;
}


int main()
{
  int n, m;
  int u, v, d;
  int q;
  while (scanf ("%d %d", &n, &m) == 2) {
    memset(edges, 0, sizeof(edges));
    // read fuel's price
    for (int i = 0; i < n; ++i)
      scanf ("%d", &prices [i]);
    // read edge's information
    for (int i = 0; i < m; ++i) {
      scanf ("%d %d %d", &u, &v, &d);
      ve.push_back (Edge (u, v, d));
      ve.push_back (Edge (v, u, d));
      int m = ve.size();
      edges[u].push_back(m-2);
      edges[v].push_back(m-1);
    }
    scanf ("%d", &q);
    while (q--) {
      int c, s, e;
      scanf ("%d %d %d", &c, &s, &e);
      int res = simulate (c, s, e);
      if (res != -1)
        printf ("%d\n", res);
      else
        printf ("impossible\n");
    }
  }
  return 0;
}

