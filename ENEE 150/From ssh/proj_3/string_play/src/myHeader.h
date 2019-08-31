#define HISTORY_SIZE 10 /*the maximum size of the history*/
#define MAX_STRING_LEN 100 /*the maximum size of strings*/
#define MAX_CMD_LEN 11	/*the maximum size of a command*/

/* Print a listing of the different commands */
void printHelp(void);

/* Read a string from the keyboard */
void getString(char *str);

/* Print the string to the screen */
void printString (const char *str);

/* Print a history of the commands */
void printHistory(char history[][MAX_CMD_LEN], int size);

/* Replace the current string with the new string */
void replaceString (char *current, char *newstr);

/* Toggle the case of the string */
void toggleString(const char *str, char *toggled);

/* Append the new string to the current string */
void appendString(char *str, char *newstr);

/* Reverse the string character by character*/
void reverseString (const char *str, char *reverse);

/* Reverse the string word by word */
void reverseWord (const char *str, char *wordreverse);

/* Find string str in the current string and return and number of times it appears in the current string */
int findString (const char *current, char *str);

/* Print the statistics of the current string */
void printStatistics (const char *str);

/* Add a command to the history table. If the history table is full, discard the oldest command. Function takes three arguments: history table, the command to be added into the table, and the current history table size */
void updateHistory (char history[][MAX_CMD_LEN], const char *cmd, int size);

/*Process the command entered from the keyboard. If the command is quit, returns 1. The result string contains the result of executing the command */
int processCommand (char *current, char *cmd, char *result); 

