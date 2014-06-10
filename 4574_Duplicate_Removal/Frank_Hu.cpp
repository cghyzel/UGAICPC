/*
 * DuplicateRemoval.cpp
 *
 *  Created on: Jun 10, 2014
 *      Author: Frank Hu
 */

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int clicks;
	cin >> clicks;
	while ((clicks)) {
		int oranges[clicks];
		for (int i = 0; i < clicks; i++) {
			cin >> oranges[i];
			if (oranges[i - 1] == oranges[i]) {
				i -= 1;
				clicks -= 1;
			}
		}
		for (int i = 0; i < clicks; i++) {
			cout << oranges[i] << " ";
		}
		cout << "$" << "\n";
		cin >> clicks;
	}
	return 0;
}
