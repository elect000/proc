#include <iostream>
#include <sstream>
using namespace std;

int main()
{
  unsigned int N, res, s;
  string str;
  cin >> N;
  cin.ignore ();
  for (unsigned int i = 0; i < N; ++i) {
    res = 0;
    getline(cin, str);
    istringstream S(str);
    while (S >> s) {
      if (s > res) 
      res = s;
    }
    cout << "Case " << (i + 1) << ": " << res << "\n";
  }
  return 0;
}
