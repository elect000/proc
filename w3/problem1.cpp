// Wedding Shopping
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

bool matrix[201][20];
// matrix[value][addition number]
// = true or false
int main()
{
  int times;
  scanf("%d", &times);
  while (times--) {
    int M, C;
    scanf("%d %d", &M, &C);
    memset(matrix, 0, sizeof(matrix));
    matrix [0] [0] = true;
    for (int i = 1; i <= C; ++i) {
      int K;
      cin >> K;
      for (int j = 0; j < K; ++j) {
        int t = 0;
        cin >> t;
        for (int k = 0; k + t <= M; ++k) {
          matrix[k + t][i] = (matrix [k + t] [i] || (matrix[k][i - 1]));
        }
      }
    }
    bool t = true;
    for (int i = M; i > 0; --i) {
      if (t && matrix [i] [C]) {
        printf ("%d\n", i);
        t = false;
        break;
      }
    }
    if (t) printf ("no solution\n");
  }
  return 0;
}

