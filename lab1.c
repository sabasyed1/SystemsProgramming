// Saba Syed 
// LAB 1
// 9/18/21


#include <stdio.h>

// PI is the ratio of the circumference of a circle
#define PI 3.14159


/*
  declaring variables 
 */

double weight, volume, innerA , outerA, innerD, outerD, area, density, batchWeight, thickness;
int quantity;

void main()
{
	
  {
    // got this information from geeksforgeeks
     // Old file name
    char old_name[] = "main.c";
  
    // Any string
    char new_name[] = "lab1.c";
  int value;
    // File name is changed here
    value = rename(old_name, new_name);
  

  }
	printf("Please enter the inner diameter of the Washer in cm: ");
	scanf("%lf", &innerD);

	printf("Please enter the outer diameter of the Washer in cm: ");
	scanf("%lf", &outerD);

	printf("Please enter the density of the Washer in g/cm2: ");
	scanf("%lf", &density);
	
	printf("Please enter the thickness of the Washer in cm: ");
	scanf("%lf", &thickness);
	
	printf("Please enter the number of the Washers ordered: ");
        scanf("%d", &quantity);

	//calculating inner area
	innerA = PI*innerD/2*innerD/2;
	//calculating outer area
	outerA = PI*outerD/2*outerD/2;
	//calculating area
	area = outerA - innerA;
	//calculating volume
	volume = area * thickness;
       	//calculating weight 
	weight = volume * density;
	//calculating batch weight
	batchWeight = quantity * weight;

	printf("The rim area of the washer is %10.6lf\n", area);
	printf("The weight of the washer is %10.6lf\n", weight);
	printf("The weight of the batch of washers is %10.6lf\n", batchWeight);
}
