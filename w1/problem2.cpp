#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

char cv[100];
int iv[100];

int check(char,int);

int check(char c, int k) {
  for (int i = 0; i < k; ++i) {
    if (cv[i] == c) {
      ///      cout << c << " " << iv[i] << "\n";
      return iv[i];
    }
  }
  return 0;
}

int main()
{
  int N;
  cin >> N; // N <- 1
  while (N--) {
    // k1 = paid character's length
    // k2 = article's length
    int k, k1, k2; 
    int it;
    char ct;
    cin >> k; // k <- 7
    k1 = k;
    while (k--) {
      cin >> ct >> it;
      cv[k] = ct; // cv[k] <- a
      iv[k] = it; // iv[k] <- 3
    }
    cin >> k;
    k2 = k;
    string s;
    int sum = 0; // sum of money
    getline(cin, s);
    while (k--) {
      stringstream ss;
      getline(cin, s);
      ss << s;
      while(ss >> ct){
        sum += check(ct, k1);
      }
    }
    cout << fixed;
    cout << setprecision (2) << (((float)sum) / 100) << "$" <<  endl;
  }
  return 0;
}
