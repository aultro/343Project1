#include <sys/stat.h>

int read_file( char* filename, char **buffer ){
		//filename is file to be read, **buffer:place to store contents of read
	//finding size
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	//create space in memory
	//
	//fill that space in memory with the file it read
	//
	//return size of file in bytes
}


int write_file( char* filename, char *buffer, int size){
	//filename is file to be written, *buffer where to write to,in project1 will be output file name, size of file
	//create space in memory at *buffer???????
	//
	//write filename to that space
	//
	//
	


	//check that it completed correctly?
}

