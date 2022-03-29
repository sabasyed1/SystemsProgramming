// Saba Syed
// csit231-01
// 11/8/2021

#include <stdio.h>
#include <time.h>

// variables
int Calculate(int inputNumber);
int CalculateRecursion(int inputNumber);
int main(void) {
  struct timespec start, stop;
  int inputNumber = 0;
  

  // asks the user to enter a number 
  printf("PLease enter a number between 1 - 15 :\n");
  scanf("%d",&inputNumber);

  // if the user doesn't enter a valid number it will ask again
  while(inputNumber <= 0 || inputNumber > 15)
  {
    printf("PLease enter a valid number between 1 - 15 :\n");
    scanf("%d",&inputNumber);
  }

  // asks user if they want recursion or not
  char recursionOption;
  printf("Please enter 'R' for recursion and 'N' for no recursion : \n");
  scanf("%c",&recursionOption);

  while((recursionOption != 'R') && (recursionOption != 'N') && (recursionOption != 'r') && (recursionOption != 'n'))
  {
    printf("Please enter valid 'R' for recursion and 'N' for no recursion :\n");
    scanf("%c",&recursionOption);
  }
  
  int returnedValue =0;

  // calculates the time it took
  if(recursionOption == 'r' || recursionOption == 'R')
  {
     clock_gettime(CLOCK_REALTIME, &start);
     returnedValue = CalculateRecursion(inputNumber);
     clock_gettime(CLOCK_REALTIME, &stop);
     printf("Calculating the factorial of %d took %.0f nanoseconds when done recursively and the result was %d",inputNumber,(double)(stop.tv_nsec - start.tv_nsec), returnedValue);
  }
  else
  {
    clock_gettime(CLOCK_REALTIME, &start);
    returnedValue = Calculate(inputNumber);
    clock_gettime(CLOCK_REALTIME, &stop);
    printf("Calculating the factorial of %d took %.0f nanoseconds when NOT done recursively and the result was %d",inputNumber, (double)(stop.tv_nsec - start.tv_nsec), returnedValue);
  }



  return 0;
}

int Calculate(int inputNumber)
{
  int factorialResult = 1;
   for(int i=1; i <= inputNumber; ++i)
    {
      factorialResult *= i;
    }
   return factorialResult;
}
int CalculateRecursion(int inputNumber)
{
  if(inputNumber > 0)
    return inputNumber * CalculateRecursion(inputNumber - 1);
  else
    return 1;
}