#include <stdio.h>
#include "matrix_functions.h"
#include <stdlib.h>

/* Allocate space for an object of size "size" bytes and return a pointer to it. Exit with an error message if this allocation request cannot be granted */
void *matrix_allocate_variable (int size){

        void *ptr;
        if((ptr = malloc(size))==NULL){
                fprintf(stderr,"\nCannot allocate memory\n");
		exit(1);
        }
        return ptr;

}

/* Read values of the matrix s (specifier) from standard input*/
void matrix_new(int **matrices, int *row_counts, int *column_counts, char specifier){

        int i, j;
	int index = (int)specifier - (int)'A';
        int num;


        //Scan for row and column size
        scanf(" %d %d",&row_counts[index],&column_counts[index]);

	 //Error message
	if( row_counts[index] <= 0 || column_counts[index] <= 0){
                fprintf(stderr,"\nNumber of row and columns should be positive\n");
                return;
        }else if( row_counts[index] > MAX_MATRICES || column_counts[index] > MAX_MATRICES){
                fprintf(stderr,"\nThe max number of rows and columns, is 5. Please enter a different number.\n");
                return;
        }

        //Free memory to the matrix
        if(matrices[index]!=NULL){
		free(matrices[index]);	
	}
	
	matrices[index] = matrix_allocate_variable(row_counts[index] * column_counts[index] * sizeof(int));
       

        //Scans each element into matrix
        for( i=0; i<row_counts[index]; i++){
                for( j=0; j<column_counts[index]; j++){
                        scanf(" %d",&(matrices[index])[(i * column_counts[index]) + j] );
                }
        }
       return;
}

/* Add two matrices. Read names of two matrices from standard input */
void matrix_add (int **matrices, int *row_counts, int *column_counts){

        char matrixChar1, matrixChar2;
        int i, j, matrix1, matrix2;

        scanf(" %c %c", &matrixChar1, &matrixChar2);

	matrix1 = matrixChar1 - 'A';
	matrix2 = matrixChar2 - 'A';

	if( (matrix1 < 0 || matrix1 > 3) || (matrix2 < 0 || matrix2 > 3)){
		fprintf(stderr,"\nOne or both of the matricies you entered is invalid.\n");
		return;
	}else if( row_counts[matrix1] == 0 || row_counts[matrix2] == 0){
                fprintf(stderr,"\nOne or both of the matrices are not filled in. They do not add.\n");
	        return;
        }else if((row_counts[matrix1] != row_counts[matrix2]) || (column_counts[matrix1] != column_counts[matrix2])){
                fprintf(stderr, "\nThe matrices' row and columns do not match. They cannot add.\n");
		return;
        }

        for( i=0; i<row_counts[matrix1]; i++){
                for( j=0; j<column_counts[matrix1]; j++){
                        printf("%4d", matrices[matrix1][i*column_counts[matrix1]+j] + matrices[matrix2][i*column_counts[matrix1]+j]);

                }
                printf("\n");
        }

        return;
}


/* Multiply two matrices. Read names of two matrices from standard input  */
void matrix_multiply (int **matrices, int *row_counts, int *column_counts){
	
	char matrixChar1, matrixChar2;
        int i, j, k, matrix1, matrix2;
	int result;
	
        scanf(" %c %c", &matrixChar1, &matrixChar2);

        matrix1 = matrixChar1 - 'A';
        matrix2 = matrixChar2 - 'A';

        if( matrix1 < 0 || matrix1 > 3 || matrix2 < 0 || matrix2 > 3){
                fprintf(stderr,"\nOne or both of the matricies you entered is invalid.\n");
                return;
        }else if( matrices[matrix1] == 0 || matrices[matrix2] == 0){
                fprintf(stderr,"\nOne or both of the matrices are not filled in. They do not add.\n");
                return;
        }else if( (column_counts[matrix1] != row_counts[matrix2])){
                fprintf(stderr, "\nThe matrices' row and columns do not match. They cannot multiply\n");
                return;
        }
	
	
	//first loop to go through
	for(i=0; i<row_counts[matrix1]; i++){
		for( j=0; j<column_counts[matrix2]; j++){
			result = 0;
			for( k=0; k<column_counts[matrix1]; k++){
				result += matrices[matrix1][i*column_counts[matrix1]+k]*matrices[matrix2][j+k*row_counts[matrix2]];
			}
			printf("%4d",result);			
		}	
		printf("\n");
		
	}
	

}

/* Calculate the transpose of a matrix */
void matrix_transpose (int **matrices, int *row_counts, int *column_counts){
        int i, j, matrix = -1;
        char matrixChar;

        scanf(" %c",&matrixChar);

        matrix = matrixChar - 'A';
	
		if(matrix < 0 || matrix > 3){
			fprintf(stderr, "\nInvalid matrix.\n");
			return;
		}

        for( i=0; i<column_counts[matrix]; i++){

                for( j=0; j<row_counts[matrix]; j++){
                        printf("%4d",(matrices[matrix])[i+j*column_counts[matrix]]);
		}
                printf("\n");
        }
}
