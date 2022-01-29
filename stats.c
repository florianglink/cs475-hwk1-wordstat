
#include "stats.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/**
 * Initializes the statistics structure
 * @param st an uninitialized WordStats struct
 * @return an initialized WordStats struct 
 */
WordStats initStats(WordStats st)
{ 
	st.wordCount = 0;
	st.vowelCount = 0;
	st.consonantCount = 0;
	for(int i = 0; i<ALPHABET_SIZE; i++){
		st.histo[i] = 0;
	}

	// TODO initialize all fields in the st struct before returning it
	return st;
}

/**
 * Updates vowels and consonants in the struct
 * @param st WordStats structure
 * @param input the user-input string
 * @return an updated WordStats struct 
 */
WordStats updateVowelCons(WordStats st, const char str[])
{
	int i = 0;
	while(str[i] != '\0') {
		if((str[i] >= 65 && str[i] <= 90) || (str[i] >=97 && str[i] <= 122)) {
			if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
				st.vowelCount++;
			}
			else {
				st.consonantCount++;
			}
		}
		i++;
	}
	// TODO - update the vowel and consonant count
	//        in the st struct before returning it
	return st;
}

/**
 * Updates word count in the struct
 * @param st 
 * @param str 
 * @return an updated WordStats struct 
 */
WordStats updateWordCount(WordStats st, const char str[])
{    
    char delim[] = " ,.!;:\n";
    char *words, *ptr;
        ptr= str;
     
    while ((words = strtok(ptr, delim)) !=NULL) {
		if(isalpha(words[0])) {
        	st.wordCount++;
       		ptr = NULL; 
		}
		else {
			ptr = NULL;
		}
    }
	// TODO - update the word count in the st struct before returning it
	return st;
}

/**
 * Outputs vowel and consonant stats
 * @param st WordStats structure
 */
void printVowelConsFreq(WordStats st)
{
	float vowels;
	float cons;
	vowels = st.vowelCount;
	cons = st.consonantCount;
	float vowelPercent = (vowels/(vowels+cons));
	float consonantPercent = (cons/(vowels+cons));
	printf("\nVowels: %u (%.2f%%)\n", st.vowelCount, vowelPercent);
	printf("Consonants: %u (%.2f%%)\n", st.consonantCount, consonantPercent);
	printf("Total: %u\n", st.vowelCount+st.consonantCount);
}

/**
 * Outputs word count
 * @param st WordStats structure
 */
void printWordCount(WordStats st)
{
	printf("\nWords: %u\n", st.wordCount);
}

/**
 * Outputs histogram vertically
 * @param st WordStats structure
 */
void printHistogram(WordStats st)
{
	int i;
	int max = st.histo[0];
	for(i=1; i<26; i++) {      //loop to find the frequency of the most common letter in histo
		if(st.histo[i] > max){
			max = st.histo[i];
		}
	}
	printf("\n");
	for(int j = max; j>0; j--){    
		for(int k=0; k<26; k++) {
			if(st.histo[k]>=j) {
				printf("* ");
			}
			else{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("a b c d e f g h i j k l m n o p q r s t u v w x y z\n");
	for(int l=0; l<26; l++) {
		printf("%u \n", st.histo[l]);
	}
}

/**
 * Update the histogram
 * @param histo	the histogram
 * @param str	the string used to update the histogram
 */
void updateHistogram(int histo[], const char str[])
{
	int i = 0;
	while(str[i] != '\0') {
		if(isalpha(str[i])) {
			histo[tolower(str[i])-'a']++;
		}
		i++;
	}
}
