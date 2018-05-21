#include <iostream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
vector<char> v;
map<char, vector<char>> m;
int end_state;
bool res;
string str;

void my_search (string s) {
  if ((int) s.size () == end_state) {
    bool first = true;
    for (char c : s) {
      if (first) {
        first = false;
        printf ("%c",c);
      } else {
        printf (" %c",c);
      }
    }
    printf ("\n");
    res = true;
    return;
  }
  for (char c : str) {
    bool check = true;
    for (char c_ : s) {
      if (find (m [c].begin (), m [c].end (), c_)
          != m [c].end () ||
          (string::npos != s.find (c)))  {
           check = false;
      }
    }
    if (check) {
      my_search (s + c);
    }
  }
  return;
}

int main()
{
  string dummy, st;
  int times;
  scanf("%d", &times);
  getline(cin, dummy);
  while (times--) {
    str = "";
    v.clear ();
    m.clear ();
    res = false;
    getline(cin, dummy);
    getline(cin, st);
    stringstream ss;
    ss << st;
    while (ss >> st)
      str += st;
    sort(str.begin(),str.end());
    ss.clear ();
    getline (cin, st);
    ss << st;
    // write rules
    while (ss >> st) {
      // "A<B" => key:"A" value:"B"
      m [st [0]].push_back (st [2]);
    }
    end_state = str.size ();
    for (int i = 0; i < end_state; ++i) {
      string s = "";
      s += str [i];
      my_search (s);
    }
    if (!res) {
      printf ("NO\n");
    }
    if (times != 0) {
      printf ("\n");
    }
  }
  return 0;
}
