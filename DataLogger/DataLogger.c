#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void do_log();

void  main(){
	int i = 0;
	
	do_log();
	
	do{
		if(600 <= i){
			i = 0;
			do_log();
		}
		sleep(1); 
		i=i+1;
	}while(1);
	exit(EXIT_SUCCESS);
}

void do_log(){
	FILE* fp = NULL;
	FILE* cp = NULL;
	char charr[16];
	
	fp = fopen("data.log", "a");
	if(NULL == fp)
		exit(EXIT_FAILURE);
	cp = popen("curl ifconfig.me","r");
	if(NULL == cp)
		exit(EXIT_FAILURE);
		
	fgets(charr,16,cp);	
	fputs(charr,fp);
	
	fclose(fp);
	pclose(cp);
}
