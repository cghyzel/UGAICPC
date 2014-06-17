#include <iostream> 

using namespace std;

bool connected[999] {true};
int depots [1000] {0};
int minStrategicValue, numDepots;
int calculateStrategicValue() {
  int strategicValue= 0;
  //  cout << "Calculating Strategic value" << endl;
  /*  for(int i = 0; i < numDepots; i++) {
    cout << depots[i];
    if(i < numDepots -1) {
      if(connected[i]) {
	cout << " - ";
      } else {
	cout << " x ";
      }
    }
  }
  cout << endl; */
  for(int i = 0; i < numDepots; i++) {
    for(int j = i; j < numDepots - 1 && connected[j]; j++) {
      
      strategicValue += depots[i] * depots[j+1];
    }
  }
  //  cout << "Calculated Strategic value: " << strategicValue << endl;
  return strategicValue;
}
void bomb(int loc, int bombs)  {
  int temp = loc;
  //  cout << "Bombs Remaining: " << bombs << endl;
  if(!bombs) {
    temp = calculateStrategicValue();
    if( temp < minStrategicValue) {
      minStrategicValue = temp;
    }
  } else if(bombs == ((numDepots -1) - loc) ) {
    //    cout << "bombing remaining " << endl;
    while(temp < numDepots -1) {
      connected[temp++] = false;
    }
    if((temp = calculateStrategicValue()) < minStrategicValue) {
      minStrategicValue = temp;
    }
    temp = loc;
    while(temp < numDepots -1) {
      connected[temp++] = true;
    }
  } else {
    connected[loc] = true;
    bomb(loc + 1, bombs);
    connected[loc] = false;
    bomb(loc + 1, bombs -1);
    connected[loc] = true;
  }
}
int main() {
  int i, bombs;
  cin >> numDepots >> bombs;
  while(numDepots || bombs) { // n != 0
    //    cout << "Number of Depots: " << numDepots << endl;
    //    cout << "Number of bombs: " << bombs << endl;
    for(i = 0; i < numDepots; i++) {
      cin >> depots[i];
    }
    for(i = 0; i < numDepots -1; i++) {
      connected[i] = true;
    }
    minStrategicValue = 9999999;
    bomb(0, bombs);
    cout << minStrategicValue << endl;
    cin >> numDepots >> bombs;
  }
}
