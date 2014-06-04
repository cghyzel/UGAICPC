#include <iostream> 
#include <vector>
using namespace std;


/**
 * Author: Christopher Ghyzel
 * Solution for 4867 Profits
 * Another simple one. This solution is O(n). 
 * I iterate throught the profits in reverse
 * and calculate if a section is worth keeping based on whether or not it is negative
 * meanwhile detecting the size of the profits
 */
int main() {
  int i = 0, n = 0, maxProfits =-9999999, tmp=0;
  int profits [250000] = {0};  
  cin >> n;
  while(n) {
    maxProfits =-9999999;
    tmp = 0;
    for(i = 0; i < n; i++) {
      cin >> profits[i];
    }
    for(i = n - 1; i > -1; i--) {
      tmp += profits[i];
      if(tmp > maxProfits) {
	maxProfits = tmp;
      } 
      if(tmp < 0) {
        tmp = 0;
      } 
    }
    cout << maxProfits << endl;
    cin >> n;
  }
}
