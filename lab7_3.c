//saba syed
//matthew chua

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char *argv[]){
FILE *fp;
int filedesc_str;

int bottleNumber= atoi(argv[0]);

FILE *remainingFile = fopen("remaining.txt", "r" ); //  Saba: open the file
int line_size = 300;
char* remainingFileLine = malloc(line_size);

	if(remainingFile == NULL){
		printf("File not found, cannot open remaining file");
	}

	else{
	filedesc_str=fileno(remainingFile);

		while (fgets(remainingFileLine, line_size, remainingFile) != NULL){

			bottleNumber--; // Saba: decrement the bottleNumber
			
			printf("\n %i is the file descriptor pid of lab7_3 is: %d, ppid is: %d \n",filedesc_str, getpid(), getppid()); //matt: print pid ppid
			printf("%d %s \n", bottleNumber, remainingFileLine); // Saba: print the line of the remaining file with bottleNo.
			
			fflush(stdout);
			fp = fopen("beer.out", "a");	// matt: print section to beer.out
			fprintf(fp, "\n %i is the file descriptor pid of lab7_3 is: %d, ppid is: %d \n",filedesc_str, getpid(), getppid()); // matt: print pid ppid
			fprintf(fp, "%d %s \n", bottleNumber, remainingFileLine); // Saba: print the line of the remaining file with bottleNo.
			fclose(fp);
			fflush(stdout);

		}
		free(remainingFileLine); //  Saba:free heap
	}

	fclose(remainingFile); // Saba: close the file
	return 0;
	exit (0);
}

