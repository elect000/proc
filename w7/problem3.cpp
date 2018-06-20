#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
  int r1, r2, a_, b_, a, b;
  while (true) {
    scanf("%d %d %d %d", &a_, &b_, &r1, &r2);
    if (a_ == 0 && b_ == 0 && r1 == 0 && r2 == 0) break;
    a = a_>b_?a_:b_;
    b = a_>b_?b_:a_;
    if (b >= (r1>r2?2*r1:2*r2)) {
      if (a >= 2 * (r1 + r2))
        printf ("S\n");
      else if (a >=
               ((r1 + r2) +
                (sqrt(((r1 + r2) * (r1 + r2)) -
                      ((b - (r1 + r2)) * (b - (r1 + r2)))))))
        printf ("S\n");
      else printf ("N\n");
    }
    else printf ("N\n");
  }
  return 0;
}
