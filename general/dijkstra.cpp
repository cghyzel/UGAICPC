#include <iostream>
#include <vector>
#include <map>
#define N 100 //Maximum number of nodes
using namespace std;

/* Dijkstra in O(nlog(n)) - works for any graph with non-negative weights */

/* https://www.youtube.com/watch?v=gdmfOwyQlcI */


typedef double weight; //int ?  
int n;  // n nodes
vector<int> rel [N + 10]; //rel[i][j]; the j-th neighbor of i
vector<weight> edge [N + 10]; // edge[i][j]; the length of edge i -> r[i][j] 
weight dist [N + 10]; //minimum distance from initial node
int previouslyAccessed [N + 10]; //previously accessed node for minimum path to node i is previouslyAccess[i]
multimap<weight, int> h; // (candidate distance, node id)
 
void init() {
  int i;
  cin >> n; //read in number nodes
  for(i = 0; i < n; i++) {
    rel[i].clear();
    edge[i].clear();
  }
  /* read graph */
  
  for(i = 0; i < n; i++) {
    dist[i] = -1; // represent infinite cost with -1
  }
}

// in the tree h <weight, int> : <candidate distance, node id>
void dijsktra(int start) {
  weight distance, temp;
  int currentNode, i, j;
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
	previouslyAccessed[j] = currentNode;
	h.insert(multimap<weight, int>::value_type(temp, j));
      } 
    }
  }
}

