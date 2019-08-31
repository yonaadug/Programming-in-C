#include <stdio.h>
#include "arrayFunctions.h"

int main(void)
{
	double x[100], xmean, xmedian;
	int i, n;
	
	printf("Number of elements: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf( "Enter value of x[%d]: \n", i);
		scanf( "%lf", &x[i]);
	}

	xmean = mean_array(x, n);
	xmedian = median_array(x, n);

	printf("\nMean Value = %g\n", xmean);
	printf("Median Value = %g\n", xmedian);
	
	return 0;
}
