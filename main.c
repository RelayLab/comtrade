#include "cfg_file_struct.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 1024

int main(){

	char filename[] = "example.cfg";
	char buff [MAX_STRING_LENGTH+1];
	FILE * file_to_read = fopen ( filename , "r" );
	cfg_file_struct * cfg_file = malloc ( sizeof ( cfg_file ) );

	fgets ( buff , MAX_STRING_LENGTH , file_to_read );
	
	
	fclose( file_to_read ) ;
	free ( cfg_file );
	return 0;
};
