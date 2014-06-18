#include <iostream>
using namespace std;

int minimizeDmg(int n, int k);

int main() {
   int n; // number of depots
   int k; // number of attacks
   while (cin >> n >> k) {
      if (n == 0 && k == 0) exit(0); // end of input
      cout << minimizeDmg(n, k) << endl; // print answers
   }
   return 0;
} // main

int minimizeDmg(int n, int k) {
   // read inputs
   int depots[n];
   for (int i = 0; i < n; ++i) {
      cin >> depots[i];
   }
   
   // initialize the damages
   int damages[n-1][n];
   for (int i = 0; i < n-1; ++i) {
      for (int j = i+1; j < n; ++j) {
         damages[i][j] = depots[i] * depots[j];
      }
   }
   
   bool isBombed[n-1]; // remember which depot has been bombed
   int stratValue[n-1][2]; // determine where to attack each round
   int sum, bombIndex, min;
   while (--k >= 0) {
      /*
       Sample Input (You should verify yourself that my answer matches yours)
       n = 5, k = 2
       [ 1 | 4 | 5 | 1 | 2 ]
       
       0 |   | 4 | 5 | 1 | 2 |
       1 |   |   | 20| 4 | 8 |
       2 |   |   |   | 5 | 10|
       3 |   |   |   |   | 2 |
       4 |___|___|___|___|___| // this row is ignore
           0   1   2   3   4
       
       stratValue for attack #1
       | 0  | 49 |
       | 4  | 17 |
       | 29 | 2  |
       | 39 | 0  |
       
       stratValue for attack #2
       | 0  | 17 |
       | x  | x  | // will be given some arbitrarily large value
       | 4  | 2  |
       | 9  | 0  |
       
       Answer = 6
       */
      
      // set the strategic value of every position
      sum = 0;
      for (int i = 0; i < n-1; ++i) {
         if (isBombed[i]) { // already bombed
            stratValue[i][0] = 123456789;
            stratValue[i][1] = 123456789;
         } else {
            for (int j = 0; j < i; ++j) { // left side
               for (int k = j+1; k <= i; ++k) {
                  if (damages[j][k] == 0) break;
                  sum += damages[j][k];
               }
            }
            stratValue[i][0] = sum;
            sum = 0;
            
            for (int j = i+1; j < n-1; ++j) { // right side
               for (int k = j+1; k < n; ++k) {
                  if (damages[j][k] == 0) break;
                  sum += damages[j][k];
               }
            }
            stratValue[i][1] = sum;
            sum = 0;
         } // if
         
         // determine where to bomb
         if (i == 0) {
            min = stratValue[0][0] + stratValue[0][1];
            bombIndex = 0;
         } else if (stratValue[i][0] + stratValue[i][1] < min) {
            min = stratValue[i][0] + stratValue[i][1];
            bombIndex = i;
         }
      } // for
      
      // zeroing out depots that do not cause a threat anymore
      isBombed[bombIndex] = true;
      for (int i = 0; i <= bombIndex; ++i) {
         for (int j = bombIndex+1; j < n; ++j) {
            if (damages[i][j] == 0) break;
            damages[i][j] = 0;
         }
      }
   } // while
   
   int answer = 0;
   for (int i = 0; i < n-1; ++i) {
      for (int j = i+1; j < n; ++j) {
         if (damages[i][j] == 0) break;
         answer += damages[i][j];
      }
   }
   return answer;
} // minimizeDmg

/*
 Sample Inputs
 
 4 1
 4 5 1 2
 4 2
 4 5 1 2
 5 2
 1 4 5 1 2
 7 6
 1 3 1 4 5 1 2
 7 2
 5 5 5 5 5 5 5
 1000 900
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7 
 7 7 7 7 7 7 7 7 7 7 
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7 
 
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 7 7 7 7 7 7 7 7 7 7
 0 0
*/
