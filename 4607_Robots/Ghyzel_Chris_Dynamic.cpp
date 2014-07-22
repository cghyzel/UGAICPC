#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;


int n;  // n nodes

typedef long double weight;
weight minDistToEnd [1002];
struct target {
  int x;
  int y;
  int p; //penalty
};


vector<target> targets;

/* Calculate distance between nodes i and j */
weight calculateTimeCost(int i, int j) {
  int a;
  weight total = 1+ sqrt(((targets[i].x - targets[j].x) * (targets[i].x - targets[j].x)) + ((targets[i].y - targets[j].y) * (targets[i].y - targets[j].y)));
  // Calculate penalty incurred 
  total +=  targets[j-1].p - targets[i].p;
  //cout << i << " " << j << " : " << total << endl;
  return total;
}

void init(int n);
void build(int n);
void printMinDistToEnd(int n);
int main() {
  int n;
  weight temp;
  cin >> n;
  while(n) {
    init(n);
    build(n);
    //printMinDistToEnd(n);
    temp = minDistToEnd[0];
    cout << fixed << setprecision(3) << temp << endl;
    cin >> n;
  }
}
void printMinDistToEnd(int n) {
  for(int i = 0; i < n+2; i++) {
    cout << i << " : " << minDistToEnd[i] << endl;
  }
}
void build(int n) {
  weight cost = 0;
  int j;
  for(int i = n+1; i > -1; --i) {
    for(j = i+1; j < n+2; ++j) {
      if(j == i+1) {
	cost = calculateTimeCost(i, j) + minDistToEnd[j];
	//cout << i << " " << j << " : " <<cost << endl;
      } else if(cost > (calculateTimeCost(i, j) + minDistToEnd[j])) {
	cost = calculateTimeCost(i, j) + minDistToEnd[j] ;
	//cout << i << " " << j << " : " <<cost << endl;
      }
    }
    minDistToEnd[i] = cost;
  }
}


void init(int n) {
  int penalty;
  targets.clear();
  target temp;
  temp.x = 0; 
  temp.y = 0;
  temp.p = 0;
  targets.push_back(temp);
  for(int i = 0; i < n; ++i) {
    cin >> temp.x >> temp.y >> penalty;
    temp.p = penalty + targets[i].p;
    targets.push_back(temp);
  }
  temp.x = 100;
  temp.y = 100;
  temp.p = targets[n].p;
  targets.push_back(temp);
}
