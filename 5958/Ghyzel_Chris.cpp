#include <iostream>

using namespace std;

/**
 * 5958 - Inverse Triangular Numbers Solution
 * Author: Christopher Ghyzel
 * Pretty simple solution. I generate a list of all the triangular numbers to 1 million then iteratively search though them.
 * Useful resource: http://www.mathsisfun.com/algebra/triangular-numbers.html
 */
int main() {
  
  int triangularNums [44720] = {0}; 
  int i, num;
  bool isTriangular;
  triangularNums [0] = 1;

  //Generate triangular numbers
  // 44720 is the number of triangular numbers
  // below 1 million (10^9)
  for (i = 1; i < 44720 ; i++) {   
    triangularNums[i] = triangularNums[i-1] + (i+1);
  }

  while (cin >> num) {
    isTriangular = false;
    //I could implement binary search but I am lazy and this worked
    for (i = 0; (i < 44720) && !(isTriangular= (triangularNums[i] == num))  && (triangularNums[i] < num); i++) {}
    if(isTriangular) {
      cout << (i + 1) << endl;
    }
    else {
      cout << "bad" << endl;
    }
  }
}
