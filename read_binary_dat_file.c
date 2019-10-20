/*file : read_binary_dat_file.c
 * this function intended to read contents of
 * dat file into the memory*/
#include "main.h"

void read_binary_dat_file (
		dat_file_2013 * dat_file ,
		char * filename_prefix ,
		int nA ,
		int nD ,
		int N,
		int rows ) {

	/*open dat file stream to read from*/

	char filename [256];
	strcpy ( filename , filename_prefix );
	strcat ( filename , ".dat" );

	/*"b" (binary) mode is used for reading*/
	FILE * file_to_read = fopen ( filename , "rb" );
	/*temp buffer for saving data from text file*/
	char buff [MAX_STRING_LENGTH];

	dat_file -> data_lines = malloc (  sizeof ( data_line ) * rows  );
	int i,j;

	/*is_eol var is not used here,
	 * provided only for compatibility with read_from_file()*/
	bool is_eol; 
	/*each timestep in the dat file represented with fixed number of bytes 
	 * by an expression at page 26
	 * nD_rounded is calculated by dividing nD by 16 and rounding up*/
	int nD_rounded =  ( nD%16  == 0 ) ? nD/16 : nD/16+1 ;
	int single_row_size = ( nA * N ) + (  2 * ( nD_rounded )  + 4 + 4 );

	for ( i = 0 ; i < rows ; i++ ){

		is_eol = false;

		dat_file -> data_lines [i] . n = 
			read_from_binary_file ( file_to_read , N );

		dat_file -> data_lines [i] . timestamp = 
			read_from_binary_file ( file_to_read , N );

		dat_file -> data_lines [i] . A_values = malloc ( sizeof (double) * nA );
		dat_file -> data_lines [i] . D_values = malloc ( sizeof (int) * nD );
		for ( j = 0 ; j < nA ; j++ ){
			dat_file -> data_lines [i] . A_values [j] = 
				read_from_binary_file ( file_to_read , N );
		}
		for ( j = 0 ; j < nD ; j++ ){
			dat_file -> data_lines [i] . D_values [j] = 
				read_from_binary_file ( file_to_read , N );
		}

	}
	
	fclose ( file_to_read ); 
	
	return;

}
