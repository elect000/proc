#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

vector<string> source;
map<string, int> pairs = {};
string dummy;
string elem;

int main()
{
  int times;
  scanf("%d",&times);
  getline(cin, dummy);
  getline(cin, dummy);
  while (times--) {
    pairs.clear ();
    source.clear();
    int elem_num = 0;
    int elem_size_min = -1;
    int elem_size_max = -1;
    while(getline(cin,elem) && elem.compare("") != 0) {
      if (elem_size_min == -1) {
        elem_size_min = elem.length ();
        elem_size_max = elem.length ();
      } else {
        if (elem_size_min > elem.length ()) {
          elem_size_min = elem.length ();
        }
        if (elem_size_max < elem.length ()) {
          elem_size_max = elem.length ();
        }
      }
      elem_num++;
      source.push_back(elem);
    }
    int elem_size = elem_size_min + elem_size_max;
    string a, b;
    for (int i = 0; i < elem_num; ++i) {
      for (int j = elem_num - 1; j > 0; --j) {
        if (i == j) break;
        a = source[i] + source[j];
        b = source[j] + source[i];
        if (a > b) {
          string t = a;
          a = b;
          b = t;
        }
        if (a.length () == elem_size && pairs.find(a) != pairs.end()) { // find a in map
          ++ pairs [a];
        } else if (b.length () == elem_size &&  pairs.find (b) != pairs.end ()) { // find b in map
          ++ pairs [b];
        } else { // not found
          if (a.length () == elem_size)
            pairs.insert (make_pair (a, 0));
          if (b.length () == elem_size)
            pairs.insert (make_pair (b, 0));
        }
      }
    }

    int max = -1;
    vector<string> result;
    for (pair<string, int> p:pairs) {
      if (p.first.length () == (elem_size_max + elem_size_min)) {
        if (max < p.second) {
          result.clear ();
          result.push_back (p.first);
          max = p.second;
        } else if (max == p.second) {
          result.push_back (p.first);
        }
      }
    }
    sort(result.begin (), result.end ());
    printf ("%s\n", result [0].c_str());
    if (times) printf ("\n");
  }
  return 0;
}
