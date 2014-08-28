#include <iostream>

using namespace std;

void whichSatellites(string input) {
  bool pings [1001];
  int len = input.length();
  for(int i = 0; i < len; ++i) {
    switch (input[i]) {
    case '1':
      pings[i] = true;
      break;
    case '0':
      pings[i] = false;
      break;
    }
  }
  for(int i = 1; i < len; ++i) {
    //    cout << "Initial value:" << pings[i] << endl;
    if(pings[i]) {
      for(int j = i+i; j < len; j+=i) {
	pings[j] = true^pings[j];
      }
    }
  }
  int last = 0;
  for( int i = len -1; i > 0; --i) {
    if(pings[i]) {
      last = i;
      break;
    }
  }
  for(int i = 1; i < last; ++i) {
    if( pings[i] ) {
      cout << i << " ";
    }
  }
  if(last != 0) {
    cout << last << endl;  
  }
}
int main() {
  string line;
  cin >> line;
  while(!(line == "0")) {
    whichSatellites(line);
    cin >> line;
  }
}

