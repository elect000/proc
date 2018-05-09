// Army Buddies
#include <iostream>
using namespace std;

int buddies [100000][2];

int main()
{
  int B, S;
  while (true) {
    cin >> B >> S;
    if ((B == S) && (S == 0)) {
      break;
    }
    for (int i = 0; i < B; ++i) {
      // buddies[i][0] : i : buddies[i][1]
      buddies [i] [0] = i - 1; // left
      buddies [i] [1] = i + 1; // right
    }
    int x, y, s, t;
    while (S--) {
      cin >> x >> y;
      --x;
      --y;
      // ...[s][x]<----->[y][t]...
      s = buddies [x] [0];
      t = buddies [y] [1];
      if (s != -1) {
        cout << s + 1 << " ";
        buddies [s] [1] = t;
      } else {
        cout << "* ";
      }
      if (t != B) {
        cout << t + 1 << endl;
        buddies [t] [0] = s;
      } else {
        cout << "*" << endl;
      }
    }
    cout << "-"<< endl;
  }
  return 0;
}

// OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
// <- i j dead
//
// OOOOXXXXXXXXXXXXXXXOOOOOOOOOOO
// XXXXXXXXXXXXXXXXXXXOOOOOOOOOOO => end
// ^
// or
// OOOOXXXXXXXXXXXXXXXXXXXXXXXXXX => end
//                              ^
// 10 4
// 2  5
// 6  9
// 1  1
// 10 10
// OXXXXOOOOO 1 6
// OXXXXXXXXO 1 10
// XXXXXXXXXO * 10
// XXXXXXXXXX * *
