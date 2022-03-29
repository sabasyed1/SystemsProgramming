
// Saba Syed 
// CSIT231-01
// Lab 3 

#include <stdio.h>
#include<stdbool.h>

int main()
{
  int totalBill =0, totalChoice = 4, selectedItem;
  printf("Please select item from menu by their number.\n");
  
  // menu 
  printf("1. Chicken \n");
  printf("2. Pizza \n");
  printf("3. Burger \n");
  printf("4. Soup \n");
  printf("5. Egg \n");
  printf("6. Gyro \n");
  printf("7. Hot Dog \n");
  printf("8. Salad \n");
  
  //for else
  for(int i = 0; i < totalChoice ; i++)
  {
    if(i == 0)
    {
      printf("What would you like to eat? \n");
      scanf("%d",&selectedItem);
    }
    else
    {
      printf("What Else? \n");
      scanf("%d",&selectedItem);
    }

    //switch case
    switch(selectedItem)
    {
      case 1:{
        totalBill+= 4;
        break;
      }
      case 2 :{
        totalBill+=2;
        break;
      }
      case 3 :{
        totalBill+=5;
        break;
      }
      case 4 :{
        totalBill++;
        break;
      }
      case 5 :{
        totalBill++;
        break;
      }
      case 6 :{
        totalBill+=6;
        break;
      }
      case 7 :{
        totalBill+=4;
        break;
      }
      case 8 :{
        totalBill+=2;
        break;
      }
      default:{
        continue;
      }
    }

  }
// total 
printf("Your total bill is = %d. \n",totalBill);
  return(0);
}

[syeds3@turing lab3]$ 
