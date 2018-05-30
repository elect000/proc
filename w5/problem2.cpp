#include <stdio.h>
#include <algorithm>
using namespace std;
// 4
// for-young  A->B      cost
// Y           U    A B 4
// for-young  C->A      cost
// Y           U    C A 1
// for-more30 D->B      cost
// M           U    D B 6
// for-more30 C<->D     cost
// M           B    C D 2

int main()
{
  int lines;
  while (scanf("%d", &lines) && lines != 0) {
    char dummy;
    // scanf ("%c", &dummy);
    int matrix_I[26][26];
    int matrix_Prof[26][26];
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        matrix_I[i][j] = 1001;
        matrix_Prof[i][j] = 1001;
      }
      matrix_I[i][i] = 0;
      matrix_Prof[i][i] = 0;
    }
    char a, b, c, d;
    int val;
    while (lines--) {
      scanf("%c %c %c %c %c",
            &dummy, &a, &b, &c, &d);
      scanf ("%d", &val);
      int from = c - 'A';
      int to = d - 'A';
      if (a == 'Y') {
        // for young
        if (b =='U')
          matrix_I[from][to] =
            min(matrix_I[from][to], val);
        else
          matrix_I[from][to] =
            matrix_I[to][from] =
            min(val,
                matrix_I[to][from]);
      } else {
        // for more 30
        if (b == 'U')
          matrix_Prof [from] [to] =
            min (matrix_Prof [from] [to], val);
        else
          matrix_Prof [from] [to] =
            matrix_Prof [to] [from] =
            min (val,
                 matrix_Prof [to] [from]);
      }
    }
    int res = 1001;
    int min_pos;
    int from, to;
    scanf ("%c %c %c", &dummy, &a, &b);

    from = a - 'A';
    to = b - 'A';
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        for (int k = 0; k < 26; ++k) {
          // a[j] -> a[k] 's cost ?
          // a[j] -> a[i] -> a[k] 's cost?
          matrix_I [j] [k]
            = min (matrix_I [j] [k],
                   matrix_I [j] [i]
                   + matrix_I [i] [k]);
          matrix_Prof [j] [k]
            = min (matrix_Prof [j] [k],
                   matrix_Prof [j] [i]
                   + matrix_Prof [i] [k]);
        }
      }
    }

    for (int i = 0; i < 26; ++i) {
      if ((matrix_I [from] [i] + matrix_Prof [to] [i] < res)
          && (matrix_I [from] [i] <= 500)
          && (matrix_Prof [to] [i] <= 500)
          ) {
        res = matrix_I [from] [i]
          + matrix_Prof [to] [i];
      }
    }
    if (res == 1001)
      printf ("You will never meet.\n");
    else {
      printf ("%d", res);
      for (int i = 0; i < 26; ++i) {
        if (matrix_I [from] [i] + matrix_Prof [to] [i] == res)
        printf (" %c", i + 'A');
      }
      printf ("\n");
    }
  }
  return 0;
}
