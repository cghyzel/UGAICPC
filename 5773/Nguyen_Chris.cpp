

#include <iostream>
#include <cmath>
using namespace std;

int a, b, c, d;
int temp;

int main () {
  do {
    int minimum = 0;
    cin >> a >> b >> c >> d;
    
    if ( !(a || b || c || d) ) exit(0);

    // brute force evalulation
    while (a != b || b != c || c != d || d != a) {
      minimum++;
      temp = a;
      a = abs(a-b);
      b = abs(b-c);
      c = abs(c-d);
      d = abs(d-temp);
    }
    cout << minimum << endl;
  } while (1);
} // main
