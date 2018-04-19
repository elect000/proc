#include <iostream>
#include <sstream>
using namespace std;

static int size = 20;
static int ssize = 19;
int state[20][20];
int sum, i, j;
static void printer();
void check(int, int);
void state_change();

void state_change () {
  for (i = 0; i < size; ++i) {
    for (j = 0; j < size; ++j)
      check (i,j);
  }
}

void check (int y, int x) {
  sum = 0;
  if (y == 0) {
    if (x == 0) {
      sum = state [1] [0] + state [1] [1] + state [0] [1];
    } else if (x == ssize) {
      sum = state [1] [ssize] + state [1] [ssize - 1] + state [0] [ssize - 1];
    } else {
      sum = state [0] [x - 1] + state [1] [ssize - 1]
        + state [1] [x] + state [1] [x + 1]
        + state [0] [x + 1];
        }
  } else if (y == ssize) {
    if (x == 0) {
      sum = state [ssize - 1] [0] + state [ssize - 1] [1] + state [ssize] [1];
    } else if (x == ssize) {
      sum = state [ssize] [ssize - 1] + state [ssize - 1] [ssize - 1]
        + state [ssize - 1] [ssize];
    } else {
      sum = state [ssize] [x - 1] + state [ssize - 1] [x - 1]
        + state [ssize - 1] [x] + state [ssize - 1] [x + 1]
        + state [ssize] [x + 1];
    }
  } else {
    if (x == 0) {
      sum = state [y - 1] [0] + state [y - 1] [1]
        + state [y] [1] + state [y + 1] [1]
        + state [y + 1] [0];
    } else if (x == ssize) {
      sum = state [y - 1] [ssize] + state [y - 1] [ssize - 1]
        + state [y] [ssize - 1] + state [y + 1] [ssize - 1]
        + state [y + 1] [ssize];
    } else {
      sum = state [y + 1] [x] + state [y + 1] [x + 1]
        + state [y] [x + 1] + state [y - 1] [x + 1]
        + state [y - 1] [x] + state [y - 1] [x - 1]
        + state [y] [x - 1] + state [y + 1] [x - 1];
    }
  }
  if (sum % 10 == 3) {
    state [y] [x] += 10;
  } else if (sum % 10 == 2 && state [y] [x] % 10 == 1){
    state [y] [x] += 10;
  } else {}
}

int main()
{
  string s, st;
  int cases, year, x, y;
  cin >> cases;
  while (cases--) {
    getline (cin, s);
    cin >> year;
    for (i = 0; i < size; ++i) {
      for (j = 0; j < size; ++j) {
        state [i][j] = 0;
      }
    }
    getline(cin, s);
    while (getline (cin, s)) {
      if (s == "") break;
      stringstream ss (s);
      getline (ss, st, ' ');
      y = atoi (st.c_str ()) - 1;
      getline (ss, st, ' ');
      x = atoi (st.c_str ()) - 1;
      state [y] [x] = 1;
    }
    for (i = 0; i < size; ++i) {
      cout << "*";
    }
    cout << "\n";
    while (year--) {
      printer ();
      state_change ();
      for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
          state [i] [j] /= 10;
        }
      }
    }
    cout << "\n";
  }
  return 0;
}

static void printer() {
  for (i = 0; i < size; ++i) {
    for (j = 0; j < size; ++j) {
      if (state[i][j]) cout << "O";
      else cout << " ";
    }
    cout << "\n";
  }
  for (i = 0; i < size; ++i) {
    cout << "*";
  }
  cout << "\n";
}
