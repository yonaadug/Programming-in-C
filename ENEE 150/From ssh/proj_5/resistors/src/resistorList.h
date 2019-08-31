#ifndef _resistorList_h
#define _resistorList_h 

/* header file for resistor linked list: */

typedef struct resistor {
	  int resistor_id;  /* resistor ID */
	  double resistance; /* resistance value */
	  struct resistor *next; /* pointer to next node */
} resistorList;

typedef resistorList * resistorListPtr; /*synonym for resistorList * */

/* Insert a new resistor into the beginning of the list 	*/
/* id -- resistor ID; value -- value of resistance		*/
void insertResistor (resistorListPtr * sPtr, int id, double value);

/* Delete a resistor from the list */
void deleteResistor (resistorListPtr * sPtr, int id);

/* Print the resistor list and the total resistance at the end */
/* For example: R2 --> R3 --> R1 --> Total Resistance: 30.50   */
void printResistance (resistorListPtr currentPtr);

#endif

