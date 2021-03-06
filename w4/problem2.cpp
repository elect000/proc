#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
int visited [500010];
int mp [50010];
int reached [50010];

int dfs(int i)
{
  visited[i] = 1;
  int r = 0;
  if ((mp[i] != 0) && (visited[mp[i]] == 0)) {
    r += dfs(mp[i]) + 1;
  }
  visited[i] = 0;
  reached[i] = r; // memorize!
  return r;
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
    memset(visited, 0, sizeof(visited));
    memset(reached, -1, sizeof(reached));
    for (int i = 1; i <= elem_num; ++i) {
      if (reached[i] == -1) {
        dfs(i);
      }
      if (max < reached[i]) {
        max = reached[i];
        res = i;
      }
    }
    printf("Case %d: %d\n", ++c, res);
  }
  return 0;
}
