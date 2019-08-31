// Name: Yonathan Kebede
// Project Description: Make a program that implements an ADT for 
// 						complex numbers and include function for finding
// 						the root and the magnitude. This program also adds,
// 						subtracts, and multiplies 2 complex numbers.
// ENEE 150
// Dr. David Kuijt


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

double absolute(complex_type *c);

void root(complex_type *c);


int main(){


	double img, real; // Imaginary and real variables for complex number	
	complex_type *c1 = NULL , *c2 = NULL; // 2 complex number objects created. 	
	
	//Ask for complex number
	printf("\nEnter the first complex number (real then imaginary part): ");
	fscanf(stdin,"%lf %lf",&real,&img);
	c1 = complex_new(real, img);
	
	//Check if complex number object created successfully.
	if(c1 == NULL){
		fprintf(stderr,"\nCannot make complex number due to memory. Exiting...");
		exit(1);
	}
	
	//Ask for complex number
	printf("\nEnter the second complex number (real then imaginary part): ");
	fscanf(stdin,"%lf %lf",&real,&img);
    c2 = complex_new(real, img);
	
	//Check if complex number object created successfully.	
	if(c2 == NULL){
                fprintf(stderr,"\nCannot make complex number due to memory.\n");
                exit(1);
        }
	
	
    printf("\nComplex numbers entered:\n%lf + %lfi \n%lf + %lfi\n",complex_real(c1),complex_fake(c1),complex_real(c2),complex_fake(c2));
	
	//Functions that add, subtract add and multiply 2 complex numbers
	complex_add(c1,c2);	
	complex_subtract(c1,c2);
	complex_multiply(c1,c2);		
	
	//Print both magnitude and roots for both complex numbers
	
	printf("\nFirst complex number:\nMagnitude = %lf",absolute(c1));
	root(c1);
	
	printf("\nSecond complex number:\nMagnitude = %lf",absolute(c2));
	root(c2);
	
	
	return 0;
}


//Calculate absolute value of complex number 'c'
double absolute(complex_type *c){

        double magnitude = sqrt(pow(complex_real(c),2)+pow(complex_fake(c),2));
        return magnitude;
}

//Calculate square root of complex number 'c'
void root(complex_type *c){

	double real = complex_real(c);
	double fake = complex_fake(c);
    printf("\nSquare root(s) = ");

    if( real==0 && fake==0){
		printf("0.00\n");
    } else if(fake==0){
 		if(real > 0){
			printf("%lf and %lf\n", sqrt(real),-sqrt(real));
		}else{
			printf("%lfi and %lfi\n", sqrt(real),-sqrt(real));
		}
	} else{
		double x1, y1;
		y1 = sqrt((absolute(c)-real)/2);
		x1 = fake/(2*y1);
		printf("%lf + %lfi \tand\t %lf + %lfi\n",x1,y1,x1,-y1);

	}
}

