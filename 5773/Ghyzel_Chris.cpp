#include <iostream> // cin, cout
#include <cmath>    // abs
using namespace std;

/**
 * Viva La Difference!
 * Problem: Find the number of steps required till the numbers converge.
 * Really simple solution. We should consider giving this to people as their first problem.
 */

int main() {
  bool notQuit = true;
  int a, b, c, d, tempA, tempB, tempC, tempD, steps;
  
  while(notQuit) {
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    if(a || b || c || d) {
      steps = 0;
      while(!(a == b && a == c && a == d)) {
	tempA = a;
	tempB = b;
	tempC = c;
	tempD = d;
	a = abs(tempA - tempB);
	b = abs(tempB - tempC);
	c = abs(tempC - tempD);
	d = abs(tempD - tempA);
	steps++;
      }
      cout << steps << endl;
    } else {
      notQuit = false;
    }
  }
}
