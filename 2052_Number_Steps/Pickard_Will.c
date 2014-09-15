/**
 *@file
 *	Problem Id: 2052
 *	Number Steps
 *
 *	Read input (from a file?) corresponding to coordinates (x,y) then print the number at that point or print "No Number"
 *
 *Will Pickard
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int n, x, y, num, i;
	FILE *file;

	if(argc < 2){//no input file
		printf("Please enter an input file for the 2nd arg\n");
		exit(1);	
	}
	file = fopen(argv[1], "r");
	if(file == NULL){
		printf("File dne\n");
		exit(1);
	}

	//first line in file is number of coordinates
	fscanf(file, "%d", &n);
	for(i=0; i<n; i++){
		fscanf(file, "%d", &x);
		fscanf(file, "%d", &y);
		if(x==y || x==(y+2)){//x has to be equal to y or 2 greater than it
			if(x%2==0 && y%2==0)
				printf("%d\n", (x+y));
			else
				printf("%d\n", ((x+y)-1));
		}
		else
			printf("No Number\n");
		
	}
}
