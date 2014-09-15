#include <iostream>

using namespace std;

int buyCandy(int calories[], int cost[], int n, int money);
/**
 * similar to knapsack problem
 * subset sum with multiple supplies
 */
int main() {
  int n, money =0;
  int calories [5000] = {};
  int cost [5000] = {};
  double mDouble;
  cin >> n >> mDouble;
  while(n != 0 || mDouble != 0) {
    money = (int) (mDouble * 100.0); // map to integer space
    for(int i = 0; i < n; ++i) {
      cin >> calories[i] >> mDouble;
      cost[i] = (int) (mDouble * 100.0); // map to integer space
    }
    cout << buyCandy(calories, cost, n, money) << endl;
    cin >> n >> mDouble;
  }
}

int buyCandy(int calories[], int cost[], int n, int money) {
  int *  maxCals = new int [money +1];
  int i, j, tmp;
  // i = 0 is zero by default
  for( i = 1; i <= money; ++i) {
    maxCals[i] = maxCals[i-1];

    for(j=0; j<n; j++) {
      if(i >= cost[j]) {
	tmp = maxCals[i - cost[j]] + calories[j];
	if(tmp > maxCals[i]) {
	  maxCals[i] = tmp;
	}
      }
    }
  }
  tmp = maxCals[money];
  delete [] maxCals;
  return tmp;
}
