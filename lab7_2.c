//saba syed
// matthew chua

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
	FILE *fp;
	int status, wstatus, ret;
	int filedesc_str;


	FILE *happensToFallFile = fopen("happenstofall.txt","r");	//  Saba: read- only
	int line_size = 300;
	char* fallFileLine = malloc(line_size);
	if (happensToFallFile == NULL)
	{
		printf("Unable to open happenstofall file");
	}
	else
	{
	int fork2;
	filedesc_str=fileno(happensToFallFile);

		while (fgets(fallFileLine, line_size, happensToFallFile) != NULL)	// Saba: read line by line
		{
			setbuf(stdout, NULL);
			printf("\n %i is the file descriptor pid of lab7_2 is: %d, ppid is: %d ",filedesc_str, getpid(), getppid()); // matt: print pid ppid
			printf("\n%s ",fallFileLine); //  matt: print output for lab7_2
			
			fflush(stdout);
			fp = fopen("beer.out", "a");	// matt: print section to beer.out
			fprintf(fp, "\n %i is the file descriptor pid of lab7_2 is: %d, ppid is: %d ",filedesc_str, getpid(), getppid()); // matt: print pid ppid
			fprintf(fp, "\n %s ",fallFileLine); // matt: print output for lab7_2
			fclose(fp);

			fflush(stdout);
			fork2 = fork(); //matt: fork
			if(fork2 == 0){
			char *args[] = {argv[0], "text2", "text3", NULL}; // Saba:set args value
			execv("./lab7_3", args); // Saba:exec lab7_3 and pass args
			}
			wait(&wstatus);
		
		}
		free(fallFileLine);
		return 0;
		
		}
	fclose(happensToFallFile);
	
}
