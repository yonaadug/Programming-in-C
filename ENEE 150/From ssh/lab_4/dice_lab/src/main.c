/* Name: Yonathan Kebede
 */


#include <stdio.h>
#include <stdlib.h>

double fraction (int x,int y);

int main(void){
	
	double x,y;
	
	printf("This program calculates the fraction of 2 integers\nEnter the numerator and the denominator: ");
	scanf("%lf %lf",&x,&y);
	printf("%f\n",fraction(x,y));	
	return 0;
}

double fraction (int x, int y){	
	if(y==0){
		fprintf(stderr, "\nCannot calculate ratio to of %d, to 0", x);
		exit(1);
	}

	return 1.0*x/y;
}
