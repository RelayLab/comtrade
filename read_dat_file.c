/*file : read_dat_file.c
 * this function intended to read contents of
 * dat file into the memory*/
#include "main.h"

void read_dat_file (
		dat_file_2003 * dat_file ,
		char * filename_prefix ,
		int nA ,
		int nD ,
		int rows ) {

	/*open dat file stream to read from*/

	char filename [256];
	strcpy ( filename , filename_prefix );
	strcat ( filename , ".dat" );
	FILE * file_to_read = fopen ( filename , "r" );
	/*temp buffer for saving data from text file*/
	char buff [MAX_STRING_LENGTH];

	dat_file -> data_lines = malloc (  sizeof ( data_line ) * rows  );
	int i,j;
	/*is_eol var is not used here,
	 * provided only for compatibility with read_cfg_file()*/
	bool is_eol; 

	for ( i = 0 ; i < rows ; i++ ){

		is_eol = false;

		read_from_file ( file_to_read , buff , &is_eol );
		dat_file -> data_lines [i] . n = atoi ( buff );

		read_from_file ( file_to_read , buff , &is_eol );
		dat_file -> data_lines [i] . timestamp = atof ( buff );

		dat_file -> data_lines [i] . A_values = malloc ( sizeof (double) * nA );
		dat_file -> data_lines [i] . D_values = malloc ( sizeof (int) * nD );
		for ( j = 0 ; j < nA ; j++ ){
			read_from_file ( file_to_read , buff , &is_eol );
			dat_file -> data_lines [i] . A_values [j] = atof ( buff );
		}
		for ( j = 0 ; j < nD ; j++ ){
			read_from_file ( file_to_read , buff , &is_eol );
			dat_file -> data_lines [i] . D_values [j] = atoi ( buff );
		}

	}
	
	fclose ( file_to_read ); 
	
	return;
}
