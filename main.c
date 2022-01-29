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
int main(int argc, char **argv) {
	WordStats w;
	w = initStats(w);
	char input[MAX_INPUT_LEN]; //holds user-input string
	char option[MAX_INPUT_LEN];
	PROMPT: printf("Enter strings (# to stop):\n"); //prompt the user to input strings

	while (input[0] != '#') {
		fgets(input, MAX_INPUT_LEN, stdin);
		w = updateVowelCons(w, input);
		w = updateWordCount(w, input);
		updateHistogram(w.histo, input);
	}

	while(option[0] != '5') {
		getMenuOption();
		fgets(option, MAX_INPUT_LEN, stdin);

		if(option[1] != '\0') {
			if(option[0] == '1'){
				printVowelConsFreq(w);
			}
			else if(option[0] == '2'){
				printWordCount(w);
			}
			else if(option[0] == '3'){
				printHistogram(w);
			}
			else if(option[0] == '4'){
				goto PROMPT;
			}
		}
		else {
			printf("Unknown option. Try again.\n");
		}
	}

	// TODO: repeatedly print menu options and prompt for an option
	// TODO: display the proper output

	printf("Exiting...\n");
	return 0;
}
