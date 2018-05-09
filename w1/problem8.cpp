#include <iostream>
#include <stdio.h>
using namespace std;

#define max_people 10000
int peoples;

int llist [max_people * 2];

void set_friends(int, int);
void set_enemies(int, int);
bool are_friends(int, int);
bool are_enemies(int, int);
void merge (int, int);
void init ();
int run (int);

void init () {
  // 0 1 2 3 4 5 6 7 8 9
  // 0 1 2 3 4 5 6 7 8 9
  int t = max_people * 2;
  while (t--)
    llist [t] = t;
}

int run (int t) {
  // go to the top of the linked list
  if (t == llist [t]) return t;
  else return run (llist [t]);
}

void merge (int x, int y) {
  x = run (x);
  y = run (y);
  // x < y ex 3 5
  // 0 1 2 3 4 5 6 7 8 9
  // 0 1 2 5 4 5 6 7 8 9
  if (x % max_people < y % max_people)
    llist [x] = y;
  else if (x % max_people > y % max_people)
  llist [y] = x;
}

void set_friends(int x, int y) {
  if (are_enemies (x, y))
    printf ("-1\n");
   else {
    merge (x, y);
    merge (x + max_people, y + max_people);
  }
}

void set_enemies (int x, int y) {
  if (are_friends (x, y))
    printf ("-1\n");
  else {
    merge (x, y + max_people);
    merge (y, x + max_people);
  }
}

bool are_friends(int x, int y) {
  int xt = run (x);
  int yt = run (y);
  if (xt == yt) return true;
  return false;
}

bool are_enemies (int x, int y) {
  int xt = run (x);
  int ynt = run ((y + max_people)
                 % (max_people * 2));
  if (xt == ynt) return true;
  return false;
}

int main()
{
  scanf("%d", &peoples);
  init ();
  while (true) {
    int c, x ,y;
    scanf("%d %d %d", &c, &x, &y);
    if (c == 0 && x == 0 && y == 0) break;
    switch (c) {
    case 1: // set-friends
      set_friends(x, y);
      break;
    case 2: // set-enemies
      set_enemies(x, y);
      break;
    case 3: // are-friends?
      if (are_friends(x, y)) printf ("1\n");
      else printf ("0\n");
      break;
    default: // are-enemies?
      if (are_enemies(x, y)) printf ("1\n");
      else printf ("0\n");
      break;
    }
  }
  return 0;
}
