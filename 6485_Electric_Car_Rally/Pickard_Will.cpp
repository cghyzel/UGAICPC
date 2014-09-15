#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

//define the indicies for a station to anoter station
#define START 0
#define STOP 1
#define ELAPSED 2


using namespace std;
struct Station;
struct Path;
struct Course;
//station 1 has paths to stations 2 and 3
struct Path{
	int a, b;
	int times[3];
};
//station 1 is a station
struct Station{
	vector<Path *> paths;	
	int id;
};

//course contains stations 1-3
struct Course{
	Station stations[];
	int numStations;
	int numPaths;
};

int toInt(string c);
Station * makeStations(int num);

int main(int argc, char* argv[]){
	if(argc != 2) exit(1);
	
	string line;
	ifstream file (argv[1]);
	if(!file.is_open()) exit(1);
	
	while(getline(file, line)){
		//create the course
		struct Course course;
		course.numStations = toInt(line[0]);
		course.numPaths = toInt(line[2]); 
		course.stations[course.numStations];
		
		//init all stations on the course
		for(int i=0; i<course.numStations; i++){	
			struct Station station;
			station.id = i;
			//station.paths = new vector<Path *>;
			course.stations[i] = station;
		}
		//create paths and and those paths to stations
		int thisStationId, otherStationId;
		for(int i=0; i<course.numStations; i++){
			struct Path path;
			getline(file, line);
			
			isstringstream iss(line);
			string tSI, oSI;
			iss >> tSI;
			iss >> oSI;	
			//line is of form "x y" |where x and y are ints| and |x = y = someStationId| 
			thisStationId = toInt(tSI);
			otherStationId = toInt(oSI);	

			path.a = thisStationId;
			path.b = otherStationId;				
			
			int totalElapsed = 0; //must be 1439 - indicating end of this stations paths
		//	while(totalElapsed != 1439){
				getline(file, line);
				
				istringstream iss(line);
				string start, stop, elapsed;
				iss >> start;
				iss >> stop;
				iss >> elapsed;
				//line is now of form "start stop elapsed"
				cout << "line: " << line << endl;
				path.times[START] = toInt(start);
				path.times[STOP] = toInt(stop);
				path.times[ELAPSED] = toInt(elapsed);
				totalElapsed += path.times[STOP]; 			

				cout << path.times[START] << " " << path.times[STOP] << " "  << path.times[ELAPSED] << endl;	
		//	}
			cout << "test0" << endl;
			course.stations[i].paths.push_back(&path);
			cout << "test1" << endl;
			for(int j=0; j<course.stations[i].paths.size(); j++){
				cout << "Path-- " << endl;
				cout << "from: " << course.stations[i].paths.at(j)->a << endl;
				cout << "to: " << course.stations[i].paths.at(j)->b << endl;
				cout << "start: " << course.stations[i].paths.at(j)->times[START] << endl;
				cout << "stop: " << course.stations[i].paths.at(j)->times[STOP] << endl;
				cout << "elapsed: " << course.stations[i].paths.at(j)->times[ELAPSED] << endl;
			}
		}
	}
	
}
/*
Station * makeStations(int num){
	struct Station stationSize;
	struct Station temp = malloc((num * sizeof(&stationSize)));
	
	return (*temp);
}*/
int toInt(char c){
	return c - '0';
}
