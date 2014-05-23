#include <iostream> // string, cin, & cout
#include <cmath> //sqrt & abs
#include <cstdio>
#include <cfloat>
using namespace std;


bool * connected;
int * sameLineCities;

struct City {
  int x;
  int y;
};

City * cities;

double distance(City c1, City c2) {
  return sqrt(abs((c1.x - c2.x) * (c1.x - c2.x)) + abs((c1.y - c2.y) * (c1.y - c2.y)));
}

bool allConnected(int numOfCities) {
  for(int i = 0; i < numOfCities; i++) {
    if(!connected[i]) return false;
  }
  return true;
}


double connectCities (int numOfCities, int numInLine) {
  int minCity, i, j, k;
  double minDistance, totalDistance = 0;

  for(i = 0; i < numInLine; i++) {
    minDistance = 1000000;
    minCity = 0;
    for(j = 0; j < numInLine; j++) {
      if(!connected[ sameLineCities[j] ]) {
	for(k = 0; k < numOfCities; k++) {
	  if(connected[k] & ( minDistance > distance( cities[k] , cities[ sameLineCities[j] ] ) ) ) { 
	    minDistance = distance(cities[k], cities[sameLineCities[j]]);
	    minCity = sameLineCities[j];
	  }
	}
      }
    }
    if(minDistance != 1000000){
      totalDistance += minDistance;
      connected[minCity] = true;
    }
  }
  return totalDistance;
}

double minimumCable (int numOfCities) {
  bool first = true;
  int lowestY, numInLine, i, j;
  double cableLength = 0;
  double maxInitialDistance = 0;


  while(!allConnected(numOfCities)) {
    lowestY = 9001;
    numInLine = 0;
    for(i = 0; i < numOfCities; i++) {
      // cout << i <<" : " << cities[i].y << endl;
      if(cities[i].y < lowestY && !connected[i]) {
	lowestY = cities[i].y;
      }
    }
    // cout << lowestY << endl;
    for(i = 0; i < numOfCities; i++) {
      if(cities[i].y == lowestY) {
        sameLineCities[ numInLine++ ] = i;
      }
    }
    if(first) {
      first = false;
      for(i = 0; i < numInLine; i++) {
	// cout << sameLineCities[i] << endl;
	connected[sameLineCities[i]] = true;
	for(j = i+1; j < numInLine; j++) {
	  // cout << "Distance between cities: " << distance(cities[sameLineCities[i]], cities[sameLineCities[j]]) << endl;
	  if(maxInitialDistance < distance(cities[ sameLineCities[i]], cities[ sameLineCities[j]])) {
	    maxInitialDistance = distance(cities[ sameLineCities[i]], cities[ sameLineCities[j]]);
	  }
	}
      }
      // cout << "Initial Distance: " << maxInitialDistance << endl;
      cableLength = maxInitialDistance;
    } else {
      cableLength += connectCities( numOfCities, numInLine);
    }
  }
  return cableLength;
}


/** 
 * FOR THE GLORY OF CARTESIA!
 */
int main() {
  int temp, numOfCities;
  bool quit = false;
  cities = new City[1000];
  connected = new bool[1000];
  sameLineCities = new int[1000];

  while(!quit) {
    cin >> numOfCities;
    if (numOfCities == 1) { 
      cin >> temp;
      cin >> temp;
      printf("%.2f\n", (float) 0);
    } else if(numOfCities) { // numOfCities != 0
      
      for(int i = 0; i < numOfCities*2; i++) {

	if(i%2) { // Y
	  connected[i/2] = false;
	  cin >> cities[i/2].y;
	  
	} else { // X
	  
	  cin >> cities[i/2].x;
	  
	}
      }
      printf("%.2f\n", minimumCable(numOfCities));
    } else { // numOfCities == 0
      quit = true;
    }
  }
}
