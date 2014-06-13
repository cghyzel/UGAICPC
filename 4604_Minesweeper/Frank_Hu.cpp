/*s
 * MineSweeper.cpp
 *
 *  Created on: Jun 10, 2014
 *      Author: Frank Hu
 */

#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	int row;
	int col;
	cin >> row;
	cin >> col;
	while (((row) && (col))) {
		int square[row][col];
		bool mines[row][col];
		char temp = 'z';
		for (int i = 0; i < row; i++) {
			for (int k = 0; k < col; k++) {
				cin >> temp;
				if (temp == '*') {
					mines[i][k] = true;
				} else
					mines[i][k] = false;
				square[i][k] = 0;
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (mines[i][j])
					for (int k = i - 1; k <= i + 1; k++) {
						for (int o = j - 1; o <= j + 1; o++) {
							if (k >= 0 && o >= 0 && k < row && o < col)
								square[k][o] = square[k][o] + 1;
						}
					}
			}
		}

		for (int i = 0; i < row; i++) {
			for (int k = 0; k < col; k++) {
				if (!mines[i][k])
					cout << square[i][k];
				else
					cout << "*";
			}
			cout << "\n";
		}
		cin >> row;
		cin >> col;
		if (row == 0 && col == 0)
			return 0;
	}

}

/* namespace std */
