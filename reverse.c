
/***************************************************************
 *main method that calls read_file, reverses
 *
 * @param input_filename file to be reversed
 * @param output_filename where to write the reverse to 
 *
 * *************************************************************/

#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	if(argc<3){
		fprintf(stderr, "ERROR, insufficient parameters");
	}

	//names for the arguments and a place for the reversed contents
	char* input_filename= argv[1];
	char* output_filename= argv[2];
	char* reversed;
	
	//create pointer to fill with file contents
	char** contents;

	//integer variables
	int bytes_read, i;

	//reads the file and returns bytes read.
		bytes_read = read_file(input_filename, contents);
	
	////reverse contents into reversed
	for(i=0; i <bytes_read; i++){
		reversed[i]=*contents[bytes_read-i];
	}

	//take that reverse and write it to output 
	write_file(output_filename, reversed, bytes_read);
	free(contents);
	return 1;
}
