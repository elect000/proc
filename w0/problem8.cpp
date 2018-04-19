#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

static int size = 21;
static int ssize = 20;
int state[22][22];
int sum, i ,j;
int checker [] = {-1,0,1};

void printer();
void update(int, int);
void state_change();

void update (int y, int x) {
  sum = 0;
  for (int p : checker) {
    for (int q : checker) {
      if ((p == 0) && (q == 0)) {}
      else {
        sum += state [y + p] [x + q];
      }
    }
  }
  sum %= 10;
  if (sum == 3) {
    state [y] [x] += 10;
  } else if (state [y] [x] == 1 && sum == 2) {
    state [y] [x] += 10;
  } else {}
}



int main()
{
  string s, st;
  int cases, year, x, y;
  cin >> cases;
  getline (cin, s);
  while (cases--) {
    cin >> year;
    // initialize
    for (i = 0; i < size; ++i) {
      for (j = 0; j < size; ++j) {
        state [i] [j] = 0;
      }
    }
    // read positive position
    getline (cin, s);
    while (getline (cin, s)) {
      if (s == "") break;
      stringstream ss (s);
      getline (ss, st, ' ');
      y = atoi (st.c_str ());
      getline (ss, st, ' ');
      x = atoi (st.c_str ());
      state [y] [x] = 1;
    }
    for (i = 0; i < ssize; ++i) {
      cout << "*";
    }
    cout << "\n";
    // print & update
    while (year--) {
      printer ();
      state_change ();
      for (i = 1; i < size; ++i) {
        for (j = 1; j < size; ++j) {
          state [i] [j] /= 10;
        }
      }
    }
    if (cases) {
      cout << endl;
    }
  }
  return 0;
}


void printer() {
  for (i = 1; i < size; ++i) {
    for (j = 1; j < size; ++j) {
      if (state[i][j]) cout << "O";
      else cout << " ";
    }
    cout << "\n";
  }
  for (i = 0; i < ssize; ++i) {
    cout << "*";
  }
  cout << "\n";
}

void state_change () {
  for (i = 1; i < size; ++i) {
    for (j = 1; j < size; ++j) {
      update (i, j);
    }
  }
}
