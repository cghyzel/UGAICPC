#include <iostream>

using namespace std;

int grid [4][100][100];
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
	switch(c) {
	case '.':
	  grid[0][i][j] = 9999999;
	  grid[1][i][j] = 9999999;
	  grid[2][i][j] = 9999999;
	  grid[3][i][j] = 9999999;
	  break;
	case '*':
	  grid[0][i][j] = -1;
	  grid[1][i][j] = -1;
	  grid[2][i][j] = -1;
	  grid[3][i][j] = -1;
	  break;
	case 'X':
	  targetRow = i;
	  targetCol = j;
	  grid[0][i][j] = -2;
	  grid[1][i][j] = -2;
	  grid[2][i][j] = -2;
	  grid[3][i][j] = -2;
	  break;
	case 'N':
	  grid[0][i][j] = 0;
	  grid[1][i][j] = 9999999;
	  grid[2][i][j] = 9999999;
	  grid[3][i][j] = 9999999;
	  break;
	case 'W':
	  grid[0][i][j] = 9999999; 
	  grid[1][i][j] = 0;
	  grid[2][i][j] = 9999999;
	  grid[3][i][j] = 9999999;
	  break;
	case 'S':
	  grid[0][i][j] = 9999999; 
	  grid[1][i][j] = 9999999;
	  grid[2][i][j] = 0;
	  grid[3][i][j] = 9999999;
	  break;
	case 'E':
	  grid[0][i][j] = 9999999; 
	  grid[1][i][j] = 9999999;
	  grid[2][i][j] = 9999999;
	  grid[3][i][j] = 0;
	  break;
	}
      }    
    }
    //    printGrid(rows, cols);
    constructGrid(rows, cols);
    //    printGrid(rows, cols);
    count = 0;
    min = 0;
    if(grid[0][targetRow][targetCol] != -2) {// N
      min = grid[0][targetRow][targetCol];
      for(i = targetRow; i < rows; i++) {
	if(grid[0][i][targetCol] == -1) {
	  i = rows;
	}
	else if(grid[0][targetRow][targetCol]-1 == grid[0][i][targetCol]) {
	  ++count;
	}
      }
    }
    if(grid[1][targetRow][targetCol] != -2) { // W
      min = grid[1][targetRow][targetCol];
      for(i = targetCol; i < cols; i++) {
	if(grid[1][targetRow][i] == -1) {
	  i=cols;
	}
	else if(grid[1][targetRow][targetCol]-1 == grid[1][targetRow][i]) {
	  ++count;
	}
      }
    }
    if(grid[2][targetRow][targetCol] != -2) { // S
      min = grid[2][targetRow][targetCol];
      for(i = targetRow; i > -1; i--) {
	if(grid[2][i][targetCol] == -1) {
	  i = -1;
	}
	else if(grid[2][targetRow][targetCol]-1 == grid[2][i][targetCol]) {
	  ++count;
	}
      }
    }
    if(grid[3][targetRow][targetCol] != -2) { //E
      min = grid[3][targetRow][targetCol];
      for(i = targetCol; i > -1; i--) {
	if(grid[3][targetRow][i] == -1) {
	  i = -1;
	}
	else if(grid[3][targetRow][targetCol]-1 == grid[3][targetRow][i]) {
	  ++count;
	}
      }
    }
    cout << min << " " << count << endl;
    cin >> rows >> cols;
  }
}
void constructGrid(int rows, int cols)  {
  int instrNum, d, i, j, k;
  bool obstacle;
  bool targetReached = false;
  bool canMove = true;
  for(instrNum = 0; canMove && !targetReached; instrNum++) {
    canMove = false;
    for(d = 0; d < 4; d++) {
      for(i = 0; i < rows; i++) {
	for(j = 0; j < cols; j++) {
	  if(grid[d][i][j] == instrNum) {
	    canMove = true;
	    //issue instructions
	    //turn
	    if(d == 0) {
	      if(grid[3][i][j] > instrNum) {
		grid[3][i][j] = instrNum + 1;
	      }
	    } else {
	      if(grid[((d -1)% 4)][i][j] > instrNum) {
		grid[((d -1) %4)][i][j] = instrNum + 1;
	      }
	    }
	    if(grid[((d +1)%4)][i][j] > instrNum) {
	      grid[((d +1)%4)][i][j] = instrNum + 1;
	    }
	    //move
	    obstacle = false;
	    switch(d)  {
	    case 0: //N
	      for(k = i; k > -1 && !obstacle; k--) {
		if(grid[0][k][j] == -1) {
		  obstacle = true;
		}
		if(grid[0][k][j] == -2) {
		  targetReached = true;
		  grid[0][k][j] = instrNum + 1;
		}
		if(grid[0][k][j] > instrNum) {
		  grid[0][k][j] = instrNum + 1;
		}
	      }
	      break;
	    case 1: // W
	      for(k = j; k > -1 && !obstacle; k--) {
		if(grid[1][i][k] == -1) {
		  obstacle = true;
		}
		if(grid[1][i][k] == -2) {
		  targetReached = true;
		  grid[1][i][k] = instrNum + 1;
		}
		if(grid[1][i][k] > instrNum) {
		  grid[1][i][k] = instrNum + 1;
		}
	      }
	      break;
	    case 2: // S
	      for(k = i; k < rows && !obstacle; k++) {
		if(grid[2][k][j] == -1) {
		  obstacle = true;
		}
		if(grid[2][k][j] == -2) {
		  targetReached = true;
		  grid[2][k][j] = instrNum + 1;
		}
		if(grid[2][k][j] > instrNum) {
		  grid[2][k][j] = instrNum + 1;
		}
	      }
	      break;
	    case 3: // E
	      for(k = j; k < cols && !obstacle; k++) {
		if(grid[3][i][k] == -1) {
		  obstacle = true;
		}
		if(grid[3][i][k] == -2) {
		  targetReached = true;
		  grid[3][i][k] = instrNum + 1;
		}
		if(grid[3][i][k] > instrNum) {
		  grid[3][i][k] = instrNum + 1;
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
	cout << grid[d][i][j] << " ";
      }
      cout << endl;
    }
  }
}
