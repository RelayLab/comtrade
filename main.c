#include "main.h"

int main ( int argc, char ** argv ) {

	if ( argc != 2 ){
		fprintf ( stderr , "%s\n", "Wrong number of arguments proveded!" );
		return 0;
	}
	
	char * filename = argv[1];

	cfg_file_2003 * cfg_file = malloc ( sizeof ( cfg_file_2003 ) );
	read_cfg_file ( cfg_file , filename );
	read_dat_file ( cfg_file , filename );

}
