#include "main.h"

void read_sampling_data ( 
		FILE * file_to_read,
		char * buff,
		cfg_file_2003 * cfg_file,
		bool * is_eol){

	cfg_file -> s_data = 
		malloc (  sizeof ( sampling_data ) * cfg_file -> nrates );
	int i = 0;
	for ( i = 0 ; i < cfg_file -> nrates ; i++ ){

		*is_eol = false ; 

		read_from_file ( file_to_read , buff , is_eol );
		cfg_file ->  s_data [ i ] . samp = atof ( buff );

		read_from_file ( file_to_read , buff , is_eol );
		cfg_file ->  s_data [ i ] . endsamp = atoi ( buff );
	}
}

