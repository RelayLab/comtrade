#include "main.h"

void read_analog_channels ( 
		FILE * file_to_read,
		char * buff,
		cfg_file_2013 * cfg_file,
		bool * is_eol){

	cfg_file -> a_channels = malloc (  sizeof ( analog_channel ) * cfg_file -> nA );
	int i = 0;
	for ( i = 0 ; i < cfg_file -> nA ; i++ ){

		*is_eol = false ; 

		read_from_file ( file_to_read , buff , is_eol );
		cfg_file ->  a_channels [ i ] . An = atoi ( buff );

		read_from_file ( file_to_read , buff , is_eol );
		strcpy (cfg_file ->  a_channels [ i ] . ch_id , buff );

		read_from_file ( file_to_read , buff , is_eol );
		strcpy (cfg_file ->  a_channels [ i ] . ph , buff );

		read_from_file ( file_to_read , buff , is_eol );
		strcpy (cfg_file ->  a_channels [ i ] . ccbm , buff );

		read_from_file ( file_to_read , buff , is_eol );
		strcpy (cfg_file ->  a_channels [ i ] . uu , buff );

		read_from_file ( file_to_read , buff , is_eol );
		cfg_file ->  a_channels [ i ] . a = atof ( buff );

		read_from_file ( file_to_read , buff , is_eol );
		cfg_file ->  a_channels [ i ] . b = atof ( buff );

		read_from_file ( file_to_read , buff , is_eol );
		cfg_file ->  a_channels [ i ] . skew = atof ( buff );

		read_from_file ( file_to_read , buff , is_eol );
		cfg_file ->  a_channels [ i ] . min = atof ( buff );

		read_from_file ( file_to_read , buff , is_eol );
		cfg_file ->  a_channels [ i ] . max = atof ( buff );

		read_from_file ( file_to_read , buff , is_eol );
		cfg_file ->  a_channels [ i ] . primary = atof ( buff );

		read_from_file ( file_to_read , buff , is_eol );
		cfg_file ->  a_channels [ i ] . secondary = atof ( buff );

		read_from_file ( file_to_read , buff , is_eol );
		cfg_file ->  a_channels [ i ] . PS = buff[0];
	}
	
}

