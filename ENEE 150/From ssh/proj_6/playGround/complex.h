struct complex;
typedef struct complex complex_type;

/*create a new complex number with no param*/
complex_type *complex_new_noArg(void);

/*create a new complex number with real and imaginary as parameters*/
complex_type *complex_new(double , double);

/*return the real part of the complex number*/
double complex_real(complex_type *);

/*return the imaginary part of the complex number*/
double complex_fake(complex_type *);

/*multiplication of 2 complex numbers*/
void complex_multiply(complex_type *, complex_type *);

/*Subtraction of 2 complex numbers*/
void complex_subtract(complex_type *, complex_type *);

/*addition of 2 complex numbers*/
void complex_add(complex_type *, complex_type *);

