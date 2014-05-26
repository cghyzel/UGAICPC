/*
  Chris Nguyen
  May 25th, 2014
  Goal: a, b, c, d must equal each other after some round of substraction.
        a = |a-b|, b = |b-c|, c = |c-d|, d = |d-a| (use the values from the previous not updated value of current round)
  Inputs: 4 numbers on each line representing a,b,c,d respectively
          0 0 0 0 marks the end of inputs
 */

#include <iostream>
#include <cmath>
using namespace std;

int main () {
int a, b, c, d;
int temp;
  do {
    int minimum = 0;
    cin >> a >> b >> c >> d;
    
    if ( !(a || b || c || d) ) exit(0); // if ( !0 && !0 && !0 && !0 )

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
