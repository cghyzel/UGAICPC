#include <iostream>

using namespace std;

/*
 * Really simple problem and solution
 * Author: Christopher Ghyzel
 */
int main() {
  int n = 0, count = 0, i=0, temp = 0, previous = 0;
  int ordered [25] = {0};
  
  cin >> n; 
  while(n) {
    //reset previous at the beginning of new input set
    previous = 0;
    for(i = 0; i < n; i++) {
      cin >> temp;
      if(temp != previous) //if temp is not the previous
	ordered[count++] = temp; //add it to the ordered list
      previous = temp;
    }
    // print guesses in original order with no duplicates
    for(i = 0; i < count; i++) {
      cout << ordered[i] << " ";
    }
    cout << "$" << endl; //end of output
    count = 0;
    cin >> n;
  }
}
