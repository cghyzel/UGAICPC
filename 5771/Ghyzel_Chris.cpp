#include <iostream>

using namespace std;

int buildHex(int index);
  
/* Global Variables */
// Stores inputed numbers
int unordered[12];
// Ordered number in the order they fit into the hex
int ordered[12];
/**
 * Ordered numbers by index in hexagram
 * 
 *         9
 *        /  \
 *  0 -- 1 -- 2 -- 3
 *    \ /      \  /
 *    8          4
 *   /  \       /  \
 * 11 -- 7  -- 5 -- 10
 *        \   /
 *          6
 */
int total, lineSum;
// tracks which numbered have been used
bool unorderedTrack[12];
// tracks if the input has ended
bool notEnded;

int main() {
  //take in first input
  cin >> unordered[0]; 
  notEnded = (unordered[0] != 0);
  while(notEnded) {
    total = unordered[0];
    for(int i = 1; i < 12; i++) {
    cin >> unordered[i];
    total += unordered[i];
    }
    // No numbers are in ordered list
    for(int i = 0; i < 12; i++) {
      unorderedTrack[i] = false;
    }
    //Recursion begin!
    cout << buildHex(0)/12 << endl;
    // take in new line of input
    cin >> unordered[0]; 
    notEnded = (unordered[0] != 0);
  }
}

int buildHex(int index) {
  if(total%3 != 0) return 0;
  // check as lines are connected
  if(index == 4) {
    lineSum = ordered[0] + ordered[1] + ordered[2] + ordered[3];
    if(total / 3 != lineSum) { return 0; }
  } else if(index == 7) { 
    if(lineSum != (ordered[3] + ordered[4] + ordered[5] + ordered[6])) { return 0; }
  } else if(index == 9) {
    if(lineSum != (ordered[6] + ordered[7] + ordered[8] + ordered[0])) { return 0; }
   } else if(index == 11) {
    if(lineSum != (ordered[9] + ordered[2] + ordered[4] + ordered[10])) { return 0; }
  } else if(index == 12) {
    if(lineSum != (ordered[9] + ordered[1] + ordered[8] + ordered[11])) { return 0; }
    else if(lineSum != (ordered[11] + ordered[7] + ordered[5] + ordered[10])) { return 0; }
    else {
      return 1;
    }
  } 
  int numOfCombos = 0;
  for(int i = 0; i < 12; i++) {
    // if not filled
    if(!unorderedTrack[i]) {
      ordered[index] = unordered[i];
      unorderedTrack[i] = true;
      //new recursion at next index
      numOfCombos += buildHex(index + 1);
      unorderedTrack[i] = false;
    }
  }
  return numOfCombos;
}
