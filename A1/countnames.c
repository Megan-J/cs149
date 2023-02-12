/**
 * Description: This module implements mathematical operations on vectors.
 * Author names: Megan Ju, Neel Patel
 * Author emails: megan.ju@sjsu.edu, neel.patel@sjsu.edu
 * Last modified date: February 10, 2023
 * Creation date: February 11, 2023
 **/
 
 #include <stdio.h>
 #include <string.h>
 
 #define MAX_NAME_LENGTH 30
 #define MAX_NAMES 100
 
 /**
 * Main function for counting name occurrences in a file
 * Assumption: none
 * Input parameters: arc, argv
 * Returns: 0 if successful, 1 if there was an error
 **/
 int main(int argc, char *argv[]){
 	
 	// Checking if the number of arguments passed to the program is correct
 	// If incorrect, print out error statements and return 1
 	if(argc != 2){
 		fprintf(stderr, "Error: Incorrect number of arguments\n");
 		fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
 		return 1;
 	}
 
 	// Reading in the file
 	FILE *list = fopen(argv[1], "r");
 	
 	// Checking if fopen() succeeded
 	// If error, print out error statements and return 1
 	if(NULL == list){
 		fprintf(stderr, "Error: Unable to open file %s.\n", argv[1]);
 		return 1;
 	}
 	
 	// Two arrays to store names and occurances
 	char names[MAX_NAMES][MAX_NAME_LENGTH];	// 
 	int occurrences[MAX_NAMES];	// keep track of number of times each name read
 	
 	// Keep track of total number of names
 	int totalNames = 0;
 	
 	// Temp var for new name read
 	char name[MAX_NAME_LENGTH];
 	
 	// Current line number
 	int lineNumber = 0;
 	
 	// Iterate through the file to count the names
 	while(fgets(name, MAX_NAME_LENGTH, list)){
 	
 		lineNumber++;	// incrementing line number
 		
 		int curNameLength = strlen(name);	// keeping track of length of name
 		
 		// If the line is empty, print out warning
 		if(curNameLength <= 1){
 			fprintf(stderr, "Warning - Line %d is empty.\n", lineNumber);
 			continue;
 		}
 		
 		// Reformatting the \n to \0
 		if (name[strlen(name) - 1] == '\n'){
 			name[strlen(name) - 1] = '\0';
 		}
 		
 		// Check if name is already accounted for
 		int knownNames = 0;
 		
 		for(int i = 0; i < totalNames; i++){
 			
 			//if the names are the same
 			if(strcmp(names[i], name) == 0){
 				//increment number of times seen
 				occurrences[i]++;
 				knownNames = 1;
 				break;
 			}
 		}
 		
 		// If name is not already known, add to array
 		if(!knownNames){
 			strcpy(names[totalNames], name);
 			occurrences[totalNames] = 1;
 			totalNames++;

 		}
 	}

 	// Close input file
 	fclose(list);
 	
 	// Print occurrence for each name
 		for(int i = 0; i < totalNames; i++){
 			printf("%s: %d\n", names[i], occurrences[i]);
 		}
 	
 	// Return 0 to indicate successful execution
 	return 0;
 
 
 }
