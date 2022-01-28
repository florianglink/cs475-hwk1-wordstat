#include <stdio.h>
#include <string.h>
#include "stats.h"
#include "menu.h"

#define MAX_INPUT_LEN 128 /** maximum length of input users can enter */

/**
 * Main function
 * 
 * @param argc the number of command line arguments (ignore for this assignment)
 * @param argv an array of command line arguments (ignore for this assignment)
 */
int main(int argc, char **argv)
{
	char input[MAX_INPUT_LEN]; //holds user-input string
	
	printf("Enter strings (# to stop):\n"); //prompt the user to input strings
	while (input[0] != '#') {
		fgets(input, MAX_INPUT_LEN, stdin);

	}
	// TODO: repeatedly print menu options and prompt for an option
	// TODO: display the proper output

	printf("Exiting...\n");
	return 0;
}
