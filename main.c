#include "main.h"

int main ( int argc, char ** argv ) {

	if ( argc != 2 ){
		fprintf ( stderr , "%s\n", "Wrong number of arguments proveded!" );
		return 0;
	}
	
	char * filename = argv[1];

	cfg_file_2003 * cfg_file = malloc ( sizeof ( cfg_file_2003 ) );
	read_cfg_file ( cfg_file , filename );
	/*open cfg file to read from*/
	FILE * file_to_read = fopen ( filename , "r" );
	/*temp buffer for saving data from text file*/
	char buff [MAX_STRING_LENGTH];

	/*line 1*/
	bool is_eol = false ; /*a special variable to indicate that end of line has been reached in case the cfg file being not separated with commas properly. Reset for each new line*/


	/*the following lines only reads text from file
	 * and fills them to appropriate fields of cfg file
	 * for string strcpy is used, for other types just
	 * assigning from approriate data type conversion*/
	read_from_file ( file_to_read , buff , &is_eol );
	strcpy (cfg_file -> station_name , buff );

	read_from_file ( file_to_read , buff , &is_eol );
	strcpy (cfg_file -> rec_dev_id , buff );

	read_from_file ( file_to_read , buff , &is_eol );
	cfg_file -> rev_year = atoi ( buff );

	/*line 2*/
	is_eol = false ; 

	/*again, but nA and nD fields in the cfg file
	 * are omitted wit additional line of code*/
	read_from_file ( file_to_read , buff , &is_eol );
	cfg_file -> TT = atoi ( buff );

	read_from_file ( file_to_read , buff , &is_eol );
	buff [ strlen( buff ) ] = '\0' ; /*omit the last char as it should be A or D*/
	cfg_file -> nA = atoi ( buff );

	read_from_file ( file_to_read , buff , &is_eol );
	buff [ strlen( buff ) ] = '\0' ; 
	cfg_file -> nD = atoi ( buff );

	/*line 3...3+nA*/
	is_eol = false ; 

	/* this code creates array of analog channels according to the nA number
	 * and fills into them info from text cfg file*/
	/*this function read_analog_channels is only user for the brevity*/
	read_analog_channels ( file_to_read, buff, cfg_file, &is_eol );

	/*line 3+nA...3+TT*/
	/*simultaneously for the digital channels*/
	is_eol = false ; 

	read_digital_channels ( file_to_read, buff, cfg_file, &is_eol );

	/*line 4+TT*/
	is_eol = false ; 

	read_from_file ( file_to_read , buff , &is_eol );
	cfg_file -> lf = atof ( buff );

	/*line 5+TT*/
	is_eol = false ; 

	read_from_file ( file_to_read , buff , &is_eol );
	cfg_file -> nrates = atoi ( buff );

	/*line 6+TT..6+TT+nrates*/
	is_eol = false ; 

	read_sampling_data ( file_to_read, buff, cfg_file, &is_eol );

	/*line 7+TT+nrates*/
	is_eol = false ; 

	fclose( file_to_read ) ;

	free ( cfg_file -> a_channels );
	free ( cfg_file );

	return 0;
};
