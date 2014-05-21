#include <iostream> // string, cin, & cout
#include <cmath> //sqrt & abs
using namespace std;


bool * connected = new bool[1000];
int * sameLineCities = new int[1000];
struct City {
  int x;
  int y;
};

int distance(City c1, City c2) {
  return sqrt(abs((c1.x * c1.x) - (c2.x * c2.x)) + abs((c1.y * c1.y) - (c2.y * c2.y)));
}

bool allConnected(int numOfCities) {
  for(int i = 0; i < numOfCities) {
    if(!connected[i]) return false;
  }
  return true;
}

int minimumCable (int numOfCities, City * cities) {
  int cableLength = 0;
  bool first = true;

  while(!allConnected(numOfCities)) {
    int lowestY = 9001;
    int numInLine = 0;
    for(int i = 0; i < numOfCities; i++) {
      if(cities[i].y < lowestY && !connected[i]) {
	lowestY = cities[i].y;
      }
    }
    for(int i = 0; i < numOfCities; i++) {
      if(cities[i].y == lowestY) {
        sameLineCities[ numInLine++ ] = i;
      }
    }
    if(first) {
      first = false;
      for(int i = 0; i < numInLine; i++) {
	connected[sameLineCities[i]] = true;

      }
      
    } else {
      cableLength += connectCities( cities, numOfCities, numInLine);
    }
  }
  return cableLength;
}

int connectCities (City * cities, int numOfCities, int numInLine) {
  int minDistance, minCity;
  int totalDistance = 0;

  for(int i = 0; i < numInLine; i++) {
    minDistance = 9001;
    for(int j = 0; j < numInLine; j++) {
      if(!connected[ sameLineCities[j] ]) {
	for(int k = 0; k < numOfCities; k++) {
	  if(connected[k] && (minDistance > distance(cities[k], cities[sameLineCities[j]]) ) ) { 
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

/** 
 * FOR THE GLORY OF CARTESIA!
 */
int main() {
  int temp;
  int numOfCities;
  bool quit = false;
  City * cities;
  cities = new City[1000];
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
      cout << minimumCable(numOfCities, cities) << endl;

    } else { // numOfCities == 0

      quit = true;

    }
  }
}

