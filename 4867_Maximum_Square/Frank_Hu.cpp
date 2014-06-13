/*
 * MaximumSquare.cpp
 *
 *  Created on: May 27, 2014
 *      Author: Frank Hu
 */

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int row, col;
int square[1000][1000];
int board[1000][1000];

int main() {
	bool s = true;
	cin >> row;
	cin >> col;
	while (((row) && (col))) {

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> square[i][j];
			}

		}

		int largestSquareSize = 0;
		for (int i = row - 1; i >= 0; i--) {
			for (int j = col - 1; j >= 0; j--) {

				if (square[i][j] == 1) {
					if (j == col - 1 || i == row - 1) {
						board[i][j] = 1;
					} else {
						int s = min(board[i + 1][j], board[i][j + 1]);
						int k = min(s, board[i + 1][j + 1]);
						board[i][j] = k + 1;
					}
					if (board[i][j] > largestSquareSize) {
						largestSquareSize = board[i][j];
					}
				} else
					board[i][j] = 0;

			}
		}

		cout << largestSquareSize;
		cout << "\n";
		cin >> row;
		cin >> col;
	}
}
