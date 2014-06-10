#include <iostream>
using namespace std;

int main() {
   int guesses, prev, curr;
   do {
      cin >> guesses;
      if (guesses == 0) return 0;
      cin >> curr;
      cout << curr << " ";
      prev = curr;
      for (int i = 1; i < guesses; ++i) {
         cin >> curr;
         if (curr != prev) {
            cout << curr << " ";
            prev = curr;
         } // if
      } // i
      cout << '$' << endl;
   } while (1);
} // main