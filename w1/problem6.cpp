#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

vector<string> source;
string dummy;
string elem;

bool comp(string, string);

int main()
{
  int times;
  scanf("%d",&times);
  getline(cin, dummy);
  getline(cin, dummy);
  while (times--) {
    map<string, int> pair = {};
    decltype(pair)::iterator it;
    source.clear();
    pair.clear();
    int elem_num = 0;
    while(getline(cin,elem) && elem.compare("") != 0) {
      elem_num++;
      source.push_back(elem);
    }
    string a, b;
    for (int i = 0; i < elem_num / 2; ++i) {
      for (int j = elem_num - 1; j >= elem_num / 2; --j) {
        a = source[i] + source[j];
        b = source[j] + source[i];
        if ((it = pair.find(a)) != pair.end()) { // find a in map
          ++ pair [a];
        } else if ((it = pair.find (b)) != pair.end ()) { // find b in map
          ++ pair [b];
        } else { // not found
          pair.insert (make_pair (a, 0));
          pair.insert (make_pair (b, 0));
        }
      }
    }
    ///////////////////////////
  }
  return 0;
}

