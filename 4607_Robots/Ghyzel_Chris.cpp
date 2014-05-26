#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
struct Target {
  int x;
  int y;
  int penalty;
};
// Candidate set
Target * targets;
int numOfTargets;
int currentX;
int currentY;
int minIndex;
//feasibility tracking
int previousTarget;

double distanceFromCurrent(int target) {
  return sqrt(((currentX - targets[target].x) * (currentX - targets[target].x)) + ((currentY - targets[target].y) * (currentY - targets[target].y)));
}
double distanceToEnd(int target) {
  return sqrt(((100 - targets[target].x) * (100 - targets[target].x)) + ((100 - targets[target].y) * (100 - targets[target].y)));
}
/*
 * evalutes the total penalty to get to the end
 */
double timeToEnd() {
  double endTime = 1 + sqrt(((currentX - 100) * (currentX - 100)) + ((currentY - 100) * (currentY - 100)));
  for(int i = previousTarget+1; i < numOfTargets; i++) {
    endTime += targets[i].penalty;
    //    cout << targets[i].penalty;
  }
  return endTime;
}
/*
 * evaluates the local penalty for each target
 */
double totalPenalty(int target) {
  //1 second stop
  double penalty = 1; 
  //add the penalty for all targets before it 
  for(int i = previousTarget+1; i < target; i++) {
    penalty += targets[i].penalty;
  }
  penalty += distanceFromCurrent(target);
  penalty += distanceToEnd(target);
  return penalty;
}

/*
 * Selection function
 * Returns double with the minimum time penalty
 */
double selectTarget() {
  double minPenalty = 99999999;
  
  //  cout << "Beginning selection" << endl;
  for(int i = previousTarget+1; i < numOfTargets; i++) {
    //cout << i << ": " << totalPenalty(i) << endl;
    if(minPenalty >= totalPenalty(i)) {
       minPenalty = totalPenalty(i);
      minIndex = i;
    }
  }
  
  //cout << minIndex;
  return minPenalty;
}
/*
 * Traverse the course
 * Returns total time
 */
double traverseCourse() {
  bool notFinished = true;
  double totalTime = 0;
  double lowestTimeToATarget;
  while(notFinished) {
    lowestTimeToATarget = selectTarget();

    if(lowestTimeToATarget >= timeToEnd()) {
      //cout << timeToEnd() << " yatta!" <<  endl; 
      totalTime += timeToEnd();
      notFinished = false;
    }
    else {
      //cout << lowestTimeToATarget << endl;
      totalTime+=lowestTimeToATarget;
      totalTime-=distanceToEnd(minIndex);
      previousTarget = minIndex;
      currentX = targets[previousTarget].x;
      currentY = targets[previousTarget].y;
    }
  }
  return totalTime;
}
int main() {
  double solution;

  bool quit = false;
  targets = new Target[1000];

  while (!quit) {
    /* Set up */
    previousTarget = -1;
    currentX = 0;
    currentY = 0;
    cin >> numOfTargets;
    
    if (numOfTargets) { // numOfTargets != 0
      
      for(int i = 0; i < numOfTargets*3; i++) {
	
	if(i%3 == 1) { //Y

	  cin >> targets[i/3].y;
      
	} else if (i % 3) { // Penalty

	  cin >> targets[i/3].penalty;
	  //	  cout << "\nX: " << targets[i/3].x << " Y: "  << targets[i/3].y << "P: "<< targets[i/3].penalty << endl;
	} else { // X
	  
	  cin >> targets[i/3].x;
	  
	}
      }
      solution = traverseCourse();
      solution = round( solution * 1000.0 ) / 1000.0;
      
      printf("%.3f\n", solution);
    } else { // numOfTargets == 0
      quit = true;
    }
  }
}
