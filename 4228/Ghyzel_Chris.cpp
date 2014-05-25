#include <iostream>

using namespace std;

/**
 * Chris 0 has to switch to C++ now because I beat him to finish this problem after he had started.
 */
int main() {
  bool numberWasUsed [49] = {false};
  bool notQuit = true;
  int i, temp, n;
  while(notQuit) {
    cin >> n;
    if(n) {
      // n is the number of tickets
      // 6 is the numbers per ticket
      for(i = 0; i < n*6; i++) {
	cin >> temp;
	numberWasUsed[temp-1] = true;
      }
      //breaks when the number was not used
      for(i = 0; i < 49 && numberWasUsed[i]; i++) {}
      if(numberWasUsed[i]) { // all numbers were used
	cout << "Yes" << endl;
      } else { // a number wasn't used
	cout << "No" << endl;
      }
      //reset for next round of input
      for(i = 0; i < 49; i++) {
	numberWasUsed[i] = false;
      }
    } else { //input was 0
      notQuit = false;
    }
  }
}
