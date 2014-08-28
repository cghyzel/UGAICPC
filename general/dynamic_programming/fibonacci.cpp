#include <iostream>

using namespace std;

long fibonacci(long n);

int main() {
  //cout << fibonacci(20) << endl;
  // cout << fibonacci(50) << endl; 
  // is too slow fibonacci(50) 
  // instead build dynamically
  // remember what we did
  // lets build the fibonacci sequence from the bottom up to answer the same question
  long  fibonacci [51];
  for(long i = 0; i <= 50; ++i) {
     switch(i) {
     case 0:
       fibonacci[i] = 0;
       break;
     case 1:
       fibonacci[i] = 1;
       break;
     default: //otherwise
       fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
       break;
     } 
  }
  cout << fibonacci[50] << endl;
}

long fibonacci(long n) {
  switch(n) {
  case 0:
    return 0;
    break;
  case 1:
    return 1;
    break;
  default: //otherwise
    return fibonacci(n-1) + fibonacci(n-2);
    break;
  }
 
}
