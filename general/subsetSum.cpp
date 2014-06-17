/*
 * Generalized version of subset sum problem
 * "Given a set of n numbers ai sum up to M, and any K ≤ M, 
 * whether there is a subset of the numbers such that they sum 
 * up to (hit) K? We assume n might be as big as 1000, but M or K is not too big"
 */
#include <iostream>

using namespace std;

int main() {

  int a [6];
  int n = 6; //number of number in a
  int M = 0;
  cout << "A: { ";
  for(int i = 0; i < n; i++) {
    M+= a[i] = i * 2;
    cout << a[i] << " ";
  }
  cout << "}" << endl;
  int m [M + 10]; //is there a subset in Ato sum to this number?  
  for(int i = 0; i < M +10; i++) {
    m[i]=0;
  }
  m[0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = M; j >=a[i]; j--) {
      m[j] |= m[j-a[i]]; //bitwise or assignment
    }
  }
  for(int i = 0; i < M; i++) { 
    cout << i << ": " << m[i] << endl;
  }
}
