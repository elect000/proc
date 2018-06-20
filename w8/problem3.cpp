#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int cl[26];
bool check (string s) {
  for (int i = 0; i < 26; ++i) cl[i] = -1;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '&') continue;
    if (s[i] == '~') {
      if (cl[s[++i] - 'a'] == 1) return false;
      else {
        cl[s[i] - 'a'] = 0;
        continue;
      }
    }
    if (cl[s[i] - 'a'] == 0) return false;
    else cl[s[i] - 'a'] = 1;
  }
  return true;
}

int main()
{
  int times;
  scanf ("%d", &times);
  getchar();
  while (times--) {
    string str;
    getline (cin, str);
    bool res = false;
    int start;
    for (int i = 0; i < str.length() && !res; ++i) {
      if (str[i] == '(') start = i;
      if (str[i] == ')') res = check(str.substr(start + 1, i - start - 1));
    }
    if (res) puts("YES");
    else puts("NO");
  }
  return 0;
}

