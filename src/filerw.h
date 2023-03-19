///////////////////////////////////////////


// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


///////////////////////////////////////////


// prototypes
char **read_from_file(char const*);


///////////////////////////////////////////


// reads lines from a file
#define READ_BUFFER_SIZE 64
char **read_from_file(char const *filename)
{
	// create file pointer
	FILE *fp;
	fp = fopen(filename, "r");
	if (!fp) {
		perror("Error");
		exit(EXIT_FAILURE);
	}

	// init variables
    char *line = NULL;
    size_t line_len = 0;
    size_t buffer_size = READ_BUFFER_SIZE;
    char **arr = (char **)malloc(sizeof(char *) * buffer_size);

	// getline loop
    int pos = 0;
    while(getline(&line, &line_len, fp) != -1) {
		// if first char is not alphanumeric, skip
		// for skipping empty lines or lines containing spaces, tabs, etc.
		if (!isalpha(line[0])) continue;

		// add line to array
		arr[pos++] = strdup(line);

		// if buffer fills, increase its size
        if (pos >= buffer_size) {
            buffer_size += READ_BUFFER_SIZE;
            arr = (char **)realloc(arr, sizeof(char *) * buffer_size);
        }
    }
	// place NULL at the end of the array
	// for ease in looping later
	arr[pos] = NULL;

	// tidy up and return array
	fclose(fp);
	free(line);
	return arr;
}

/*
STATEMENT OF NON-PLAGIARISM
		I hereby declare that all information in this assignment has been obtained and presented in
		accordance with academic rules and ethical conduct and the work I am submitting in this
		document, except where I have indicated, is my own work.
		Student Name: Hephzibah Bode-Favours
		Student Number: 21344221
		Date: 15/03/2023
*/
