// DOesn't Work yet,d
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
struct railroad {
	int importance = 0;
};

int SplitArray(railroad* array, int pivotValue, int startIndex, int endIndex);
int SplitArray(railroad* array, int pivot, int startIndex, int endIndex) {
	int leftBoundary = startIndex;
	int rightBoundary = endIndex;

	while (leftBoundary < rightBoundary) //shuttle pivot until the boundaries meet
	{
		while (pivot < array[rightBoundary].importance //keep moving until a lesser element is found
		&& rightBoundary > leftBoundary) //or until the leftBoundary is reached
		{
			rightBoundary--; //move left
		}
		swap(array[leftBoundary], array[rightBoundary]);
		//PrintArray(array, ARRAY_SIZE);			 //Uncomment this line for study

		while (pivot >= array[leftBoundary].importance //keep moving until a greater or equal element is found
		&& leftBoundary < rightBoundary) //or until the rightBoundary is reached
		{
			leftBoundary++; //move right
		}
		swap(array[rightBoundary], array[leftBoundary]);
		//PrintArray(array, ARRAY_SIZE);			 //Uncomment this line for study
	}
	return leftBoundary; //leftBoundary is the split point because
						 //the above while loop exits only when
						 //leftBoundary and rightBoundary are equal
}

void QuickSort(railroad* array, int startIndex, int endIndex) {
	int pivot = array[startIndex].importance; //pivot element is the leftmost element
	int splitPoint;

	if (endIndex > startIndex) //if they are equal, it means there is
							   //only one element and quicksort's job
							   //here is finished
			{
		splitPoint = SplitArray(array, pivot, startIndex, endIndex);
		//SplitArray() returns the position where
		//pivot belongs to
		array[splitPoint].importance = pivot;
		QuickSort(array, startIndex, splitPoint - 1); //Quick sort first half
		QuickSort(array, splitPoint + 1, endIndex); //Quick sort second half
	}
}
/*
 * Compare Teams by the size of their penalty
 * penalty = | DistanceA - DistanceB |
 * Teams with higher penalties have a higher priority
 */
struct TeamCompare {
	bool operator()(const railroad &t1, const railroad &t2) const {
		if (t1.importance < t2.importance) {
			return true;
		}
		return false;
	}
};

int main() {
	int attacks, railroads;

	railroads = 1;
	cin >> railroads;
	cin >> attacks;
	struct railroad railroad[railroads];
	int newArray[railroads];
	for (int i = 0; i < railroads; i++) {
		cin >> railroad[i].importance;
	}
	for(int i =0; i< railroads; i++)
	newArray[i] = railroad[i].importance;

	for (int i = 0; i < railroads; i++) {
		for (int j = 0; j < railroads; j++) {
			if (i != j)
				railroad[i].importance *= railroad[j].importance;
		}
	}

	QuickSort(railroad, 0, railroads - 1);
	int total = 0;
	for (int i = 0; i < railroads; i++) {
		total += railroad[i].importance;
	}
	for (int i = railroads - 1; i >= 0; i--) {
		total -= railroad[i].importance;
		for (int j = 0; j < railroads; j++) {
			railroad[j].importance = railroad[j].importance
					- (newArray[i] * newArray[j]);
		}
		railroads -= 1;
	}
	cout << total;

//while not three 0's
}
