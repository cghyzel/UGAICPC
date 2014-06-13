#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

// Literally got this from RosettaCode.org
void distribute(int dist, vector<int> &List) {

  // So, what this is doing is finding the largest distance if the current 
  // vector is too small for the distance. The distance passed in is the value of the amount of beads
  // in vector[i] where i is the element you wish to pass in.
	if (dist > List.size())
		List.resize(dist); //resize if too big for current vector


  // For loop, running from 0 to the element passed in,
  // This adds 1 to every element from 0- the distance, generating a sort of
  // "Gravity effect", where the beads are like falling down, 
	for (int i = 0; i < dist; i++)
		List[i]++;
}

int main(){

  int beadAmounts[] = { 2,4 ,1 ,3 ,3,30 ,40 ,40 ,20 };
  vector <int> list, actualAmountOfBeadsInEachRow;
  
  // We distribute 2 to list(0) and list(1), and then we add one for each element along the list for however many beads
  // there are in beadAmounts[i], simulating the gravity effect,
    for (int i=0; i < 9; i++)
        distribute (beadAmounts[i], list);

  // print out to see if it's sorted, 
    for(int i =0; i<9; i++){
        cout << list[i] << ", ";    
    }
    // You can then do it again, in order to find the amount of beads that are actually in each row,
    for (int i=0; i < 9; i++)
        distribute (list[i], actualAmountOfBeadsInEachRow);
    
    // This will print out the beads in each row,
    for(int i =0; i<9; i++){
        cout << actualAmountOfBeadsInEachRow[i] << ", ";    
    }

    return 0;
}
