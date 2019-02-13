/* file : write_to_csv.c
 * this function writes record data from cfg and dat structs
 * held in a memory to csv file with the same name.
 * the structure of the csv file is similar to dat except
 * than it contains channel names and actual recorded values
 * ( not the scaled and divisioned ones )*/


#include "main.h"

void write_to_csv (
		cfg_file_2003 * cfg_file,
		dat_file_2003 * dat_file ,
		char * filename_prefix ) {

	/* open a stream for writing */
	char filename [256];
	strcpy ( filename , filename_prefix );
	strcat ( filename , ".csv" );
	FILE * file_to_write = fopen ( filename , "w" );

	int i , j;
	double value_to_print;


	/*the first row with names*/
	fprintf ( file_to_write, "time;" );

	for ( i = 0 ; i < cfg_file -> nA ; i++ ){
		fprintf ( file_to_write, "%s;" , cfg_file -> a_channels [i]  . ch_id );
	}
	for ( i = 0 ; i < cfg_file -> nD ; i++ ){
		fprintf ( file_to_write, "%s;" , cfg_file -> d_channels [i]  . ch_id );
	}

	fprintf ( file_to_write , "\n" );

	/*for following rows we print timestamp column and then
	 * all the analog and discrete vals columns*/
	for ( i = 0 ; i < dat_file -> data_lines_count ; i++ ){

		fprintf ( file_to_write , "%d;" , dat_file -> data_lines [i] . timestamp );

		/*analog_vals*/
		for ( j = 0 ; j < cfg_file -> nA ; j++ ){
			value_to_print =
				(dat_file -> data_lines [ i ]  . A_values [ j ] )
				* 
				(cfg_file -> a_channels [ j ] . a ) 
				+
				(cfg_file -> a_channels [ j ] . b ) ;

			fprintf ( file_to_write , "%f;" , value_to_print );
		}

		/*discrete vals*/
		for ( j = 0 ; j < cfg_file -> nD ; j++ ){
			fprintf ( file_to_write , "%d;" , dat_file -> data_lines [ i ] . D_values [ j ] );
		}
			fprintf ( file_to_write , "\n" );

	}


	fclose ( file_to_write );

	
}
