/*Function to calculate the mean of the array*/

double  mean_array (double x[ ], int n)
{
	double sum =0.0, mean;
	int i;

	for (i = 0; i < n; i++) {
		sum = sum + x[i];
	}

	mean = sum/n;
	return mean;
}
 
