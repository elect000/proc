#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

vector<string> dict;
vector<string> dec;
vector<int> linebreak;
const char cl [27] =
  {'A','B','C','D','E','F','G','H','I','J','K','L',
   'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};

int find (char c) {
  for (int i = 0; i < 27; ++i) {
    if (cl[i] == c) return i;
  }
  return -1;
}

int main()
{
  string str;
  while (true) {
    getline(cin, str);
    if (str[0] == '#') {
      break;
    }
    dict.push_back(str);
  }
  getline(cin, str);
  string res = str;
  string ans = str;
  int max_mcount = 0;
  for (int k = 1; k < 27; ++k) {
    for (int i = 0; i < str.length(); ++i) {
      res[i] = cl[(find(str[i]) + k) % 27];
    }
    int mcount = 0;
    for (string s : dict) {
      for (int i = 0; i < res.length(); ++i) {
        for (int j = 0 ; j < s.length(); ++j) {
          if (res[i+j] != s[j]) break;
          if (j == s.length() - 1)
            ++mcount;
        }
      }
    }
    if (max_mcount < mcount) {
      max_mcount = mcount;
      ans = res;
    }
  }
  linebreak.clear ();
  int pos = 0, prepos = -1;
  int count = 0;
  for (int i = 0; i < ans.length (); ++i) {
    if (ans [i] == ' ') pos = i;
    if (count >= 60 && prepos != pos) {
      count = 0;
      linebreak.push_back (pos);
      prepos = pos;
      i = pos;
    }
    ++count;
  }
  for (int i = 0; i < ans.length(); ++i) {
    if (i == ans.length () - 1 && ans [i] == ' ') break;
    if (linebreak [0] == i) {
      putchar ('\n');
      linebreak.erase (linebreak.begin ());
    }
    else putchar(ans[i]);
  }
  printf("\n");
  return 0;
}
