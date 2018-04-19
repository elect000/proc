#include <stdio.h>
#include <iostream>
using namespace std;

int i;
int shuffle [100] [52];
int card [52], temp_card [52];
static string values [13] =
  {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
static string suits [4] =
  {"Clubs", "Diamonds", "Hearts", "Spades"};

void change (int);
void printout ();

void printout () {
  for (i = 0; i < 52; ++i)
    cout << values [card [i] % 13] << " of " << suits [(card [i] - 1) / 13] << endl;}


void change (int n) {
  for (i = 0; i < 52; ++i)
    temp_card [i] = card [shuffle [n - 1] [i] - 1];
  for (i = 0; i < 52; ++i)
    card [i] = temp_card [i];
}

int main()
{
  int cases, times, j, type;
  string str;
  cin >> cases;
  while (cases--) {
    for (i = 0; i < 52; ++i)
      card [i] = i + 1;
    cin >> times;
    for (i = 0; i < times; ++i) {
      for (j = 0; j < 52; ++j)
        cin >> shuffle [i] [j];
    }
    getline (cin, str);
    while (getline (cin, str)) {
      if (str == "\0")
        break;
      else {
        type = atoi (str.c_str ());
        change (type);
      }
    }
    printout ();
    if (cases)
      cout << endl;
  }
  return 0;
}
