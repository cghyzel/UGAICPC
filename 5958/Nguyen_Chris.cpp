/*
  Chris Nguyen
  May 25th, 2014

  Triangular Number 5958
  Goal: Given a number k, determine if k is a triangular number and print out the number of dots on the side
  Input: 1 integer on each line

  Strategy: A triangular number can be thought of a sum of the 1st n natural numbers: k = n(n+1)/2
 */

#include <iostream>
#include "math.h" // <cmath>
using namespace std;

int main() {
  int answer = 0;
  int k = 0;

  while (cin >> k) {
    answer = static_cast<int>( sqrt(2*k) ); // approximate solution rounded down
    if ( answer * (answer+1) == 2 * k ) cout << answer << endl; // based on k = n(n+1)/2 <--> 2k = n(n+1)
    else cout << "bad" << endl;
  }
} // main
