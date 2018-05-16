// The Stern-Brocot Number System
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
  int m, n;
  while (true) {
    vector<char> vec;
    scanf("%d %d", &m, &n);
    if (m == 1 && n == 1) break;
    while (true) {
      vec.clear ();
      bool left = true;
      while (true) {
        // 1/n
        if (m == 1) {
          if (left) {
            for (int i = 0; i < n - 1; ++i)
              vec.push_back ('L');
          } else {
            for (int i = 0; i < n - 1; ++i)
              vec.push_back ('R');
          }
          n = 1;
          break;
        }
        // m/1
        if (n == 1) {
          if (left) {
            for (int i = 0; i < m - 1; ++i)
              vec.push_back ('R');
          } else {
            for (int i = 0; i < m - 1; ++i)
              vec.push_back ('L');
          }
          m = 1;
          break;
        }
        // m/n (m<n)
        if (m < n) {
          left = !left;
          int t = m;
          m = n;
          n = t;
        }
        // m/n (m>n)
        else {
          while (m > n) {
            if (left) vec.push_back ('R');
            else vec.push_back ('L');
            m -= n;
          }
        }
      }
      for (char c: vec) {
        printf ("%c", c);
      }
      printf ("\n");
      break;
    }
  }
  return 0;
}

// 1/1 => 1/2 => 2/3 => 3/4 => 5/7
//     L      R      R      L

//  2      2     1        1
// --- =  --- = --- = -------
//  3      3     3     1 + 1 <! L
//              ---       ---
//               2         2 <! R
//
//  5      5     1      1
// --- =  --- = ---- = ------    
//  7      7     7     1 + 2 <! L
//              ---       ---
//               5         5


//  2      1
// --- = ------
//  5     2 + 1 <! RR
//           ---
//            2 <! L
