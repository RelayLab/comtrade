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

	/*at first, we print time info row
	fprintf ( file_to_write, "time;" );
	for ( i = 0 ; i < dat_file -> data_lines_count ; i++ ){
		fprintf ( file_to_write, "%f;" , dat_file -> data_lines [i] . timestamp cfg_file -> a_channels [i]  . ch_id );
	};
	*/

	/* at second, we print analog channels as rows */
	for ( i = 0 ; i < cfg_file -> nA ; i++ ){
		/* print name of the channel
		 * then analog channels samples */
		fprintf ( file_to_write, "%s;" , cfg_file -> a_channels [i]  . ch_id );

		for ( j = 0 ; j < dat_file -> data_lines_count ; j++ ){
			value_to_print =
				(dat_file -> data_lines [j]  . A_values [ i ] )
				* 
				(cfg_file -> a_channels [ i ] . a ) 
				+
				(cfg_file -> a_channels [ i ] . b ) ;

			fprintf ( file_to_write , "%f;" , value_to_print );
		}

		fprintf ( file_to_write , "\n" );
	}


	/* then performing the same actions on digital channels */
	for ( i = 0 ; i < cfg_file -> nD ; i++ ){
		/* print name of the channel
		 * then digital channels samples */
		fprintf ( file_to_write, "%s;" , cfg_file -> d_channels [i]  . ch_id );

		for ( j = 0 ; j < dat_file -> data_lines_count ; j++ ){
			fprintf ( file_to_write , "%d;" , dat_file -> data_lines [ j ] . D_values [ i ] );
		}
		fprintf ( file_to_write , "\n" );
	}


	fclose ( file_to_write );

	
}
