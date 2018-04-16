#include <iostream>
using namespace std;

static int default_day_max [12] =
  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
private:
  unsigned int check_month () {
    if (month == 2) return this->check_leap ();
    else return 0;
  }
public:
  unsigned int year;
  unsigned int month;
  unsigned int day;
  Date () {};
  Date (unsigned int y, unsigned int m, unsigned int d) {
    year = y;
    month = m;
    day = d;
  }
  bool zero () {
    return (year == 0) && (month == 0) && (day == 0);
  }
  unsigned int check_leap () {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
      return 1;
    else
      return 0;
  }
  Date& operator+=(unsigned int n) {
    day += n;
    unsigned int t;
    while ((int) day > (t = (default_day_max [(int) month - 1] + (this->check_month ())))) {
      day -= t;
     if (month == 12) {
       year++;
       month = 1;
     } else {
       month++;
     }
    }
    return *this;
  }
};

int main()
{
  Date date;
  unsigned int n;
  while (1) {
    cin >> n >> date.day >> date.month >> date.year;
    if ((date.zero ()) && (n == 0)) break;
    date += n;
    cout << date.day <<  " " << date.month  << " " << date.year << "\n";
  }
  return 0;
}
 
