/**************************************************
 *File utilities including read file and write file
 *
 *@author Rose Ault
 *@version Fall 2018
 * ***********************************************/



#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

/*************************************************
 * Find the size, allocate memory, and read file into memory
 *
 * @param filename a pointer to file to be read
 * @param buffer a pointer to a pointer to the 
 * 	space the file will be read to
 * @return size of file
 *************************************************/
int read_file( char* filename, char **buffer){
	//handle error if filename does not exist
	if(filename==NULL){
	fprintf(stderr, "ERROR: file pointer is null in read_file");
	return(-1);
	}

	//find size of filename
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;
	printf("%i", size);

	//handle error if file is size 0
	if(size ==0){
		fprintf(stderr, "ERROR MESSAGE: size = 0 in read_file ");
	}
	FILE* fp = fopen(filename,"r");

	//create space in memory
	if((buffer = (char**) malloc(size))==NULL){
		//handle error is malloc fails
		fprintf(stderr, "ERROR MESSAGE: malloc fail in read_file");
		return(-1);
	}
	
	//read file into buffer
	fread(buffer, size, 1, fp);	
	
	//return size of file in bytes
	return size;

}

/*************************************************
 * Write file to filename
 *
 * @param filename pointer to where to write to
 * @param buffer pointer to contents to be written
 *@param size Size of file 
 * **********************************************/

int write_file( char* filename, char *buffer, int size){
	//filename is where to write to , buffer is contents to be written,
	
	//create file pointer to where to write to
	FILE* fp = fopen(filename, "r");
	
	
	//write buffer to filename
	fwrite(buffer, size, 1, fp);

	return 1;
}

