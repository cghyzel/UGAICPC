#include <iostream>

/* Kruskals algorithm directly results in the minimum spanning tree */


/** copied from Wikipedia 
 * KRUSKAL(G):
 * 1 A = ∅
 * 2 foreach v ∈ G.V:
 * 3   MAKE-SET(v)
 * 4 foreach (u, v) ordered by weight(u, v), increasing:
 * 5    if FIND-SET(u) ≠ FIND-SET(v):
 * 6       A = A ∪ {(u, v)}
 * 7       UNION(u, v)
 * 8 return A
 * 
 * Edges and nodes are represented using find-union
 */
struct edge 
{
  int x; // index of vertex
  int y; // index of vertix
  int distance; //distance between edges
};

edge edges [250];
int used [250];
int set [200];

bool operator<(const edge & e1, const edge & e2) 
{
  return (e1.distance < e2.distance);
}

// finds which set Node a belongs to
int findSet(int a) 
{
  int pset[200];
  int pc = 0; //counter
  while(a != find[a]) {
    pset[pc] = a;
    pc++;
    a = find[a];
  }
  while(pc) {
    pc--;
    set[ pset[pc] ] = a; //join nodes with set a
  }
  return a;
} 

int minimumSpanningTree() {
  int i, x, y;
  // n is the number of vertices
  for(i = 0; i < n; i++) { 
    set[i]=i;
  }
  int edgeNum = 0;
  for(i = 0; i < n -1; i++) {
    x = findSet( edges[i].x);
    y = findSet( edges[i].y);
    if(x != y) {
      used[i] = 1; // edge is used
      set[x] = y; // x joins y's set
      edgeNum++;
    }
    else 
      used[i] = 0;
  }
  if(edgeNum == n-1) return 1; //success
  else return 0; //fail
  
}

// now just pass in a sorted list of edges and you are done!
