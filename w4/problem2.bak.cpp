#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
map<int,int> m;
vector<int> checked;

int dfs(int i)
{
  if (find(checked.begin(), checked.end(), i)
      != checked.end()) {
    return 1;
  }
  checked.push_back(i);
  if (m[i] == 0) {
    return 1;
  } else {
    return dfs(m[i]) + 1;
  }
}

int main()
{
  int c = 0;
  int times;
  scanf("%d", &times);
  int res = 0;
  while (times--) {
    m.clear();
    int elem_num = 0;
    scanf("%d", &elem_num);
    for (int i = 0; i < elem_num; ++i) {
      int k, v;
      scanf("%d %d", &k, &v);
      m[k] = v;
    }
    int max = 0;
    for (int i = 1; i <= elem_num; ++i) {
      checked.clear();
      int r = dfs(i);
      if (max < r) {
        max = r;
        res = i;
      }
    }
    printf("Case %d: %d\n", ++c, res);
  }
  return 0;
}
