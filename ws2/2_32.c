/**
 * Description: Exercise 2.32 from Zybooks
 * Author names: Neel Patel, Megan Ju
 * Author emails: neel.patel@sjsu.edu; megan.ju@sjsu.edu
 * Last modified date: February 8, 2023
 * Creation date: February 8, 2023
 **/

#include <stdio.h>
#include <math.h>

/**
 * Outputs the current price, the change in price 
 * and the estimated mortgage
 * Assumption: none
 * Input parameters: none
 * Returns: an integer
**/

int main(void){
	int current;
	int prev;
	
	scanf("%d", &current);
	scanf("%d", &prev);
	
	int dif = current-prev;
	double mortgage = (current*0.051)/12;
	
	printf("This house is $%d. The change is $%d since last month.\nThe estimated monthly mortgage is $%lf.\n", current, dif, mortgage);	

	return 0;
}
