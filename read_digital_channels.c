#include "main.h"

void read_digital_channels ( 
		FILE * file_to_read,
		char * buff,
		cfg_file_2003 * cfg_file,
		bool * is_eol){

	cfg_file -> d_channels = malloc (  sizeof ( digital_channel ) * cfg_file -> nD );
	int i = 0;
	for ( i = 0 ; i < cfg_file -> nD ; i++ ){

		*is_eol = false ;

		read_from_file ( file_to_read , buff , is_eol );
		cfg_file ->  d_channels [ i ] . Dn = atoi ( buff );

		read_from_file ( file_to_read , buff , is_eol );
		strcpy (cfg_file ->  d_channels [ i ] . ch_id , buff );

		read_from_file ( file_to_read , buff , is_eol );
		strcpy (cfg_file ->  d_channels [ i ] . ph , buff );

		read_from_file ( file_to_read , buff , is_eol );
		strcpy (cfg_file ->  d_channels [ i ] . ccbm , buff );

		read_from_file ( file_to_read , buff , is_eol );
		cfg_file ->  d_channels [ i ] . y = atof ( buff );
	}
	
}

