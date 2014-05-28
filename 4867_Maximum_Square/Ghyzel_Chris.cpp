#include <iostream>

using namespace std;

int matrix [1000][1000] = {0};
int rows, cols;

/*
 * Author: Christopher Ghyzel
 * Very simple and inefficient solution to Maximum Square.
 * Almost embarassingly slow, I'm near the worst of those that solved the problem.
 * It has a good potential for pruning where it checks for a square -
 * could return the i and j of the detected 0 and have
 * the main method respond accordingly.
 */
int checkForSquare(int x, int y, int length) {
  int i, j;
  for(i = x; i - x < length; i++) {
    for(j = y; j - y < length; j++) {
      if(!matrix[i][j]) {
	return 0;
      }
    }
  }
  return 1;
}

int main() {
  int max, product, i, j, temp, length, realLen;

  cin >> rows;
  cin >> cols;
  while((rows) && (cols)) {
    //    cout << "Rows: " << rows << " Cols: " << cols << endl;
    product = rows*cols;
    //    cout << endl << "Number " << product << endl;
    max = 0;
    for(i = 0; i < rows; i++) {
      for(j= 0; j < cols; j++) {
	cin >> matrix[i][j];
      }
    }
    //    cout << "Finished taking input" << endl;
    for(i = 0; i < (rows - max + 1); i++) {
      for(j = 0; j < (cols - max + 1); j++) {
	//cout << "I: " << i << "J: " << j;
	realLen = length = max;
	while((rows - (length) - i > 0) && (cols - (length) - j > 0) && checkForSquare(i, j, ++length)) {
	  realLen++;
	}
	max = realLen;
	//	cout << " Max: " << max << endl;
      }
    }
	  
    cout << max << endl;
    cin >> rows;
    cin >> cols;
  }
}
