#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int element_num;
int edges [101] [101];
bool visited [101];

void printer () {
  cout << "+";
  for (int i = 0; i < element_num * 2 -1; ++i)
    cout << "-";
  cout << "+\n";
}

void init_visited ()
{
  for (int i = 0; i < 101; ++i)
    visited [i] = false;
}

void dfs (int place, int killed) // 0 -1
{
  if (place == killed) // 0 == -1
    return;
  visited [place] = true; 
  for (int i = 0; i < element_num; ++i) {
    if (edges [place] [i] && !visited [i])
      dfs (i, killed);
  }
}

int main()
{
  int c = 0;
  int times;
  scanf("%d", &times);
  while (times--) {
    bool res [101] [101];
    scanf("%d", &element_num);
    // input
    for (int i = 0; i < element_num; ++i) {
      for (int j = 0; j < element_num; ++j) {
        int element;
        scanf("%d", &edges [i] [j]);
      }
    }
    int can_reach [101];
    // reset visited place
    init_visited ();
    dfs (0,-1);
    for (int i = 0; i < element_num; ++i)
      can_reach [i] = visited [i] ? 1 : 0;
    for (int i = 0; i < element_num; ++i) {
      init_visited ();
      dfs (0, i);
      for (int j = 0; j < element_num; ++j) {
        if (can_reach [j] && !visited [j]) res [i] [j] = true;
        else res [i] [j] = false;
      }
    }
    cout << "Case " << (++c) << ":" << endl;
    printer ();
    for (int i = 0; i < element_num; ++i) {
      for (int j =0; j < element_num; ++j)
        cout << "|" << ( res [i] [j]? 'Y': 'N');
      cout<<"|\n";
      printer ();
    }
  }
  return 0;
}
// visited
//  ... if the j-th is visited,
//      visited[j] = true;
// edges
//  ... if i -> j 's edge is available,
//  ... edges[i][j]
