/*Name : Yonathan Kebede
 *Description : This program creates a transpose of a matrix provided by the
 *		user and calculates the matrix multiplication of the matrix
 *		and the transpose of the matrix.
 * ENEE 150
 * 
 */


#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int cols;	
	int element,i=0,j,k,l,row=0;	
	
	//Ask for number of columns of the matrixs
	printf("\nEnter number of columns (n): ");
	scanf("%d",&cols);
	
	//Matrix that has specified number of columns and 10 rows
	int matrix[10][cols];
	int resultElement;
	
	//User must enter a number between 1 and 10 inclusive
	if(cols<0 || cols>10){
		fprintf(stderr, "You cannot enter a non-positive number or a number more than 10 for the number of columns.\n");
		exit(1);
	}
	
	//Ask user for elements
	printf("\nYour entered row is %d\nEnter the elements: \n",cols);
	
	//Scan for elements from file
	while((fscanf(stdin,"%d",&element))!= EOF){
		if(row==10){
			fprintf(stderr, "\nToo many elements. The program is exiting");
			exit(1);
		}
		matrix[row][i] = element;
		i++;
		if(i==cols){
			row++;
			i=0;
		}	
	}
	
	//Error if user doesnt input elements inputs compared the number of 
	//columns
	if(i!=0){
		fprintf(stderr, "\nNumber of elements in last row is incomplete");
		exit(1);
	}
	
	//Print the whole matrix that the user entered
	printf("\nThe matrix you entered is as shown below:\n");	
	for(i=0; i<row; i++){
		for(j=0; j<cols; j++){
			printf("%3d",matrix[i][j]);
		}
		printf("\n");		
	}
	
	//Print the transpose by switching row and column
	printf("\nThis is the transpose of your matrix:\n");
	for(i=0; i<cols; i++){
		for(j=0; j<row; j++){
			printf("%3d",matrix[j][i]);
		}
		printf("\n");
	}

	//Create and print the matrix multiplied by it's transpose
	printf("\nThis is the matrix muliplied by its transpose:\n");	
	for( i=0; i<row; i++){
    		for( j=0; j<row; j++){
			resultElement=0;
      			for(k=0 ; k<cols ; k++){
				resultElement += matrix[i][k] * matrix[j][k];
			}
			printf("%3d",resultElement);
     		}
		printf("\n");
	}
		
	return 0;
}
