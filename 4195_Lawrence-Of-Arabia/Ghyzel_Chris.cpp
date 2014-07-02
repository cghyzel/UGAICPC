#include <iostream>

using namespace std;

int * depots;
int ***costs;

int cost0(int begin, int end);
int cost(int begin, int end, int bomb);

int main() {
  int n = 0, m = 0, i = 0, j = 0, k = 0;
  //  int *depots;
  depots = new int[1000];
  //  int ***costs;// [101]; //[1001][1000];

  costs = new int**[1001];
  for (i = 0; i < 1001; ++i) {
    costs[i] = new int*[1001];
    for (j = 0; j < 1001; ++j) {
      costs[i][j] = new int[1000];
    }
  }

  //    cout << " done" << endl;

  while(  cin >> n >> m) {
    if (n == 0 && m == 0) return 0;
    for(i = 0; i < n+1; ++i) {
      if(i != n)
	cin >> depots[i];
      for(j = 0; j < n+1; ++j) {
	for(k = 0; k < m+1; ++k) {
	  costs[i][j][k] = -1;
	}
      }
    }
    //    cout << " done" << endl;
    cout << cost(0, n-1, m) << endl;
    //cin >> n >> m;
  }
  return 0;
}


int cost0(int begin, int end) {
  int total = 0;
  int i, j;
  for(i = begin; i < end+1; ++i) {
    for(j = i + 1; j < end+1; ++j) {
      total+=depots[i]*depots[j];
    }
  }
  return total;
}
int cost(int begin, int end, int bomb) {
  if(costs[begin][end][bomb] > -1) {
    return costs[begin][end][bomb];
  }
  if(bomb == 0) {
    //cout << "begin " << begin << " end " << end << " bomb " << bomb << " cost " << cost(begin, end) << endl;
    return (costs[begin][end][bomb] = cost0(begin, end));
  }
  int min = 999999999;
  int temp;
  for(int i = begin; i <  end - bomb; ++i) {
    temp = (cost(begin, i, 0) + cost(i + 1, end, bomb -1));
    if(min > temp) {
      min = temp;
    }
  }
  //cout << "begin " << begin << " end " << end << " bomb " << bomb << " cost " << min << endl;
  return (costs[begin][end][bomb] = min);
 

}
