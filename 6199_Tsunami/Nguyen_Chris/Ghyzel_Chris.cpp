#include <iostream> // string, cin, & cout
#include <cmath> //sqrt & abs
#include <cstdio> //printf
#include <cfloat>
using namespace std;

/* Global variables */

bool * connected; //tracks which cities are connected
int * sameLineCities; //tracks cities in the same line

struct City {
  int x;
  int y;
};

City * cities;

/* Returns the distance between two cities */
double distance(City c1, City c2) {
  return sqrt(abs((c1.x - c2.x) * (c1.x - c2.x)) + abs((c1.y - c2.y) * (c1.y - c2.y)));
}

/* Returns true if all cities are connected */
bool allConnected(int numOfCities) {
  for(int i = 0; i < numOfCities; i++) {
    if(!connected[i]) return false;
  }
  return true;
}

/* Connects all of the cities with the same Y and returns the minimum amount of cable required */
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
/* Calculates the minimum cable required to connect all the cities */
double minimumCable (int numOfCities) {
  bool first = true;
  int lowestY, numInLine, i, j;
  double cableLength = 0;
  double maxInitialDistance = 0;
  
  while(!allConnected(numOfCities)) {
    lowestY = 9001;
    numInLine = 0;
    /* Find smallest y value of the unconnected cities*/
    for(i = 0; i < numOfCities; i++) {
      if(cities[i].y < lowestY & !connected[i] ) {
	lowestY = cities[i].y;
      }
    }
    /* Track all of the cities in the same line with the lowest value */
    for(i = 0; i < numOfCities; i++) {
      if(cities[i].y == lowestY) {
        sameLineCities[ numInLine++ ] = i;
      }
    }
    /* If it is the first set of cities, then just connect them all across the X axis */
    if(first) {
      first = false;
      for(i = 0; i < numInLine; i++) {
	connected[sameLineCities[i]] = true;
	for(j = i+1; j < numInLine; j++) {
	  if(maxInitialDistance < distance(cities[ sameLineCities[i]], cities[ sameLineCities[j]])) {
	    maxInitialDistance = distance(cities[ sameLineCities[i]], cities[ sameLineCities[j]]);
	  }
	}
      }
      cableLength = maxInitialDistance;
    } else {
      /* Connect the line of cities */
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
  double answers[1000];
  int index = 0;

  while(!quit) {
    cin >> numOfCities;
    if (numOfCities == 1) { 
      cin >> temp;
      cin >> temp;
      answers[index++] = 0;
      //      printf("%.2f\n", (float) 0);
    } else if(numOfCities) { // numOfCities != 0
      
      for(int i = 0; i < numOfCities*2; i++) {

	if(i%2) { // Y
	  connected[i/2] = false;
	  cin >> cities[i/2].y;
	  
	} else { // X
	  
	  cin >> cities[i/2].x;
	  
	}
      }
      answers[index++] = minimumCable(numOfCities);
      //      printf("%.2f\n", minimumCable(numOfCities));
    } else { // numOfCities == 0
      for (int k=0; k<index; ++k) {
	printf("%.2f\n", answers[k]);
      }
      quit = true;
    }
  }
}
