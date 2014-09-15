#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDupes(char *);

int main(int argc, char* argv[]){
	if(argc != 2){exit(1);}
	
	FILE *file;
	char *line = NULL;
	size_t br;
	int number; //number of inputs on a line, will be at line[0]	
	file = fopen(argv[1], "r");
	if(file == NULL){exit(1);}
	
	getline(&line, &br, file);
	number = line[0] - '0';
	//while(number != 0){
		printf("%s\n", line);
		int *toRemove[number];// = malloc(sizeof(int) * number);
		int i;
		for(i=2; i<strlen(line); i++){
			char *buf = NULL;
			while(line[i] != ' ' && i<strlen(line)){
				printf("%d: %c\n",i, line[i]);
				char t = line[i];
				//strcat(buf, &t);
				i++;	
			}	
		//	buf[strlen(buf)] = '\0';
			printf("%s to int is %d\n",buf, buf - '\0');
		}
		

	//	getline(&line, &br, file);
	//	number = line[0] - '0';
	//}
	
	//found = removeDupes(found);
}

char* removeDupes(char *str){
	char *newStr;
	printf("before rd: %s\n", str);
	newStr = malloc((strlen(str) * sizeof(char)));
	
	int i=0, j=0;
	int found = 0;
	for(i=0; i<strlen(str); i++){
		found = 0;
		for(j=0; j<strlen(newStr); j++){
			if(str[i] == newStr[j]) found = 1;
		}
		if(!found)
			newStr[strlen(newStr)] = str[i];	
	}	

	str = newStr;
	str[strlen(str)] = '\0';
	printf("after rd: %s\n", str);
	return str;
}
