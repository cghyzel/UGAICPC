#include <iostream>
#include <cmath>
using namespace std;


int charAsNum(char a);
void pushButtons(bool entered [], int cursor, int cost);
int name [18]; 
int nameLen;
int minPushes;


int main()  {
  int i;
  bool entered [18];
  string nameStr;
  cin >> nameStr;
  while(nameStr != "0") {
    nameLen = nameStr.length();
    for(i = 0; i < nameLen; i++) {
      name[i] = charAsNum(nameStr.at(i));
      entered[i] = false;
    }
    minPushes = 999999;
    pushButtons(entered, 0, 0);
    cout << minPushes << endl;;

    cin >> nameStr;
  }
}

void pushButtons(bool entered [], int cursor, int cost) {
  int i, j;
  if(cost >= minPushes) {
    return;
  }
  //base case
  for(i = 0; i < nameLen; i++) {
    if(!entered[i])
      break;
  }
  // if we have put in all the letters
  if(i == nameLen) {
    minPushes = cost;
  }
  /* c = cursor
   *     A L M A
   * i   0 1 2 3
   * c  0 1 2 3 4
   * 
   * c 0 for completed ALMA
   * | A L M A
   * c 1
   * A | L M A
   */

  if(cursor == 0) {
    for(i = 0; i < nameLen; i++) {
      entered[i] = true;
      pushButtons(entered, i+1, name[i] +1);
      entered[i] = false;
    }
  } else {
    for(i = 0; i < nameLen; i++) {
      if(!entered[i]) {
	//calculate cost at i
	int localCost = 1; // one for firing
	int activeLetter = name[cursor-1];
	//Calculate upDownCost
	int upDownCost = min(abs(activeLetter-name[i]), (26 - abs(activeLetter-name[i])));
	
	//Calculate cost of moving cursor left or right
	int leftRightCost = 0;
	if(cursor > i) { // left
	  for(j = cursor-1; j > i; j--) {
	    if(entered[j]) {
	      leftRightCost++;
	    }
	  }
	} else { // right
	  for(j = cursor; j < i; j++) {
	    if(entered[j]) {
	      leftRightCost++;
	    }
	  }
	}
	localCost+= leftRightCost + upDownCost;
	entered[i] = true;
	pushButtons(entered, i+1, cost + localCost);
	entered[i] = false;
      }
    }
  }
}

int charAsNum(char a) {
  switch(a) {
  case 'A':
      return 0;
  case 'B':
      return 1;
    
  case 'C':
      return 2;
    
  case 'D':
      return 3;
    
  case 'E':
      return 4;
    
  case 'F':
      return 5;

  case 'G':
      return 6;

  case 'H':
      return 7;

  case 'I':
      return 8;

  case 'J':
      return 9;

  case 'K':
      return 10;
  case 'L':
      return 11;
    
  case 'M':
      return 12;

  case 'N':
      return 13;
    
  case 'O':
      return 14;

  case 'P':
      return 15;

  case 'Q':
      return 16;

  case 'R':
      return 17;

  case 'S':
      return 18;

  case 'T':
      return 19;

  case 'U':
      return 20;

  case 'V':
      return 21;

  case 'W':
      return 22;

  case 'X':
      return 23;

  case 'Y':
      return 24;

  case 'Z':
      return 25;
  }
  return -1;
}
