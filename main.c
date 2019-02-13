#include "main.h"

/* this executable transforms contents of comtrade record to csv file
 * in order to plot the contents*/

int main ( int argc, char ** argv ) {

	/*the program accepts only 1 arg, prefix name of .cfg and .dat file,
	 * they should be similar*/
	if ( argc != 2 ){
		fprintf ( stderr , "%s\n", "Wrong number of arguments proveded!" );
		return 0;
	}
	
	char * filename = argv[1];

	cfg_file_2003 * cfg_file = malloc ( sizeof ( cfg_file_2003 ) );
	read_cfg_file ( cfg_file , filename );

	/*for simplicity of the program, .dat file dimensions calculated
	 * via .cfg file contents */

	/*each line represents number of the line, timestamp and TT samples of data*/
	/*number of lines equal to the last sampling data "endsamp" value*/
	dat_file_2003 * dat_file = malloc (  sizeof ( dat_file_2003 )  );
	int rows = cfg_file -> s_data [ cfg_file -> nrates - 1 ].endsamp;
	dat_file -> data_lines_count = rows ; 

	read_dat_file ( dat_file, filename , cfg_file -> nA , cfg_file -> nD , rows );

	write_to_csv ( cfg_file , dat_file , filename );

	free ( cfg_file -> a_channels );
	free ( cfg_file -> d_channels );
	free ( cfg_file -> s_data );
	free ( cfg_file ) ;
	free ( dat_file ) ;
}
