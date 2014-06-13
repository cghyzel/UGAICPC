// I'M PRETTTTYY SURE THIS IS RIGHT
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

// Literally got this from RosettaCode.org
void distribute(int dist, vector<int> &List) {
	//*beads* go down into different buckets using gravity (addition).
	if (dist > List.size())
		List.resize(dist); //resize if too big for current vector

	for (int i = 0; i < dist; i++)
		List[i]++;
}

int main() {
	// List is the list input

	// We take in all the pills and put them into a list.

	int numberOfPills;
	cin >> numberOfPills;
	while ((numberOfPills)) {

		vector<int> list, abacusPillsSorted, abacusPillsInEachRow;
		list.push_back(numberOfPills);
		while (true) {
			if (numberOfPills != 0)
				cin >> numberOfPills;
			else
				break;
			list.push_back(numberOfPills);
		}

		for (int i = 0; i < list.size(); i++) {
			distribute(list[i], abacusPillsSorted);
		}
		int totalBeads = 0;
		for (int i = list.size() - 2; i > 0; i--) {
			if (list[i - 1] > list[i]) {
				totalBeads = totalBeads + (list[i - 1] - list[i]);
				list[i - 1] = list[i - 1] - (list[i - 1] - list[i]);

				list[i] = list[i] + (list[i - 1] - list[i]);

			}
		}

		int dist = 0;

		for (int i = 0; i < abacusPillsSorted.size(); i++) {
			distribute(abacusPillsSorted[i], abacusPillsInEachRow);
		}
		for (int i = 0; i < abacusPillsInEachRow.size(); i++) {
			if (abacusPillsInEachRow[i] > dist) {
				dist = abacusPillsInEachRow[i];
			}
		}
		for (int i = abacusPillsInEachRow.size() - 1; i >= 0; i--) {
			int j = 0;
			while (abacusPillsInEachRow[i] > j) {
				cout << "X";
				j++;
			}

			while (dist > j) {
				j++;
				cout << "-";
			}

			cout << " > " << abacusPillsInEachRow[i] << endl;
		}
		cout << "A total of " << totalBeads << " beads slid during the sort.\n";
		cin >> numberOfPills;
	}
	return 0;
}
