#include <iostream>
#include <sstream>

using namespace std;

/** 
 * Palindrometer Solution
 * Author: Christopher Ghyzel
 * Simply converts between strings and numbers and 
 * checks if the reversed string is equal to the original.
 * This solution is well within the time limit but is inefficient.
 */
int main() {
  long num, n, length;
  string input, temp;
  bool notQuit = true;
  while(notQuit) {
    cin >> input;
    length = input.length();
    temp = input;
    // convert from string to number
    istringstream (temp) >> num; 
    if(num || length != 1) { //check for single 0
      n = 0;n
      while(temp != string(temp.rbegin(), temp.rend())) { // check if reversed string is the same as original
	n++;
	num++;
	temp = to_string(num); 
	while(temp.length() != length) { 
	  temp = string("0") + temp; //Concatenate zeros to front
	}
      }
      cout << n << endl;
    }
    else {
      notQuit = false;
    }
  }
}
