#include <iostream>

using namespace std;

int grid [4][100][100][2];
// 0 N
// 1 W
// 2 S
// 3 E
void printGrid(int rows, int cols);
void constructGrid(int rows, int cols);
int main() {
  int rows, cols, i , j, targetRow, targetCol, count, min;

  char c;
  cin >> rows >> cols;
  while(rows || cols) {
    for(i = 0; i < rows; i++) { // build grid
      for(j = 0; j < cols; j++) {
	cin >> c;
	grid[0][i][j][1] = 0;
	grid[1][i][j][1] = 0;
	grid[2][i][j][1] = 0;
	grid[3][i][j][1] = 0;
	switch(c) {
	case '.':
	  grid[0][i][j][0] = 99999999;
	  grid[1][i][j][0] = 99999999;
	  grid[2][i][j][0] = 99999999;
	  grid[3][i][j][0] = 99999999;
	  break;
	case '*':
	  grid[0][i][j][0] = -1;
	  grid[1][i][j][0] = -1;
	  grid[2][i][j][0] = -1;
	  grid[3][i][j][0] = -1;
	  break;
	case 'X':
	  targetRow = i;
	  targetCol = j;
	  grid[0][i][j][0] = -2;
	  grid[1][i][j][0] = -2;
	  grid[2][i][j][0] = -2;
	  grid[3][i][j][0] = -2;
	  break;
	case 'N':
	  grid[0][i][j][1] = 1;
	  grid[0][i][j][0] = 0;
	  grid[1][i][j][0] = 99999999;
	  grid[2][i][j][0] = 99999999;
	  grid[3][i][j][0] = 99999999;
	  break;
	case 'W':
	  grid[1][i][j][1] = 1;
	  grid[0][i][j][0] = 99999999; 
	  grid[1][i][j][0] = 0;
	  grid[2][i][j][0] = 99999999;
	  grid[3][i][j][0] = 99999999;
	  break;
	case 'S':
	  grid[2][i][j][1] = 1;
	  grid[0][i][j][0] = 99999999; 
	  grid[1][i][j][0] = 99999999;
	  grid[2][i][j][0] = 0;
	  grid[3][i][j][0] = 99999999;
	  break;
	case 'E':
	  grid[3][i][j][1] = 1;
	  grid[0][i][j][0] = 99999999; 
	  grid[1][i][j][0] = 99999999;
	  grid[2][i][j][0] = 99999999;
	  grid[3][i][j][0] = 0;
	  break;
	}
      }    
    }
    //    printGrid(rows, cols);
    constructGrid(rows, cols);
    //    printGrid(rows, cols);
    count = 0;
    min = 0;
    if(grid[0][targetRow][targetCol][0] != -2) {// N
      min = grid[0][targetRow][targetCol][0];
      count+= grid[0][targetRow][targetCol][1];
    }
    if(grid[1][targetRow][targetCol][0] != -2) { // W
      min = grid[1][targetRow][targetCol][0];
      count+= grid[1][targetRow][targetCol][1];
    }
    if(grid[2][targetRow][targetCol][0] != -2) { // S
      min = grid[2][targetRow][targetCol][0];
      count+= grid[2][targetRow][targetCol][1];
    }
    if(grid[3][targetRow][targetCol][0] != -2) { //E
      min = grid[3][targetRow][targetCol][0];
      count+= grid[3][targetRow][targetCol][1];
    }
    
    cout << min << " " << count % 1000000 << endl;
    cin >> rows >> cols;
  }
}
void constructGrid(int rows, int cols)  {
  int instrNum, d, i, j, k, temp;
  bool obstacle;
  bool targetReached = false;
  bool canMove = true;
  for(instrNum = 0; canMove && !targetReached; instrNum++) {
    canMove = false;
    for(d = 0; d < 4; d++) {
      for(i = 0; i < rows; i++) {
	for(j = 0; j < cols; j++) {
	  if(grid[d][i][j][0] == instrNum) {
	    canMove = true;
	    //issue instructions
	    //turn
	    if(d == 0) {
	      if(grid[3][i][j][0] > instrNum) {
		grid[3][i][j][0] = instrNum + 1;
		grid[3][i][j][1] += grid[0][i][j][1];
		temp = grid[3][i][j][1];
		grid[3][i][j][1] = temp % 1000000;
	      }
	    } else {
	      if(grid[((d -1)% 4)][i][j][0] > instrNum) {
		grid[((d -1) %4)][i][j][0] = instrNum + 1;
		grid[((d -1) %4)][i][j][1] += grid[d][i][j][1];
		temp = grid[((d -1) %4)][i][j][1];
		grid[((d -1) %4)][i][j][1] = temp % 1000000;
	      }
	    }
	    if(grid[((d +1)%4)][i][j][0] > instrNum) {
	      grid[((d +1)%4)][i][j][0] = instrNum + 1;
	      grid[((d +1) %4)][i][j][1] += grid[d][i][j][1];
	      temp = grid[((d +1) %4)][i][j][1];
	      grid[((d +1) %4)][i][j][1] =  temp % 1000000;
	    }
	    //move
	    obstacle = false;
	    switch(d)  {
	    case 0: //N
	      for(k = i; k > -1 && !obstacle; k--) {
		if(grid[0][k][j][0] == -1) {
		  obstacle = true;
		}
		if(grid[0][k][j][0] == -2) {
		  targetReached = true;
		  grid[0][k][j][0] = instrNum + 1;
		  grid[0][k][j][1] += grid[0][i][j][1];
		  temp = grid[0][k][j][1];
		  grid[0][k][j][1] = temp % 1000000;
		}
		else if(grid[0][k][j][0] > instrNum) {
		  grid[0][k][j][0] = instrNum + 1;
		  grid[0][k][j][1] += grid[0][i][j][1];
		  temp = grid[0][k][j][1];
		  grid[0][k][j][1] = temp % 1000000;
		}
	      }
	      break;
	    case 1: // W
	      for(k = j; k > -1 && !obstacle; k--) {
		if(grid[1][i][k][0] == -1) {
		  obstacle = true;
		}
		if(grid[1][i][k][0] == -2) {
		  targetReached = true;
		  grid[1][i][k][0] = instrNum + 1;
		  grid[1][i][k][1] += grid[1][i][j][1];
		  temp = grid[1][i][k][1];
		  grid[1][i][k][1] = temp % 1000000;
		}
		else if(grid[1][i][k][0] > instrNum) {
		  grid[1][i][k][0] = instrNum + 1;
		  grid[1][i][k][1] += grid[1][i][j][1];
		  temp = grid[1][i][k][1];
		  grid[1][i][k][1] = temp % 1000000;
		}
	      }
	      break;
	    case 2: // S
	      for(k = i; k < rows && !obstacle; k++) {
		if(grid[2][k][j][0] == -1) {
		  obstacle = true;
		}
		if(grid[2][k][j][0] == -2) {
		  targetReached = true;
		  grid[2][k][j][0] = instrNum + 1;
		  grid[2][k][j][1] += grid[2][i][j][1];
		  temp = grid[2][k][j][1];
		  grid[2][k][j][1] = temp % 1000000;
		}
		else if(grid[2][k][j][0] > instrNum) {
		  grid[2][k][j][0] = instrNum + 1;
		  grid[2][k][j][1] += grid[2][i][j][1];
		  temp = grid[2][k][j][1];
		  grid[2][k][j][1] = temp % 1000000;
		}
	      }
	      break;
	    case 3: // E
	      for(k = j; k < cols && !obstacle; k++) {
		if(grid[3][i][k][0] == -1) {
		  obstacle = true;
		}
		if(grid[3][i][k][0] == -2) {
		  targetReached = true;
		  grid[3][i][k][0] = instrNum + 1;
		  grid[3][i][k][1] += grid[3][i][j][1];
		  temp = grid[3][i][k][1];
		  grid[3][i][k][1] = temp % 1000000;
		}
		else if(grid[3][i][k][0] > instrNum) {
		  grid[3][i][k][0] = instrNum + 1;
		  grid[3][i][k][1] += grid[3][i][j][1];
		  temp = grid[3][i][k][1];
		  grid[3][i][k][1] = temp % 1000000;
		}
	      }
	      break; 
	    }
	  }
	}
      }
    }
  }
}
void printGrid(int rows, int cols) {
  int i, j, d;
  for(d = 0; d < 4; d++) {
    switch(d) {
    case 0:
      cout << 'N';
      break;
    case 1: 
      cout << 'W';
      break;
    case 2:
      cout << 'S';
      break;
    case 3:
      cout << 'E';
      break;
      }
    cout << endl;
    for(i = 0; i < rows; i++) {
      for(j = 0; j < cols; j++) {
	cout << grid[d][i][j][0] << " ";
      }
      cout << endl;
    }
  }
}
