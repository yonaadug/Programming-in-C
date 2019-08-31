#include "arrayFunctions.h"

double median_array (double x[ ], int n)
{
	bubble_sort(x, n); /*sort the array */

	/* If n is even, return average of two middle elements. 	If n is odd, simply return the middle element */
	if (n%2 == 0) {
		return ((x[n/2-1]+x[n/2])/2); 
	}
	else {
		return (x[n/2]);
	}
}

