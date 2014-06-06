#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;


/*
 * Solution to 4863 Balloons
 * Author: Christopher Ghyzel
 * Chooses which team to give balloons to 
 * based on the difference between
 * the Distance from A and Distance from B.
 * A priority queue automatically puts the teams
 * with the highest difference at the top of the stack
 * so they are popped and greedily take what balloons they neeed
 */
struct Team {
  int k; //Number of balloons required
  int DA; //Distance from A
  int DB; //Distance from B
};
/* 
 * Compare Teams by the size of their penalty
 * penalty = | DistanceA - DistanceB |
 * Teams with higher penalties have a higher priority
 */
struct TeamCompare {
  bool operator()(const Team &t1, const Team &t2) const
  {
    int t1penalty = abs(t1.DA - t1.DB);
    int t2penalty = abs(t2.DA - t2.DB);
    return t1penalty < t2penalty;
  }
};

int main() {
  int n, i, k, balloonsA, balloonsB, cost;
  Team team;
  priority_queue<Team, vector<Team>, TeamCompare> teams;
  cin >> n >> balloonsA >> balloonsB;
  while(n || balloonsA || balloonsB) {
    cost = 0;
    for(i = 0; i < n; i++) {
      cin >> team.k >> team.DA >> team.DB;
      teams.push(team);
    }
    while(!teams.empty()) {
      team = teams.top();
      k = team.k;
      if(team.DA - team.DB < 0) { // Prefer A	
	if(balloonsA) {
	  if(balloonsA > k) {
	    cost+= k*team.DA;
	    balloonsA -= k;
	  } else {
	    cost+= balloonsA*team.DA;
	    k -= balloonsA;
	    balloonsA = 0;
	    cost+= k*team.DB;
	    balloonsB -= k;
	  }
	} else { // no need to check because of the guarantee there are enough balloons
	  cost+= k*team.DB;
	  balloonsB -= k;
	}
      } else { // Prefer B
	if(balloonsB) {
	  if(balloonsB > k) {
	    cost+= k*team.DB;
	    balloonsB -= k;
	  } else {
	    cost+= balloonsB*team.DB;
	    k -= balloonsB;
	    balloonsB = 0;
	    cost+= k*team.DA;
	    balloonsA -= k;
	  }
	} else {
	  cost+= k*team.DA;
	  balloonsA -= k;
	}
      }
      teams.pop();
    } //while teams haven't gotten balloons
    cout << cost << endl;
    cin >> n >> balloonsA >> balloonsB;
  } //while not three 0's
}
