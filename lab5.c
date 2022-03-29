// saba syed
// csit 231
//10/18/2021
//lab5



#include <stdio.h>
#include <stdlib.h>

// PI is the ratio of the circumference of a circle
#define PI 3.14159
#define DOUBLE_SIZE 30


/*
  declaring variables 
 */

double innerD, outerD, density, thickness;

int main()
{
  double *innerA = calloc(sizeof(double),DOUBLE_SIZE), *weight = calloc(sizeof(double),DOUBLE_SIZE), *volume = calloc(sizeof(double),DOUBLE_SIZE), *outerA = calloc(sizeof(double),DOUBLE_SIZE),*batchWeight = calloc(sizeof(double),DOUBLE_SIZE), *area = calloc(sizeof(double),DOUBLE_SIZE);
	int quan = 0;
	printf("Please enter the inner diameter of the Washer in cm: ");
	scanf("%lf", &innerD);

	printf("Please enter the outer diameter of the Washer in cm: ");
	scanf("%lf", &outerD);

	printf("Please enter the density of the Washer in g/cm2: ");
	scanf("%lf", &density);
	
	printf("Please enter the thickness of the Washer in cm: ");
	scanf("%lf", &thickness);
	
	printf("Please enter the number of the Washers ordered: ");
	  scanf("%d", &quan);

	//calculating inner area
	*innerA = PI*innerD/2*innerD/2;
	//calculating outer area
	*outerA = PI*outerD/2*outerD/2;
	//calculating area
	*area = *outerA - *innerA;
	//calculating volume
	*volume = *area * thickness;
       	//calculating weight 
	*weight = *volume * density;
	//calculating batch weight
	*batchWeight = quan * *weight;

	printf("The rim area of the washer is %10.6lf\n", *area);
	printf("The weight of the washer is %10.6lf\n", *weight);
	printf("The weight of the batch of washers is %10.6lf\n", *batchWeight);
}

