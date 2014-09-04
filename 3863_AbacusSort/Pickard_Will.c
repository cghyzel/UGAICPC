/*
 *Problem: 3863 - Abacus Sort
 *
 *
 * Will Pickard
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct Abacus{
	int numCols;
	int numRows;
	unsigned long long int *rows;
};

void printAbacus(struct Abacus *);
void sort(struct Abacus *);
void sortAbacus(struct Abacus *);
void swapRows(struct Abacus *, int rowA, int rowB);

int main(int argc, char* argv[]){
	FILE *file;
	//there will be x columns
	//Each column will be one bit in a row
	//it is a matrix
	//so for 4 columns with 5 rows, it looks like
	//8	4	2	1
	//8	4	2	1
	//8	4	2	1
	//8	4	2	1
	//8	4	2	1
	//The cols correspond to "poles"
	//The rows will have a 0 | 1 - 1 means a bead is present at that col , 0 means it is not present
	//For example, the rows array may be something like
	//rows[0] = 1110
	//rows[1] = 0010
	//rows[2] = 0101
	//rows[3] = 0001
	//The input for this configuration is:
	//3
	//1
	//2
	//1
	//Notice: rows = #inputs, cols = MAX(input)
	//I only write all this out because it helps me think
	
	//Abacus.rows will be an array of 64 bit longs. 
	//According to the problem the max value for an input is 50, and MAX(input) = num cols, 
	//so the max bit string required contains 50 bits, 64 will be fine
	if(argc != 2){
		printf("2nd arg must be name of existing file.\n");
		exit(1);
	}

	file = fopen(argv[1], "r");
	if(file == NULL){
		printf("file dne\n");
		exit(1);
	}
	int *result;//the result of realloc
	unsigned long long int i; //this will be the integer scanned by fscanf
	unsigned long long int max = 0; //this will be the max input
	int END; //this will be set to !0 by feof(file)-indicating end of file
	while(fscanf(file, "%d", &i), !(END = feof(file))){
		printf("-------------top---------------\n");
		struct Abacus abacus;
		abacus.numRows = 0;
		abacus.numCols = 0;
		abacus.rows = malloc(sizeof(unsigned long long int));
		//fscanf(file, "%d", &i);
		while(i != 0){
			if(abacus.numRows > 0)
				result = realloc(abacus.rows, ((abacus.numRows+1) * sizeof(unsigned long long int))); //give the rows array another row
			//update max
			if(i > max)
				max = i;
			abacus.rows[abacus.numRows] = (unsigned long long int)i;//(i * sizeof(unsigned long long int)); //set this row to the number of beads here			
			abacus.numRows++;
			fscanf(file, "%d", &i);
		}

		abacus.numCols = max;
		sortAbacus(&abacus);
		printAbacus(&abacus);
		free((abacus.rows));
		printf("--------------------------------------------------\n\n");
	}	
}

void sortAbacus(struct Abacus *abacus){
	struct Abacus toSort;
	toSort.numCols = abacus->numCols;
	toSort.numRows = abacus->numRows;
	toSort.rows = malloc((toSort.numRows*sizeof(unsigned long long int)));

	int x, beadVal, beadCount, beadsRem;
	unsigned long long int rowBitVal, bitVal;
	int max = abacus->numCols;

	//set bit values for the rows
	for(x=0; x<abacus->numRows; x++){
		beadVal = max; 
		rowBitVal = 0;
		beadsRem = beadCount = abacus->rows[x];
		for(beadsRem; beadsRem > 0; beadsRem--){
			bitVal = pow(2, (beadVal-1));
			rowBitVal += bitVal;
			beadVal--;
		}
		toSort.rows[x] = rowBitVal;
	}
	int t = 0;
	for(t;t<abacus->numRows; t++){
		printf("row %d bitValue is %llu\n", t, toSort.rows[t]);
	}	
	//now sort toSort
	printAbacus(&toSort);	
	sort(&toSort);
	printAbacus(&toSort);
}

void sort(struct Abacus *abacus){
	int rows = abacus->numRows;
	int row;
	for(row=0; row < rows-1 ; row++){
		swapRows(abacus, row, (row+1));	
	}
}
/*
a = 	1	1	1	1
b = 	1	0	1	0
cmp =	0	1	0	1

newA = 	1	0	1	0
newB = 	1	1	1	1

*/

void swapRows(struct Abacus *abacus, int A, int B){
	unsigned long long int cmp, rowA, rowB;
	rowA = abacus->rows[A];
	rowB = abacus->rows[B];
printf("\trowA: %d ... rowB: %d\n", rowA, rowB);	
	cmp = rowA - rowB;
	A -= cmp; //drop these beads
	B &= cmp;    //to here
}

void printAbacus(struct Abacus *abacus){
	int rows = abacus -> numRows;
	unsigned long long int top, bottom, result;
	bottom = (unsigned long long int)log(2);
	int i, beadCount;
	i = beadCount = 0;
	for(i=0; i<rows; i++){
		result = abacus->rows[i];
		while(result != 0){
			top = (unsigned long long int) log(result);
			result = top/bottom;

			beadCount++;
		}
		for(beadCount; beadCount>0; beadCount--){
			printf("X");
		}
		printf("\n");
	}
}
