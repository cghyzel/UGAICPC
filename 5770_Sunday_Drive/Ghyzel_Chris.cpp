#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int numSegments, numLanes;
double  minDist [1001][10]; // Minimum distances to get to a lane
/**
 * Segment representation
 * 0 - Straight
 * 1 - Left
 * 2 - Right
 */
int main() {
  char c;
  int i, j, k, distanceFromRadius, radius, distance;
  cin >> numSegments >> numLanes;
  for( i = 0; i < 10; ++i){
    minDist[0][i] = 0;
  }

  while(numSegments || numLanes) {    
    for(i = 1; i < numSegments +1; ++i) {
      cin >> c;
      switch(c) {
      case 'S':
	cin >> distance;
	for(j = 0; j < numLanes; ++j) {
	  minDist[i][j] = minDist[i-1][j] + distance;
	    for(k = 0; k < numLanes; ++k) {
	      if(j - k != 0 && (distance / abs(j-k)) > 99) { 
		if(minDist[i][j] > minDist[i-1][k] + sqrt(distance*distance + (j - k)*10*(j - k)*10)) {
		  minDist[i][j] = minDist[i-1][k] + sqrt(distance*distance + (j - k)*10*(j - k)*10);
	    }
	      }
	    
	  }
	    //	  cout << minDist[i][j] << endl;	  
	}
	break;
      case  'L':
	cin >> radius;
	distanceFromRadius = 5;
	for(j = 0; j < numLanes; ++j) {
	  minDist[i][j] = minDist[i-1][j] + (M_PI*(radius + distanceFromRadius)/2);
	  distanceFromRadius += 10;
	  //cout << minDist[i][j] << endl;	  
	}
	
	break;
      case 'R':
	cin >> radius;
	distanceFromRadius = 5;
	for(j = numLanes -1; j > -1; --j) {
	  minDist[i][j] = minDist[i-1][j] + (M_PI*(radius + distanceFromRadius)/2);
	  
	  distanceFromRadius += 10;
	  //cout << minDist[i][j] << endl;	  
	}

	break;
      }
	
    }
    double min = minDist[numSegments][0];
    for(i = 1; i < numLanes; ++i) {
      if(minDist[numSegments][i] < min) {
	min = minDist[numSegments][i];
      }
    }
    cout << fixed << setprecision (2);
    cout << ceil(min* 100) /100 << endl;
    cin >> numSegments >> numLanes;
  }
}
