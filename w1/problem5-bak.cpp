// Football
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <istream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string teams [30];
int team_info [30][6];
// 0            1   2   3
// game_played  win tie losses
// 4           5
// goal_score  goal_against
int team_result [30];
// 0
// total_points

vector<int[6]> calc;


string dummy;
void read_battles(int);
void show_result (int);
void judge (int, int, int, int);
void init ();


void init () {
  for (int i = 0; i < 30; ++i) {
    team_result [i] = 0;
    for (int j = 0; j < 6; ++j) {
      team_info [i] [j] = 0;
    }
  }
}

void judge (int a_id, int b_id, int a_point, int b_point) {
  // 0            1   2   3
  // game_played  win tie losses
  // 4           5
  // goal_score  goal_against
  ++(team_info [a_id] [0]);
  ++(team_info [b_id] [0]);
  team_info [a_id] [4] += a_point;
  team_info [a_id] [5] += b_point;
  team_info [b_id] [5] += a_point;
  team_info [b_id] [4] += b_point;
  if (a_point > b_point) {
    ++(team_info [a_id] [1]);
    ++(team_info [b_id] [3]);
  } else if (a_point < b_point) {
    ++(team_info [b_id] [1]);
    ++(team_info [a_id] [3]);
  }
  else {
    ++(team_info [a_id] [2]);
    ++(team_info [b_id] [2]);
  }
}

void read_battles (int num_teams) {
  int team_a_id, team_b_id;
  string info;
  int team_a_point, team_b_point;
  string a_team, b_team;
  getline(cin, info);
  string delimiter1 = "#";
  string delimiter2 = "@";
  size_t pos;
  pos = info.find(delimiter1);
  a_team = info.substr(0, pos);
  info.erase(0, pos + delimiter1.length());
  pos = info.find(delimiter2);
  team_a_point = atoi((info.substr(0, pos)).c_str ());
  info.erase (0, pos+ delimiter2.length ());
  pos = info.find(delimiter1);
  team_b_point = atoi((info.substr(0, pos)).c_str ());
  info.erase (0, pos+ delimiter1.length ());
  b_team = info;

  for (int i = 0; i < num_teams; ++i) {
    if (0 == teams [i].compare (a_team)) {
      team_a_id = i;
    }
  }
  for (int i = 0; i < num_teams; ++i) {
    if (0 == teams [i].compare (b_team)) {
      team_b_id = i;
    }
  }
  judge (team_a_id, team_b_id,
         team_a_point, team_b_point);
}
void printer (int i, int j, int rank) {
  printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
         rank,
         (teams [j]).c_str (),
         i,
         team_info [j] [0],
         team_info [j] [1],
         team_info [j] [2],
         team_info [j] [3],
         team_info [j] [4] - team_info [j] [5],
         team_info [j] [4],
         team_info [j] [5]);
}

void show_result (int num_teams) {
  // 0            1   2   3
  // game_played  win tie losses
  // 4           5
  // goal_score  goal_against

  // !!!!!!!!!!!!!!!!
  for (int i = 0; i < num_teams; ++i) {
    team_result [i] = team_info [i] [1] * 3 + team_info [i] [2];
  }
  int max = 0;
  for (int i = 0; i < num_teams; ++i) {
    if (max < team_result [i])
      max = team_result [i];
  }
  // to sort
  int rank = 1;
  for (int i = max; i >= 0; --i) {
    for (int j = 0; j < num_teams; ++j) {
      if (i == team_result [j]) {
        printer (i, j, rank);
        ++rank;
      }
    }
  }
  // !!!!!!!!!!!!!!!!!!!!!!
}



int main()
{
  int times;
  string title, team_name;
  vector<string> v;
  scanf ("%d", &times);
  getline (cin, dummy);
  while (times--) {
    init ();
    // read and write title
    getline(cin, title);
    printf ("%s\n", title.c_str());
    int num_teams;
    scanf ("%d", &num_teams);
    getline (cin, dummy);
    string temp;
    for (int i = 0; i < num_teams; ++i) {
      getline(cin, temp);
      v.push_back (temp);
    }
    sort (v.begin (), v.end ());
    int k = v.size () - 1 ;
    for (string s: v) {
      teams [k] = s;
      --k;
    }
    int battles;
    scanf ("%d", &battles);
    getline (cin, dummy);
    for (int i = 0; i < battles; ++i) {
      read_battles(num_teams);
    }
    show_result(num_teams);
    printf ("\n");
    v.clear ();
    calc.clear ();
  }
  return 0;
}
