#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void incCharMem();
void sort(int, int);
int readFile(char[]);
int length = 2;
int* dynMem = NULL;
void swapDynMem(int, int);
void printResult(int);

void main(int argc, char* argv[]){
	char opt = 'h';
	dynMem = malloc(length*sizeof(int));
	
	if(1==argc){
		printf("-h\t gibt Hilfe aus\n");
		printf("-a\t sortiert aufsteigend\n");
		printf("-d\t sortiert absteigend\n");
		free(dynMem);
		exit(EXIT_SUCCESS);
	}
	
	
	
		if(0 == strcmp("-h", argv[1])){
			printf("-h\t gibt Hilfe aus\n");
			printf("-a\t sortiert aufsteigend\n");
			printf("-d\t sortiert absteigend\n");
			free(dynMem);
			exit(EXIT_SUCCESS);
		}else if(0 == strcmp("-a", argv[1])){
			sort(1, readFile(argv[2]));
		}else if(0 == strcmp("-d", argv[1])){
			sort(2, readFile(argv[2]));
		}else{
			sort(1, readFile(argv[1]));
		}
	
	getchar();
	
	free(dynMem);
	exit(EXIT_SUCCESS);
}

void incDynMem(){
	int newlength = length*length;
	int i = 0;
	
	int* temp = (int*)malloc(newlength*sizeof(int));
	if(NULL == temp){
		free(dynMem);
		exit(EXIT_FAILURE);
	}
		
	memcpy(temp, dynMem, sizeof(dynMem));
	
	free(dynMem);
	dynMem = temp;
	length = newlength;
}

int readFile(char* filename){
	int i = 0;
	
	FILE* fp = NULL;
	fp = fopen(filename,"r");	
	
	if(NULL == fp){
		free(dynMem);
		exit(EXIT_FAILURE);
	}
	
	if(0 == fscanf(fp, "%d", &dynMem[i])){
		exit(EXIT_FAILURE);
	}
	
	do{
		i++;
		if(i == length)
			incDynMem();
	}while(0 != fscanf(fp, "%d", &dynMem[i]));
	
	return i;
}

void swapDynMem(int i, int k){
	int temp = 0;
	
	temp = dynMem[i];
	dynMem[i] = dynMem[k];
	dynMem[k] = temp;
}

void sort(int opt, int j){
	int i=0;
	int k=0;
	
	if(1 == opt){
		for(i=0; i<j; i=i+1){
			for(k=i; k<j; k=k+1){
				if(dynMem[i] > dynMem[k])
					swapDynMem(i,k);
			}
		}
		printResult(j);
	}else if(2 == opt){
		for(i=0; i<j; i=i+1){
			for(k=i; k<j; k=k+1){
				if(dynMem[i] < dynMem[k])
					swapDynMem(i,k);
			}
		}
		printResult(j);
	}else{
		free(dynMem);
		exit(EXIT_FAILURE);
	}
}

void printResult(int j){
	int i = 0;
	for(i=0;i<j;i=i+1){
		printf("%d\n", dynMem[i]);
	}
}
