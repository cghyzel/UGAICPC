/*
  Chris Nguyen
  May 25, 2014
  
  Goal: Numbers in range of [1, 49] (brackets mean inclusive) must be seen from inputs.
  Input: numLines indicate how many lines of inputs are given.
         There are 6 numbers given on each line.
 */

#include <iostream>
using namespace std;

int main () {
  int size = 49;
  int numLines = 0;
  int index = 0;

  do {
    bool nums[49] = {false}; // entire array initialized to false
    cin >> numLines; // 6 integers per line

    if (numLines == 0) exit(0);

    if (numLines < 9) { // input size not big enough (6 numbers per line so need at least 9 lines to get 49 numbers)
      for (int i = 0; i < numLines * 6; i += 1) cin >> index; // reading and throwing away inputs
      cout << "No" << endl;
      continue;
    }

    for (int i = 0; i < numLines * 6; i +=1) { // input size is big enough
      cin >> index;
      nums[index-1] = true; // checks a number off if it is seen
    }

    for (int i = 0; i < size; i+=1) { // checks if every number [1,49] is seen
      if (nums[i] == false) {
	cout << "No" << endl; // number was not seen
	break;
      } else if (i == 48 && nums[i] == true) cout << "Yes" << endl; // every number seen
    }
  } while (1);
}
