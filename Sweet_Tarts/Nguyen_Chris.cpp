/*
 0 and 1
 June 19, 2014
 
 Given prefence from greatest to least of 4 candies A, B, C, D and a roll of candy,
 determine the maximum score from eating the roll of candy. A score for eating any
 piece of candy is the turn it was eaten on multiply to the preference for that candy.
 */

#include <iostream>
#include <vector>
using namespace std;

int maxScore();

int n; // number of candy
char first, second, third, fourth; // preference level
vector<int> roll;

int main() {
   while (cin >> n) {
      if (n == 0) return 0; // end of input
      cin >> first >> second >> third >> fourth; // read in preferences
      char temp;
      for (int i = 0; i < n; ++i) { // read in the order of the candy
         cin >> temp;
         if (temp == first) roll.push_back(4);
         else if (temp == second) roll.push_back(3);
         else if (temp == third) roll.push_back(2);
         else roll.push_back(1);
      }
      cout << maxScore() << endl; // output answer
      roll.clear();
   }
} // main


int maxScore() {
   int scores[n][n];
   int turn;
   for (int i = 0; i < n; ++i) {
      for (int j = i; j >= 0; --j) {
         turn = n - (i-j);
         if (i == j) { // 1 candy
            scores[i][j] = turn * roll[i];
         } else {
            scores[i][j] = max(turn*roll[j] + scores[i][j+1], turn*roll[i] + scores[i-1][j]);
         }
      }
   }
   return scores[n-1][0];
} // maxScore
