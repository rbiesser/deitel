/**
	Random Sentences
	8.11-randomsentences.c 
	Purpose: Generate random sentences from arrays of common parts of speech

	8.11	(Random Sentences) Write a program that uses random-number generation to create 
	sentences. The program should use four arrays of pointers to char called article, noun, 
	verb and preposition. The program should create a sentence by selecting a word at random 
	from each array in the following order: article, noun, verb, preposition, article and noun. 
	As each word is picked, it should be concatenated to the previous words in an array large
	enough to hold the entire sentence. The words should be separated by spaces. When the 
	final sentence is output, it should start with a capital letter and end with a period. The 
	program should generate 20 such sentences. The arrays should be filled as follows: The 
	article array should contain the articles "the", "a", "one", "some" and "any"; the noun 
	array should contain the nouns "boy", "girl", "dog", "town" and "car"; the verb array should 
	contain the verbs "drove", "jumped", "ran", "walked" and "skipped"; the preposition array 
	should contain the prepositions "to", "from", "over", "under" and "on".

	After the preceding program is written and working, modify it to produce a short story 
	consisting of several of these sentences. (How about the possibility of a random term-paper 
	writer?)
	
	@author Robbie Biesser
	@version 1.0 2/19/2019
	@source Deitel. (2015). C How to Program, 8th Edition.

*/

#include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h> // necessary for string functions

int main()
{
	srand(time(0)); // seed the random number generator

	// string literals
	// https://stackoverflow.com/a/16767062
	char const *articles[] = {"the", "a", "one", "some", "any"};
	char const *nouns[] = {"boy", "girl", "dog", "town", "car"};
	char const *verbs[] = {"drove", "jumped", "ran", "walked", "skipped"};
	char const *prepositions[] = {"to", "from", "over", "under", "on"};

	// printf("%c\n", toupper(articles[0][0]));

	char sentence[80]; // variable to store a sentence

	// a C string references each letter like an element in the char array
	// "this" "that"
	// "t", "h", "i", "s"

	int i;
	for (i = 0; i < 20; i++)
	{
		/* There's a couple different ways to solve */

		/* 1. printf, but can't reuse the sentence */
		// printf("%s %s %s %s %s %s\n"
		// 		, articles[rand() % 5]
		// 		, nouns[rand() % 5]
		// 		, verbs[rand() % 5]
		// 		, prepositions[rand() % 5]
		// 		, articles[rand() % 5]
		// 		, nouns[rand() % 5]
		// 	);

		/* 2. string concatenation with the strcat function, but it takes a lot of steps */
		// strcpy(sentence, articles[rand() % 5]);
		// strcat(sentence, " ");
		// strcat(sentence, nouns[rand() % 5]);
		// strcat(sentence, " ");
		// strcat(sentence, verbs[rand() % 5]);
		// strcat(sentence, " ");
		// strcat(sentence, prepositions[rand() % 5]);
		// strcat(sentence, " ");
		// strcat(sentence, articles[rand() % 5]);
		// strcat(sentence, " ");
		// strcat(sentence, nouns[rand() % 5]);
		// strcat(sentence, ".");

		/* 3. sprintf, like the printf function and you can reuse the sentence */
		// http://www.cplusplus.com/reference/cstdio/sprintf/
		sprintf(sentence, "%s %s %s %s %s %s."
				, articles[rand() % 5]
				, nouns[rand() % 5]
				, verbs[rand() % 5]
				, prepositions[rand() % 5]
				, articles[rand() % 5]
				, nouns[rand() % 5]
			);

		/* shared by all to uppercase the first letter */
		sentence[0] = toupper(sentence[0]); // access the first char in the string like an array

		puts(sentence);

		// the initial thought
		// you can use a 2 dimensional array if you need to save each sentence
		// select randoms
		// randomNumber1 = rand() % 100;
		// sentence[][i] = "article noun verb preposition article noun";
	}

	return 1;
}

