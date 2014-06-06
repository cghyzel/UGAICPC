#include <iostream>
using namespace std;

int calcProfit();

int profits[250000];
int numDays = 0;

int main() {
    do {
        cin >> numDays;
        if (numDays == 0) return 0;
        for (int i = 0; i < numDays; ++i) cin >> profits[i];
        cout << calcProfit() << endl;
    } while (1);
} // main

int calcProfit() {
    int totalProfit = 0;
    int maxProfit = -250000001; // 250000 * -100 + 1
    for (int i = numDays-1; i >=0; --i) {
        totalProfit += profits[i];
        if (totalProfit > maxProfit) maxProfit = totalProfit;
        if (totalProfit < 0) totalProfit = 0;
    }
    return maxProfit;
} // calcProfit