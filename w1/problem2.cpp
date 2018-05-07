// NewsPaper
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
    if (cv[i] == c) return iv[i];
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
    cin.ignore(); // If we add here, this code is accepted.
    cin >> k;
    k2 = k;
    string s;
    int sum = 0; // sum of money
    int ssize = 0;
    getline(cin, s);
    while (k--) { // lines
      getline(cin, s);
      ssize = s.size();
      for (int i = 0; i < ssize; ++i) {
        sum += check(s[i], k1);
      }
    }
    printf("%0.2lf$\n", (((double) sum) / 100));
  }
  return 0;
}
