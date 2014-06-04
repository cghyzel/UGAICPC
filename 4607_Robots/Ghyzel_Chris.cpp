#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>

using namespace std;


/**
 * Example solution with dijkstras.
 * Does not work within time limit, but a good example of how to build a graph for dijkstras nonetheless.
 */
typedef long double weight; //int ?  
int n;  // n nodes
vector<int> rel [1002]; //rel[i][j]; the j-th neighbor of i
vector<weight> edge [1002]; // edge[i][j]; the length of edge i -> r[i][j] 
weight dist [1002]; //minimum distance from initial node
int previouslyAccessed [1002]; //previously accessed node for minimum path to node i is previouslyAccess[i]
multimap<weight, int> h; // (candidate distance, node id)

struct target {
  int x;
  int y;
  int p; //penalty
};

vector<target> targets;

/* Calculate distance between nodes i and j */
weight calculateTimeCost(int i, int j) {
  int a;
  weight total = 1 + sqrt(((targets[i].x - targets[j].x) * (targets[i].x - targets[j].x)) + ((targets[i].y - targets[j].y) * (targets[i].y - targets[j].y)));
  // Calculate penalty incurred 
  for(a = i + 1; a < j; a++) {
    total += targets[a].p;
  }
  cout << "Node: " << i << " Node: " <<  j << " Total: " << total << endl;
  return total;
}

void init(int n) {
  int i = 0, j = 0;
  weight calculatedTimeCost = 0;
  target temp;
  //clear memory
  targets.clear();
  for(i = 0; i < n+2; i++) {
    rel[i].clear();
    edge[i].clear();
  }
  /* read graph */
  temp.x = 0;
  temp.y = 0;
  temp.p = 0;
  targets.push_back(temp);
  for(i = 0; i < (n); i++) {
    cin >> temp.x;
    cin >> temp.y;
    cin >> temp.p;
    targets.push_back(temp);
  }
  temp.x = 100;
  temp.y = 100;
  temp.p = 1;
  targets.push_back(temp);

  /* Calculate edges and relationships */
  for(i = 0; i < n + 2; i++) {
    for(j = i + 1; j < n + 2; j++) {
      calculatedTimeCost = calculateTimeCost(i, j);
      //     if(calculatedTimeCost < 8000) {
	rel[i].push_back(j);
	edge[i].push_back(calculatedTimeCost);
	//      } else {
	//	j = n + 2;
	//      }
    }
  }
  
  for(i = 0; i < n+2; i++) {
    dist[i] = -1; // represent infinite cost with -1
  }
}

// in the tree h <weight, int> : <candidate distance, node id>
void dijsktra(int start) {
  weight distance =0, temp =0;
  int currentNode =0, i =0, j =0;
  multimap<weight, int>::iterator iter;
  h.clear();
  dist[start] = 0;
  previouslyAccessed[start] = -1; //start has nothing previously accessed
  h.insert(multimap<weight, int>::value_type(0, start));
  while(!h.empty()) {
    iter = h.begin();
    distance = (*iter).first; // the distance
    currentNode = (*iter).second; // the node
    h.erase(iter);
    for(i = 0; i< rel[currentNode].size(); i++) { //for each neighbor of v
      temp = distance + edge[currentNode][i];
      j = rel[currentNode][i]; 
      if(dist[j] < 0 || temp < dist[j]) {
	dist[j] = temp;
	//	cout << "Distance to node " << j << ":" << temp << endl;
	previouslyAccessed[j] = currentNode;
	h.insert(multimap<weight, int>::value_type(temp, j));
      } 
    }
  }
}

int main() {
  int n;
  weight temp;
  cin >> n;
  while(n) {
    init(n);
    dijsktra(0);
    // round number 

    temp = round( dist[n+1] * 1000.0 ) / 1000.0;
    cout << " Solution: " << fixed << setprecision(3) << temp << endl;
    cin >> n;
  }
}
