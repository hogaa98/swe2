#include <stdio.h>
#include <wiringPi.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


#define LED (0)

void *myThread(void *arg);

int fd[2];//File descriptor for creating a pipe

static const char* CHAR_TO_MORSE[128] = {
 NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL, "-.-.--", ".-..-.", NULL, NULL, NULL, NULL, ".----.",
 "-.--.", "-.--.-", NULL, NULL, "--..--", "-....-", ".-.-.-", "-..-.",
 "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
 "---..", "----.", "---...", NULL, NULL, "-...-", NULL, "..--..",
 ".--.-.", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
 "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
 ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
 "-..-", "-.--", "--..", NULL, NULL, NULL, NULL, "..--.-",
 NULL, ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
 "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
 ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
 "-..-", "-.--", "--..", NULL, NULL, NULL, NULL, NULL
};



char reader()
{
	char    ch;
      int     result;

      result = read(fd[0],&ch,1);
      if (result != 1) {
        perror("reader");
        exit(3);
      }
      return ch;
}



void *writer(char ch)
{
   int     result;

   while(1){
       result = write(fd[1], &ch,1);
       if (result != 1){
           perror ("writer");
           exit (2);
       }

       
   }
}



int main() {
	if(wiringPiSetup() == -1){
		return -1;
	}	
	
	pthread_t tid;
	const char* tmp;
	int ch;
	
	pinMode(LED,OUTPUT);
	
	pipe(fd);
		
	pthread_create(&tid, NULL, &myThread, NULL);
	close(fd[0]);
	while ( (ch=fgetc(stdin)) != EOF ) {
		
			switch(ch){
				case ' ': 
					writer('=');
					break;
				default: 
					tmp=CHAR_TO_MORSE[ch];//TODO
					for(int i = 0;(tmp[i]=='.' || tmp[i]=='-');i++){
						writer(tmp[i]);
					}
					break;
			}     
		
   }
   writer(EOF);
   
   void *result;
   pthread_join(tid,&result);
   
	return(0);
	
   //printf("%s %s %s %s %s\n",CHAR_TO_MORSE['M'],CHAR_TO_MORSE['O'],CHAR_TO_MORSE['R'],CHAR_TO_MORSE['S'],CHAR_TO_MORSE['E']);
}

// Signal Morsecode Thread


void *myThread(void *arg) {
	char ch;
	close(fd[1]);
	while((ch = reader()) != EOF){
		printf("%c",ch);
		
		switch(ch){
			case '_':
				digitalWrite(LED,LOW);
				sleep(3);
				break;
			case '=':
				digitalWrite(LED,LOW);
				sleep(7);
				break;
			case '.':
				digitalWrite(LED,HIGH);
				sleep(1);
				digitalWrite(LED,LOW);
				sleep(1);
				break;
			case '-':
				digitalWrite(LED,HIGH);
				sleep(3);
				digitalWrite(LED,LOW);
				sleep(1);
				break;
			default:
				perror("thread");
				//return 1;
				break;
		}
	}
	return NULL;
}


