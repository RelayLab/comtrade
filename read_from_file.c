#include "main.h"

void read_from_file ( FILE * file_to_read, char * buff ){
	int char_from_file, i;

	for ( i = 0 ; i < MAX_STRING_LENGTH-1 ; i++ ){
		char_from_file = getc ( file_to_read );
		if ( (char_from_file == ',' ) || (char_from_file == '\n') ) {
			buff[i] = '\0';	
			break;
		}
		else {
			buff[i] = char_from_file ;
		}
	}
	
}
