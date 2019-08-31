#include <stdio.h>
#include "myHeader.h"
#include <string.h>

int main(){
	
	char command[MAX_CMD_LEN] = ""; // Command that the user enters
	char current[MAX_STRING_LEN] = "";
	char result[MAX_STRING_LEN] = "";
	char history_table[HISTORY_SIZE][MAX_CMD_LEN];
	
	int history_size = 0;
	int flag=0;
	
	printf("\nHello user, this is the StRiNgG PlAy program, where you PlAy with StRiNgS. YaaaaaaY. Now you can play with strings\n");
	
	do{
		printf("cmd> ");
		gets(command);
			
		if(strcmp(command, "hist")==0) {
			printHistory(history_table, history_size);
		}else {
			flag = processCommand(current, command, result);
			updateHistory(history_table, command, history_size);
			if(history_size!=HISTORY_SIZE)
				history_size++;
				
		}
		
		/*If command is not empty, put command into history table */	
	}  while (flag!=1);

	return 0;
}


int processCommand(char *current, char *cmd, char *result){

	if(!strcmp(cmd,"quit")){
		return 1;
	}else if(!strcmp(cmd,"new")){
		getString(current);		
	}else if(!strcmp(cmd,"list")){
		printString(current);

        }else if(!strcmp(cmd,"append")){
		char str2[MAX_STRING_LEN] = "";
		printf("Enter string to append: ");
		gets(str2);
		
		if(strlen(str2)+strlen(current)+1>MAX_STRING_LEN-1){
			fprintf(stderr,"Error: Length of total string is more than the max ((99).\n");
			return 0;
		}
		
		appendString(current," ");
		appendString(current,str2);

        }else if(!strcmp(cmd,"find")){
		char str[MAX_STRING_LEN];
		printf("Enter sub string to find: ");
		gets(str);
		printf("looking for %s \n",str);
		printf("The substring exists %d times in the current string.\n",findString(current,str));
		

        }else if(!strcmp(cmd,"replace")){
		replaceString(current,result);

        }else if(!strcmp(cmd,"toggle")){
		toggleString(current,result);
		printf("%s\n",result);

        }else if(!strcmp(cmd,"rev")){
		reverseString(current,result);
		printf("%s\n",result);
        }else if(!strcmp(cmd,"wrev")){
		reverseWord(current,result);
		printf("%s\n",result);

        }else if(!strcmp(cmd,"stat")){
		printStatistics(current);

        }else if(!strcmp(cmd,"help")){
		printHelp();
        }else if(!strcmp(cmd,"palindrome")){
		

	}	
	
	return 0;
}


/* Read a string from the keyboard */
void getString(char *str){

	printf("Enter new string: ");	
	gets(str);	
}

/* Print the string to the screen */
void printString (const char *str){
	printf("%s\n",str);
}

/* Print a history of the commands */
void printHistory(char history[][MAX_CMD_LEN], int size){
	int i;
	for( i=0; i<size; i++){
		printf("%s\n",history[i]);
	}
	
}

/* Replace the current string with the new string */
void replaceString (char *current, char *newstr){
	strcpy(current, newstr);
}

/* Toggle the case of the string */
void toggleString(const char *str, char *toggled){
	int i;	
	strcpy(toggled,str);
	for(i=0;i<strlen(str);i++){
		if(isupper(toggled[i])){
			toggled[i] = tolower(toggled[i]);
		}else if(islower(toggled[i])){
			toggled[i] = toupper(toggled[i]);
		}	
	}
}

/* Append the new string to the current string */
void appendString(char *str, char *newstr){	
	strcat(str,newstr);
}

/* Reverse the string character by character*/
void reverseString (const char *str, char *reverse){
	int i=0;
	for( i=0; i<strlen(str); i++){
		reverse[i] = str[strlen(str)-i-1];		
	}
	
}

/* Reverse the string word by word */
void reverseWord (const char *str, char *wordreverse){
	int i;
	char cpyRev[MAX_STRING_LEN];
        char delim[2] = " ";
      	reverseString(str, cpyRev);
        char *tok = strtok(cpyRev, delim);
	char *tokRev[MAX_STRING_LEN];
	strcpy(wordreverse,"");
	
        while(tok != NULL){
		reverseString(tok,tokRev);
		strcat(wordreverse,tokRev);
                tok = strtok(NULL,delim);
		if(tok!=NULL)
			strcat(wordreverse," ");
        }	
	
}

/* Find string str in the current string and return and number of times it appears in the current string */
int findString (const char *current, char *str){
	
	int count=0;
	if(strstr(current,str)==NULL){
		return 0;	
	}
	char currentCpy[strlen(current)];
        strcpy(currentCpy,current);	
	do{		
		strcpy(currentCpy, strstr(currentCpy, str)+sizeof(char)*strlen(str));
		count++;
	}while(strstr(currentCpy, str)!=NULL);	
	
	return count;	
}

/* Print the statistics of the current string */
void printStatistics (const char *str){
	int i=(int)'a',count=0,j,words=0;
	printf("Statistics:\n");
	printf("\tlength: %d\n",strlen(str));
	
	//Count words
	char cpy[MAX_STRING_LEN];
	char delim[2] = " ";
	strcpy(cpy,str);
	char *tok = strtok(cpy, delim);
	while(tok != NULL){
		words++;
		tok = strtok(NULL,delim);
	}
	
	printf("\tword: %d\n",words);
	printf("Frequency: \n");
		
	while(i<=(int)'z'){
		for(j=0; j<strlen(str); j++){
			if(str[j]==(char)i)
				count++;
		}
		i++;
		if(count ==0)
			continue;	
		
		printf("\tfrequency of '%c': %3d\n", (char)(i-1),count);
		count=0;
		
	}
	
	i=(int)'A';
	
	while(i<=(int)'Z'){
		for(j=0; j<strlen(str); j++){
                        if(str[j]==(char)i)
                                count++;
                }
                i++;
                if(count ==0)
                        continue;

                printf("\tfrequency of '%c': %3d\n", (char)(i-1),count);
                count=0;		
	}	
}
/* Add a command to the history table. If the history table is full, discard the oldest command. Function takes three arguments: history table, the command to be added into the table, and the current history table size */
void updateHistory (char history[][MAX_CMD_LEN], const char *cmd, int size){
	int i=0;
	if(size==HISTORY_SIZE){
		for(i=1; i<HISTORY_SIZE; i++){
			strcpy(history[i-1],history[i]);
		}
		strcpy(history[9],cmd);
		return;
	}
	strcpy(history[size],cmd);
	return;
}

void printHelp(void){
	
		printf("[new]        Enter New String\n");
                printf("[list]       List Current String\n");
                printf("[append]     Append a String to the End of Current String\n");
                printf("[find]       Find a String in Current String\n");
                printf("[replace]    Replace Current String with Output of Last Command\n");
                printf("[toggle]     Toggle the Case of Current String\n");
                printf("[rev]        Print Current String in Reverse Order Character By Character\n");
                printf("[wrev]       Print Current String in Reverse Order Word By Word\n");
                printf("[stat]       Print Statistics of Current String\n");
                printf("[help]       Print This Help Screen\n");
                printf("[hist]       Print a History of Commands Entered\n");
                printf("[quit]       Quit Program\n");
                printf("[palindrome] Special command. Checks if word is a palindrome\n");	
}
