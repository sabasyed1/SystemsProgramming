// Saba Syed 
// Matthew Chua
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
# include <sys/stat.h>




int main(int argc, char *argv[]) {
	 FILE *str, *stw, *fp;
	int status, wstatus, ret;
	int filedesc_str;	
	char command[128];
	

	if(argc <= 1)	// Saba: Checking if we do not have any argument
	{
		usage: printf("Command requires an argument of a number between 1 - 100");
		exit(1);
	}
	int providedNumber = atoi(argv[1]);	// Saba: converting argument to integer
	
	//  Saba: For testing purpose commented out the argc condition and provide a default value to providedNumber
	
	if(providedNumber < 1|| providedNumber > 100)	//  Saba: checking if the number is between 1 - 100
	{
		exit(99);
	}
	FILE *bottlesOfBeerFile = fopen("bottlesofbeer.txt","r");	//  Saba: read- only
	int line_size = 150;
	char providedNumberS[line_size];
	char* line = malloc(line_size);
	char textLine[2][line_size];	// Saba: for two lines in bolttlesofbeer file
	if (bottlesOfBeerFile == NULL)
	{
		printf("Unable to open beerofbottles file");
	}
	else
	{

		int i = 0;
		while (fgets(line, line_size, bottlesOfBeerFile) != NULL)	//  Saba:reading each line in file
		{
			
            		strcpy(textLine[i],line);	//  Saba: storing first line in line[0]
			i++;

		}free(line);
	}
	int fork1;
	while(providedNumber >= 0)
	{
		if(providedNumber == 0)
		{
			printf("\nNO MORE BOTTLES OF BEER ON THE WALL");
			
			
			//Matt: chmod("./beer.out", S_IRUSR |S_IWUSR); // set permision to -rw- --- ---
			strcpy(command,"chmod 600 ./beer.out"); // matt: does same thing
			system(command);
			
			
			break;
		}
		else
		{
		filedesc_str=fileno(bottlesOfBeerFile);	
		
			
			setbuf(stdout, NULL); // Saba: remove buffer
			printf("\n %i is the file descriptor pid of lab7_1 is: %d", filedesc_str,  getpid()); // matt:  show pid 
			printf("\n %d %s %d %s ",providedNumber, textLine[0], providedNumber, textLine[1]); // Saba: print output for la7_1

			fp = fopen("beer.out", "a");	// print section to beer.out
			fprintf(fp, "\n %i is the file descriptor pid of lab7_1 is: %d", filedesc_str,  getpid()); // matt: show pid 
			fprintf(fp, "\n %d %s %d %s ",providedNumber, textLine[0], providedNumber, textLine[1]); // Saba:print output for la7_1
			fclose(fp);
			

			sprintf(providedNumberS, "%d", providedNumber); //  matt: convert integer to string
			providedNumber --; 
			
			fflush(stdout);
			fork1 = fork(); // matt: fork process
				if(fork1 == 0){ // matt: check if forking was successful
				char *args[] = {providedNumberS, "text2", "text3", NULL}; // matt: set args values
				execv("./lab7_2", args); // matt: execute and pass arg values
			}
			wait(&wstatus);
								
}
		
	}return 0;
	
	fclose(bottlesOfBeerFile);	//  Saba: close the file
	
	
	
}

