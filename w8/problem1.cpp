#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> sl;
bool cmp (string a, string b) {
  return a.size() < b.size();
}

bool contain (string a, string b) {
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

int main()
{
  bool res;
  int times = 0;
  string a, b, str;
  while (cin >> str) {
    if (str != "9") {
      sl.push_back(str);
    }
    else {
      res = true;
      sort(sl.begin(), sl.end(), cmp);
      for (int i = 0; i < sl.size() - 1; ++i) {
        if (!res) break;
        for (int j = i + 1; j < sl.size(); ++j) {
          a = sl[i];
          b = sl[j];
          if (contain(a, b)) {
            res = false;
            break;
          }
        }
      }
      if (res)
        printf("Set %d is immediately decodable\n", ++times);
      else
        printf("Set %d is not immediately decodable\n", ++times);
      sl.clear();
    }
  }
  return 0;
}
