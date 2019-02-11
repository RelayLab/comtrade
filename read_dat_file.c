#include "main.h"

void read_dat_file (
		dat_file_2003 * dat_file ,
		char * filename_prefix ,
		int columns ,
		int rows ) {

	/*open dat file to read from*/

	char filename [256];
	strcpy ( filename , filename_prefix );
	strcat ( filename , ".dat" );
	FILE * file_to_read = fopen ( filename , "r" );
	/*temp buffer for saving data from text file*/
	char buff [MAX_STRING_LENGTH];

	dat_file -> data_lines = malloc (  sizeof ( data_line ) * rows  );
	int i = 0;
	bool is_eol = false;
	for ( i = 0 ; i < rows ; i++ ){

		read_from_file ( file_to_read , buff , &is_eol );
		dat_file -> data_line [i] -> n = atoi ( buff );

		read_from_file ( file_to_read , buff , &is_eol );
		dat_file -> data_line [i] -> timestamp = atof ( buff );

		for ( j = 0 ; j < nA ; j++ ){
			read_from_file ( file_to_read , buff , &is_eol );
			dat_file -> data_line [i] -> a_values [j] = atof ( buff );
		}
		for ( j = 0 ; j < nD ; j++ ){
			read_from_file ( file_to_read , buff , &is_eol );
			dat_file -> data_line [i] -> D_values [j] = atoi ( buff );
		}


	}
	
	
	return;
}
