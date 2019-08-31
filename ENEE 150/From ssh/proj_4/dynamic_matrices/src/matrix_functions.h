#ifndef _matrix_functions_h
#define _matrix_functions_h

/**********************************************************************
 * Dynamic Matrix Operations Standard Header File "matrix_functions.h"
 * **********************************************************************/

/* The maximum number of rows / columns supported. */
#define MAX_MATRICES	5

/* Error messages */

/* Allocate space for an object of size "size" bytes and return a pointer to it. Exit with an error message if this allocation request cannot be granted */
void *matrix_allocate_variable (int size);

/* Read values of the matrix s (specifier) from standard input*/
void matrix_new(int **matrices, int *row_counts, int *column_counts, char specifier);

/* Add two matrices. Read names of two matrices from standard input */
void matrix_add (int **matrices, int *row_counts, int *column_counts);

/* Multiply two matrices. Read names of two matrices from standard input  */
void matrix_multiply (int **matrices, int *row_counts, int *column_counts);

/* Calculate the transpose of a matrix */
void matrix_transpose (int **matrices, int *row_counts, int *column_counts);

/* Display matrix to the screen. */
void matrix_display(int *matrix, int row_count, int column_count);

#endif

