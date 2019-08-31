/* Name: Yonathan Kebede
 * Lab 1, Question 1
 * Description: This program sees the equivalent of a certain currency to
 * 		another currency. The currencies supported are $US, Euros, 
 * 		and Pounds.
 *
 */
#include <string.h>
#include <stdio.h>

#define US_EURO  0.74759
#define US_POUND 0.64173

int main(){
	
	int i=0,j;
	double userCurrency;

	//String to hold 
	char userCmd[10];

	//Array of possible commands in the program
	char COMMANDS[8][10]  = { 	"Euro-US" , 
					"Euro-Pound",
					"Pound-Euro",
					"Pound-US",
					"US-Pound",
					"US-Euro",
					"showrates",
					"quit"
	};
	
	printf("\n");

	
	do{
		// Variable to hold the number of the position in the COMMANDS array
		// the user enters
		j=-1;
	
		//Ask user for command
		scanf("%s",userCmd);

		// Loop to see which of the commands the user put and puts it
		// loads the number in the array into the integer j.
		for(i=0; i<8; i++){
			if (!strcmp(COMMANDS[i], userCmd)){
				j=i;			
			}
		}
		
		// Big if statement to see if the user enters a command from the array
		// and prints the conversion according to the command. 
		if(j>-1&&j<6){
			printf("Please enter amount in ");
			
			if ( j==0 || j==1){
				printf("Euros: ");
				scanf("%lf", &userCurrency);
				
				userCurrency = (j==0)? userCurrency/US_EURO: userCurrency/US_POUND;

				if(j==0){
					printf("%f $US\n", userCurrency);	
				}else { 
					printf("%f Pounds\n", userCurrency);
				}

			}else if (j==2 || j==3){
				printf("Pound: ");	
				scanf("%lf", &userCurrency);
				
				userCurrency = (j==2)?userCurrency/US_POUND*US_EURO : userCurrency/US_POUND;
				
				if(j==2){
					printf("%f Euros\n", userCurrency);
				}else {
					printf("%f $US\n", userCurrency);
				}
			}else {
				printf("US: ");
				scanf("%lf", &userCurrency);
				
				userCurrency = (j==4)? userCurrency*US_POUND : userCurrency*US_EURO;
				
				if(j==4){
					printf("%f Pounds\n", userCurrency);
				}else {
					printf("%f Euros\n", userCurrency);
				}
		
			}
		}else if( j==6){
			printf("1.00 $US = %f Pounds\n",US_POUND);
			printf("1.00 $US = %f Euros\n",US_EURO);
			printf("1.00 Euro = %f $US\n", 1/US_EURO);
			printf("1.00 Euro = %f Pounds\n",1.00/US_EURO*US_POUND);
			printf("1.00 Pound = %f $US\n",1.0/US_POUND);
			printf("1.00 Pound = %f Euros\n", 1.0/US_POUND*US_EURO);
		}
	} while( strcmp(COMMANDS[7], userCmd));
		//Do While loop ends when user enters quit

	
}
