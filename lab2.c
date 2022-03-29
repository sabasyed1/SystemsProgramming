// Saba Syed
// CSIT231-01
// LAB2


#include <stdio.h>

int main()
{
  // Get Total number of Years
    int totalYears;

    printf("How years of planet-wide temperature data you would like to enter: ");
    scanf("%d", &totalYears);

  // Variables and dynamic arrays
     float celsius[totalYears], fahrenheit[totalYears], maxTempC = 0.0, maxTempF = 0.0, minTempC = 0.0, minTempF = 0.0;
    int currentYear[totalYears],minYear = 0, maxYear = 0;
    

  // Populating data inputs and converting tempratues in F
    for(int i = 0; i < totalYears ;i++) {
     
      printf("\nEnter the year of the data : ");
      scanf("%d", &currentYear[i]);
      
      printf("In %d, enter the temperature in Celsius: ", currentYear[i]);
      scanf("%f", &celsius[i]);
            // Convert the temperature from celsius to fahrenheit formula
   
	// F=C*(9/5)+32
    fahrenheit[i] = ((celsius[i] * (1.8))+32);
  
    printf("%.2f C (celsius) = %.2f F (fahrenheit) \n", celsius[i], fahrenheit[i]);
    }

  //  Logic for minimum and maximum inputs
  for(int i = 0; i < totalYears ; i++)
  {
    if(i == 0)
    {
      minYear = currentYear[i];
      maxYear = currentYear[i];
      minTempC = celsius[i];
      minTempF = fahrenheit[i]; 
      maxTempC = celsius[i];
      maxTempF = fahrenheit[i]; 
    }
    else
    {
      if(celsius[i] < minTempC)
      {
        minYear = currentYear[i];
        minTempC = celsius[i];
        minTempF = fahrenheit[i];
      }
      else
      {
        maxYear = currentYear[i];
        maxTempC = celsius[i];
        maxTempF = fahrenheit[i];
      }
    }
  }


//  Display calculated data
printf("\n The maximum year is %d with high temprature in Celsius is %.2f C and in Fahrenheit is %.2f F.",maxYear, maxTempC, maxTempF);

printf("\n The minimum year is %d with low temprature in Celsius is %.2f C and in Fahrenheit is %.2f F.",minYear, minTempC, minTempF);


  return 0;
}
