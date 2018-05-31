#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
int visited [50000];
int mp [50000];
int reached [50000];

inline int dfs(int i)
{
  if (visited[i] == 1
      ) {
    return 1;
  }
  visited[i] = 1;
  if (mp[i] == 0) {
    return 1;
  } else {
    return dfs(mp[i]) + 1;
  }
}

int main()
{
  int c = 0;
  int times;
  scanf("%d", &times);
  int res = 0;
  while (times--) {
    memset(mp, 0, sizeof(mp));
    int elem_num = 0;
    scanf("%d", &elem_num);
    for (int i = 0; i < elem_num; ++i) {
      int k, v;
      scanf("%d %d", &k, &v);
      mp[k] = v;
    }
    int max = 0;

    for (int i = 1; i <= elem_num; ++i) {
      memset(visited, 0, sizeof(visited));
      
      int r = dfs(i);
      reached [i] = r;
      if (max < r) {
        max = r;
        res = i;
      }
    }
    printf("Case %d: %d\n", ++c, res);
  }
  return 0;
}
