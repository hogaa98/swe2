#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[], char ** envp){
int i;
char c;

FILE* fp;
fp = fopen(argv[1],"wt");
if(NULL == fp){
perror("ERROR");
return -1;
}

srand(time(NULL));

for(i=0;i<=10;i++){
fprintf(fp, "%d\n", rand()%100);
}
fclose(fp);
return 0;
}
