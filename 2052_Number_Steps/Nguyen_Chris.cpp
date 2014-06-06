/*
 Chris Nguyen
 2052 Number Steps
 Look at this problem, there is a nice grid that shows the points.
 Given a set of points, determine the number related to those points as shown in the grid.
 */

#include <iostream>
using namespace std;

int main() {
    int n; // number of test cases
    int x, y;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        /*
         x and y must be on one of the following lines:
         y = x
         y = x - 2
         */
        if (y == x || y == x - 2) {
            // x and y are both even: z = x + y
            if (x % 2 == 0 && y % 2 == 0) cout << (x+y) << endl;
            // at least x or y is odd: z = x + y - 1
            else cout << (x+y-1) << endl;
        } else cout << "No Number" << endl;
    } // for i
} // main
