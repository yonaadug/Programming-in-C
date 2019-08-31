#include <stdio.h>
#include "matrix_functions.h"
#include <stdlib.h>

int main(){

	/* Pointer to the set of matrix registers. */
	int **matrices = NULL;
	matrices = matrix_allocate_variable(MAX_MATRICES * sizeof (int *)); /* Allocate space to hold 4 matrices.*/

	/* row_counts[i] stores the number of rows in matrix i */
	int *row_counts = NULL;
	row_counts = matrix_allocate_variable(MAX_MATRICES * sizeof(int));
	
	
	/* column_counts[i] stores the number of columns in matrix i */
	int *column_counts = NULL;
	column_counts = matrix_allocate_variable(MAX_MATRICES * sizeof(int));

	char cmd;
	printf("\n");

	do{
		fflush(stdin);
		fscanf(stdin,"\n%c",&cmd);
		//printf("You entered ..%c.. thaat,",cmd);	
		fflush(stdin);
		
		if( cmd >= 'A' && cmd <= 'D'){
			matrix_new (matrices, row_counts, column_counts, cmd);
			//matrix_display (matrices[0], row_counts[0], column_counts[0])
			continue;
		}
		
		switch (cmd){
			case '+':	
				matrix_add (matrices, row_counts, column_counts);	
				break;
			case '*':
				matrix_multiply (matrices, row_counts, column_counts);
                                break;
			case '^':
				matrix_transpose (matrices, row_counts, column_counts);
                                break;
			case '$':
				return 0;
				break;
			default:       
				fprintf(stderr, "\nCommand not found.\n");
		}
	
		
	}while(cmd != '$');
	
	return 0;
}



