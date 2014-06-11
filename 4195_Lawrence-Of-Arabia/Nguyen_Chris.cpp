#include <iostream>
using namespace std;

int calcDamage(int railroads, int attacks);

int * arr;
int ** damage; // 2D array holding the damage between each station
bool * bombed; //

int main() {
   int railroads; // number of railroads
   int attacks; // number of attacks
   do {
      cin >> railroads >> attacks;
      if (railroads == 0 && attacks == 0) return 0;
      cout << calcDamage(railroads, attacks) << endl;
   } while (1);
} // main

int calcDamage(int railroads, int attacks) {
   bombed = new bool[railroads-1];
   for (int i = 0; i < railroads-1; ++i) bombed[i] = false;
   
   arr = new int[railroads];
   for (int i = 0; i < railroads; ++i) cin >> arr[i];
   
   damage = new int * [railroads];
   for (int i = 0; i < railroads; ++i) {
      damage[i] = new int[railroads];
      for (int j = i+1; j < railroads; ++j) damage[i][j] = arr[i] * arr[j];
   }
   
   while (--attacks >= 0) {
      int bombIndex = 0;
      int max = -1;
      int tempDamage;
      
      for (int i = 0; i < railroads-1; ++i) {
         if (bombed[i] != true) {
            tempDamage = 0;
            for (int j = i+1; j < railroads; ++j) {
               tempDamage += damage[i][j];
               if (bombed[j]) {
                  if (tempDamage > max) {
                     bombIndex = i;
                     max = tempDamage;
                  }
                  break; // everything else is set to zero
               }
            } // j
            if (tempDamage > max) {
               bombIndex = i;
               max = tempDamage;
            }
         } // if
      } // i

      bombed[bombIndex] = true;
      for (int j = 0; j <= bombIndex; ++j)
         for (int k = bombIndex+1; k < railroads; ++k) damage[j][k] = 0;

/*
      cout << "attack: " << attacks << endl;
      for (int i = 0; i < railroads-1; ++i) {
         for (int j = i+1; j < railroads; ++j) cout << damage[i][j] << " ";
         cout << "\n";
      }
*/
   } // while
   
   int totalDamage = 0; // holds the remaining damage
   for (int i = 0; i < railroads - 1; ++i) {
      for (int j = i+1; j < railroads; ++j) {
         if (bombed[i] != true) {
            totalDamage += damage[i][j];
         }
      }
   }
   return totalDamage;
} // calcDamage

/*
 Sample Inputs
 
 4 1
 4 5 1 2
 4 2
 4 5 1 2
 5 2
 1 4 5 1 2
 7 3
 1 3 1 4 5 1 2
 0 0

 */
