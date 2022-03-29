
// Saba Syed
// 10/06/2021
// Lab 3

#include <stdio.h>

int main(int argc, char *argv[]) {

  int StrLength = 100;
  char string[StrLength], vowelA, vowelE, vowelI, vowelO, vowelU;
  char *pointerString;
 char **memAddress;

 if(argc > 1)
 {
   int argvLen = strlen(argv);
   for(int i = 0; i < argvLen ; i++)
   {
     string[i] = argv[i];
   }
 }
 else
 {
    printf("Enter your string: ");
    scanf("%[^\n]",&string);
 }
  // replacing characters a, e, i, o, u
  printf("\nThe special characters to replace the vowels are: !@#$?+=-><:;^\n");
 
  printf("\nThe special characters that you want to replace A with: ");
  scanf("\n%c",&vowelA);

    printf("\nThe special characters that you want to replace E with: ");
  scanf("\n%c",&vowelE);

  printf("\nThe special characters that you want to replace I with: ");
  scanf("\n%c",&vowelI);

    printf("\nThe special characters that you want to replace O with: ");
  scanf("\n%c",&vowelO);

    printf("\nThe special characters that you want to replace U with: ");
  scanf("\n%c",&vowelU);
    int inputStringLen = strlen(string);

    for(int i=0; i < inputStringLen; i++)
    {
        switch(string[i])
        {
          case 'a':
          case 'A':{
            string[i] = vowelA;
            break;
          }
          case 'e':
          case 'E':{
            string[i] = vowelE;
            break;
          }
          case 'i':
          case 'I':{
            string[i] = vowelI;
            break;
          }
          case 'o':
          case 'O':{
            string[i] = vowelO;
            break;
          }
          case 'u':
          case 'U':{
            string[i] = vowelU;
            break;
          }
        }
    }
    pointerString = string;
    memAddress = &string;
    printf("\n String after replacing vowels : %s",pointerString);

    printf("\n Reverse String after replacing vowels : ");
    for(int i = inputStringLen; i >= 0; i--)
    {
      printf("%c",string[i]); 
    }
printf("\n String memory address : %p",&memAddress);
    return 0;
}