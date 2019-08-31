/*Bubblesort function to sort the array*/

void bubble_sort( double x[ ], int n)
{
	int i, j;
	double temp;

	for( i = 0; i < n-1 ; i ++ )	{		// outer for loop
		for( j = i + 1; j < n ; j ++ ) {	// inner for loop
			if( x[i] > x[j] )	{			// swap values
				temp = x[i] ;
				x[i] = x[j] ;		
				x[j] = temp ;
			}
		}
	}
}

