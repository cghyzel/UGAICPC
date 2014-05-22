#include <iostream> // string, cin, & cout
#include <cmath> //sqrt & abs

using namespace std;


bool * connected;
int * sameLineCities;

struct City {
  int x;
  int y;
};

City * cities;

int distance(City c1, City c2) {
  return (int) sqrt(abs((c1.x - c2.x) * (c2.x - c1.x)) + abs((c1.y - c2.y) * (c2.y - c1.y)));
}

bool allConnected(int numOfCities) {
  for(int i = 0; i < numOfCities; i++) {
    if(!connected[i]) return false;
  }
  return true;
}


int connectCities (int numOfCities, int numInLine) {
  int minCity, i, j, k;
  int minDistance, totalDistance = 0;

  for(i = 0; i < numInLine; i++) {
    minDistance = 9001;
    for(j = 0; j < numInLine; j++) {
      if(!connected[ sameLineCities[j] ]) {
	for(k = 0; k < numOfCities; k++) {
	  if(connected[k] && (minDistance > distance( cities[k] , cities[ sameLineCities[j] ] ) ) ) { 
	    minDistance = distance(cities[k], cities[sameLineCities[j]]);
	    minCity = sameLineCities[j];
	  }
	}
      }
    }
    totalDistance += minDistance;
    connected[minCity] = true;
  }
}

int minimumCable (int numOfCities) {
  int maxInitialDistance, cableLength = 0;
  bool first = true;
  int lowestY, numInLine, i, j;

  while(!allConnected(numOfCities)) {
    lowestY = 9001;
    numInLine = 0;
    for(i = 0; i < numOfCities; i++) {
      if(cities[i].y < lowestY && !connected[i]) {
	lowestY = cities[i].y;
      }
    }
    for(i = 0; i < numOfCities; i++) {
      if(cities[i].y == lowestY) {
        sameLineCities[ numInLine++ ] = i;
      }
    }
    if(first) {
      first = false;
      for(i = 0; i < numInLine; i++) {
	connected[sameLineCities[i]] = true;
	for(j = i; j < numInLine; j++) {
	  if(maxInitialDistance < distance(cities[(int) sameLineCities[i]], cities[ (int) sameLineCities[j]])) {
	    maxInitialDistance = distance(cities[ (int) sameLineCities[i]], cities[ (int) sameLineCities[j]]);
	  }
	}
      }
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
  //  City * array = new City[3];
  while(!quit) {
    cin >> numOfCities;
    if (numOfCities) { // numOfCities != 0

      for(int i = 0; i < numOfCities*2; i++) {

	if(i%2) { // X
	  connected[i/2] = false;
	  cin >> cities[i/2].x;
	  
	} else { // Y
	  
	  cin >> cities[i/2].y;
	  
	}
      }
      cout << minimumCable(numOfCities) << endl;

    } else { // numOfCities == 0

      quit = true;

    }
  }
}
