#include <stdio.h>
#include <stdlib.h>

void worker(int, int[] ,  char*[]);

int main(int argc, char* argv[]){
	int i;
	int settings[2];

	FILE* fp = NULL;

	if(1 == argc){
		perror("Fehler in FILE* Erzeugung: Dateiname fehlt");
		return 1;
	}

	fp = fopen(argv[argc-1],"w");
	if(NULL == fp){
		perror("Fehler in FILE* Erzeugung: NULL-Exception");
		return 2;
	}

	worker(argc, settings,  argv);

	for(i=0;i<settings[0];i=i+1)
		fputc(rand()%settings[1], fp);

	fclose(fp);
	return EXIT_SUCCESS;
}

void worker(int argc, int settings[], char* argv[]){
	int i;

	for(i=0;i<(argc-2);i=i+1){
		if('-' == argv[i][0]){
			switch(argv[i][1]){
				case 'h': printf("-h Gibt Hilfe aus");
					  printf("-n Anzahl der Zahlen");
					  printf("-r Zahlenbereich");
					  settings[0] = 0;
					  settings[1] = 0;
					  break;
				case 'n': settings[0] = argv[i+1];
					  break;
				case 'r': settings[1] = argv[i+1];
					  break;
				default:  perror("Fehlerhafte Option");
					  break;
			}
		}
	}
}
