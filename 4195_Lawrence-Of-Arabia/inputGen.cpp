#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  for(int i = 0; i < 1000; i++) {
    int n = rand() % 1001;
    int bombs = 0;
    if(n -1  > 0) 
      bombs = rand() % (n-1);
    cout << n << " " << bombs << endl;
    for(int i = 0; i < n; i++) {
      cout << (rand() % 4) + 1 << " ";
    }
    cout << endl;
  }
  cout << 0 << " " << 0 << endl;
  return 0;
}
