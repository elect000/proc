// Largest Submatrix
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

char matrix[30][30];
int base = (int)'1' - 1;
vector<int> v;

int main()
{
  int times;
  string dummy;
  scanf("%d", &times);
  getline (cin, dummy);
  getline (cin, dummy);
  while (times--) {
    int index = 0;
    // read
    
    while (fgets(matrix[index], 30, stdin) && matrix[index] != "\n") {
      if (matrix [index] [0] == '\n') break;
      index++;
      // getline(cin, dummy);
    }
    // ++index;
    for (int i = 0; i < index; ++i) {
      for (int j = 1; j < index; ++j) {
        if (matrix [i] [j] == '1') {
          // 0012301200...
          // 0123450000...
          matrix [i] [j] = (matrix [i] [j - 1] + 1);
        }
      }
    }

    int max = 0;
    for (int i = 0; i < index; ++i) {
      for (int j = 0 ; j < index; ++j) {
        if (matrix [i] [j] == '0' || (int)matrix [i] [j] == 0) continue;
        int width = matrix [i] [j] - '0';
        // 1001 0 000000....
        // 0123[4]000000....
        // 0012 3 000000....
        // 0123 0 000000....
        v.clear ();
        v.push_back (width);
        for (int k = i + 1; k < index; ++k) {
          if (matrix [k] [j] == '0')
            break;
          // height : k - i + 1
          // width : min(prev_max,
          //             matrix[k][j])
          if (width > (matrix [k] [j] - '0')) {
            v.push_back ((matrix [k] [j] - '0') * (k - i + 1));
            width = ((int) matrix [k] [j] - '0');
          }
          else
            v.push_back (width * (k - i + 1));
        }
        sort (v.begin (), v.end ());
        if (max < v [v.size () - 1])
          max = v [v.size () - 1];
      }
    }
    printf ("%d\n", max);
    if (times != 0) printf("\n");
  }
  return 0;
}
