#include "main.h"

void read_dat_file ( dat_file_2003 * dat_file , char * filename_prefix) {

	/*open cfg file to read from*/

	char filename [256];
	strcpy ( filename , filename_prefix );
	strcat ( filename , ".dat" );
	FILE * file_to_read = fopen ( filename , "r" );
	/*temp buffer for saving data from text file*/
	char buff [MAX_STRING_LENGTH];

	int i = 0;
	while (  !feof( file_to_read )  ) {
		char char_from_file = fgetc ( file_to_read ) ;
		if ( char_from_file == ',' ) {
			buff[i] = '\0' ;
		}
		else if ( char_from_file == '\n' ) {
			buff[i] = '\0' ;
		}
		else {
			buff[i] = char_from_file ;
		}
	}
	
	
	return;
}
