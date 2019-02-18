/* file: main.c
 * this executable transforms contents of a comtrade record to a csv file
 * in order to plot the contents
 * the main idea was to organize .cfg and .dat struct
 * according to the IEEE37.2013 standart and then read or
 * write their contents to other file formats*/

#include "main.h"


int main ( int argc, char ** argv ) {

	/*the program accepts only 1 arg, prefix name of .cfg and .dat file,
	 * so they should be similar*/
	if ( argc != 2 ){
		fprintf ( stderr , "%s\n", "Wrong number of arguments proveded!" );
		return 0;
	}
	
	char * filename = argv[1];

	/* these are struct for holding the contents of files*/
	cfg_file_2013 * cfg_file = malloc ( sizeof ( cfg_file_2013 ) );
	dat_file_2013 * dat_file = malloc ( sizeof ( dat_file_2013 )  );

	read_cfg_file (
			cfg_file , 	/*pointer to .cfg struct*/
			filename );	/*file to open*/

	/*for simplicity of the program, .dat file dimensions calculated
	 * via .cfg file contents */

	/*each line represents number of the line, timestamp and TT samples of data*/
	/*number of lines equal to the last sampling data "endsamp" value*/
	dat_file -> data_lines_count  =
		cfg_file -> s_data [ cfg_file -> nrates - 1 ].endsamp;

	read_dat_file (
			dat_file , 						/*pointer to .dat struct*/
			filename , 						/*file to open*/
			cfg_file -> nA ,				/*number of analog channels*/
			cfg_file -> nD ,				/*number of digital channels*/
			dat_file -> data_lines_count);	/*number of samples in file*/

	write_to_csv ( cfg_file , dat_file , filename  );

	free ( cfg_file -> a_channels );
	free ( cfg_file -> d_channels );
	free ( cfg_file -> s_data );
	free ( cfg_file ) ;
	free ( dat_file ) ;
}
