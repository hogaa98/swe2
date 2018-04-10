#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void work(File*);
char work_toDo(char[]);

int main(int argc, char* argv[], char ** envp){

	int m = 100;

	FILE* fp = NULL;

	srand(time(NULL));

		switch(argc){
			case 2:	fp = fopen(argv[1], "wt");
				work(fp, m);
				break;
			case 3:	fp = fopen(argv[2], "wt");
				if( work_toDo(argv[1]))
					work(fp, m);
				break;
			default:perror("Fehlerhafter Programmaufruf!");
				return -1;
		}

	fclose(fp);
	return EXIT_SUCCESS;
}

void work(FILE* fp){
	if(NULL==fp){
		perror("Datei konnte nicht erstellt werden!");
		return -2;
	}

	for(i=0;i<=10;i++){
		fprintf(fp, "%d\n", rand()%m);
	}
}

char work_toDo(char[] option){
	switch(option){
		case "-h": 	printf("\"-h\" zeigt die Hilfe an\n");
				printf("\"-n\" Anzahl der Zahlen(deful 100)");
				printf("\"-r\" Zahlenbereich (default 100)");
				return 'h';
		case "-n":	return 'n';
		case "-r":	return 'r';
	}
	perror("Fehler in Optionsdeterministik!");
	return -3;
}
