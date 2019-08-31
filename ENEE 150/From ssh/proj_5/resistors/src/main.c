// Name: Yonathan Kebede
// Project 5: Resistors in series
// Description: User enters a series of resisters and the program will
// 				handle the resistors in linked lists


#include <stdio.h>
#include <stdlib.h>
#include "resistorList.h"

int main(){
	
	int choice = -1;
	int resistorID;
	int resistorValue;
	resistorListPtr startPtr= NULL;
	
	
	//Loop that asks user for command until he/she enters '3' for exit
	do{
		//Display choices ask user to enter a choice.
		printf("Enter your choice: 1 insert; 2 delete; 3 exit:\n?: ");
		scanf("%d",&choice);

		if(choice ==1){
			//Code to insert a resister
			printf("Enter resistor ID: ");
			scanf("%d", &resistorID);		
			
			if(resistorID > 0){
				
				//Check if resistor ID already used
				resistorListPtr loopPtr;
	                        loopPtr = startPtr;
				int i = 0;
                	        while(loopPtr != NULL){
                        	        if(loopPtr -> resistor_id == resistorID){
						fprintf(stderr,"\nERROR. Resistor ID already taken.\n");
						i = -1;
						break;
                                	}
					loopPtr = loopPtr -> next;
                       		}
				if(i==-1)
					continue;

				
				printf("Enter resistor value: ");
				scanf("%d", &resistorValue);
					
				if( resistorValue > 0){
					insertResistor(&startPtr, resistorID, resistorValue);
					printResistance(startPtr);
										
				}else
					fprintf(stderr, "\nResistor Values should be positive.\n");
				
			} else {
				fprintf(stderr, "\nResistor ID's cannot be negative.\n");
			}

		} else if (choice ==2){
			//Code to delete a resistor
			if (startPtr == NULL) {
				printf("List is empty.\n\n");
			}

		    	else {
		    		printResistance(startPtr);
			    	printf("\nEnter the resistor ID of the resistor you want to delete: ");
			    	scanf("%d", &resistorID);
		    		deleteResistor(&startPtr, resistorID);
				printResistance(startPtr);
			}
			
			
		}else if (choice != 3){
				//Invalid entry
				fprintf(stderr,"\nInvalid Choice.\n");
		}
		
	}while(choice!=3);
	//Exit when user enters 3.
	
	return 0;	
}

//Insert resistor to list
void insertResistor (resistorListPtr * sPtr, int id, double value){
	
	resistorListPtr newPtr;
        resistorListPtr previousPtr;
        resistorListPtr currentPtr;

        newPtr = (resistorListPtr) malloc (sizeof(resistorList));
	
	if (newPtr==NULL){
		fprintf(stderr, "No memory available. Insertion failed. \n");
		return;
	}
		
	newPtr -> resistor_id = id;
	
	newPtr -> resistance = value;
	newPtr -> next = NULL;

	previousPtr = NULL;
	currentPtr = *sPtr;
	
	/*loop to find the current location in the list */
	while (currentPtr != NULL ){
		
		previousPtr = currentPtr;        
		currentPtr = currentPtr->next;
	}

	/* below is only true if we are at the beginning of the
 * 	   list and never traversed in the while loop above.
 * 	   insert new node at beginning of list */
	if (previousPtr == NULL) {
		newPtr->next = *sPtr;
		*sPtr = newPtr;
	}
	else { /*insert new node between previousPtr and currentPtr */
		previousPtr->next = newPtr;
		newPtr->next = currentPtr;
	}
	
}


void deleteResistor (resistorListPtr * sPtr, int id){
	
	resistorListPtr tempPtr;
	resistorListPtr previousPtr;
	resistorListPtr currentPtr;
	
	/* delete the first node */
	if (id == (*sPtr) -> resistor_id) {
		tempPtr = *sPtr; 
		*sPtr = (*sPtr) -> next;  /*delete the node */
		free(tempPtr); /* free the delete node */
	}
	else {
		previousPtr = *sPtr;
		currentPtr = (*sPtr) ->next;

		/*loop to find the correct location in the list */
		while (currentPtr != NULL && currentPtr -> resistor_id != id ) {
			previousPtr = currentPtr;        
			currentPtr = currentPtr -> next;
		}
		if (currentPtr == NULL) {
			printf( "%d not found.\n", id);
			return;
		}

		/*delete node at currentPtr */
		tempPtr = currentPtr; 
		previousPtr -> next = currentPtr -> next;  
		free(tempPtr);
	}

}

void printResistance (resistorListPtr currentPtr){
	
	double totalResistance=0;
	/* if list is empty */
	if (currentPtr == NULL) {
		printf("No resistors. \n\n");
    	} else {
 	
		printf("The list of resistors are: \n");

		while (currentPtr != NULL) {
			printf ("R%d --> ", currentPtr -> resistor_id );
			totalResistance += currentPtr -> resistance;
			currentPtr = currentPtr -> next;
		}
		printf("Total Resistance: %lf \n",totalResistance);
		//printf("NULL\n\n");
	}
	
	
}
