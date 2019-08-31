#include <stdlib.h>
#include <stdio.h>
#include "complex.h"


struct complex{
	double real;
	double fake; //imaginary number	
};

//CONSTRUCTOR 1
//Create complex object 'c' with no parameters
complex_type *complex_new_noArg(void){
	
	complex_type *s;
	
	s = (complex_type *) malloc (sizeof (struct complex));
	
	if( s == NULL){
		return NULL;
	}
	
	s->real = 0;
	s->fake = 0;
	
	return s;
}

//CONSTRUCTOR 2
//Create complex number object 'c'
complex_type *complex_new(double real, double fake){
	
	
	complex_type *c;

        c = (complex_type *) malloc (sizeof (struct complex));

        if( c == NULL){
                return NULL;
        }

        c->real = real;
        c->fake = fake;

        return c;
}

//Getter for real number in complex number object
double complex_real (complex_type *c){
	return (c->real);
}

//Getter for imaginary number in complex number object
double complex_fake (complex_type *c){
	return (c->fake);
}

//Add complex numbers c1 and c2 to make c
void complex_add(complex_type *c1, complex_type *c2 ){
	
	double real, fake;	
	
	real = (c1->real)+(c2->real);
	fake = (c1->fake)+(c2->fake);
	
	printf("\nAddition: %lf + %lfi \n",real,fake);
	
	return;
}

//Multiply two complex numbers and return the result
void complex_multiply(complex_type *c1, complex_type *c2){
	
    double real, fake;

    real = ((c1->real)*(c2->real))-((c1->fake)*(c2->fake));
    fake = ((c1->real)*(c2->fake))+((c1->fake)*(c2->real));
	
	printf("\nMultiplication: %lf + %lfi \n",real,fake);
	
    return;
}

//Subtract complex numbers and return the result 
void complex_subtract(complex_type *c1, complex_type *c2 ){
	
    double real, fake;

    real = (c1->real)-(c2->real);
    fake = (c1->fake)-(c2->fake);

	printf("\nSubtraction: %lf + %lfi \n",real, fake);
	
    return;
	
}
