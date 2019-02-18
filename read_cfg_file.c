/* file: read_cfg_file.c
 * this function reads contents of a file with a given filename
 * into .cfg struct*/

#include "main.h"

void read_cfg_file (
		cfg_file_2013 * cfg_file , /*pointer to .cfg struct*/ 
		char * filename_prefix ) { /*file to open*/        

	/*open cfg file to read from*/

	char filename [MAX_FILENAME_LENGTH];
	strcpy ( filename , filename_prefix );
	strcat ( filename , ".cfg" );

	/*open cfg file to read from*/
	FILE * file_to_read = fopen ( filename , "r" );
	if (!file_to_read){
		fprintf ( stderr , "CFG file with given name does not exist!\n" );
	}

	/*temp buffer for saving data from text file*/
	char buff [MAX_STRING_LENGTH];

	/*a special variable to indicate that end of line has been reached
	 * in case the cfg file being not separated with commas properly.
	 * RESET FOR EACH NEW LINE!*/
	bool is_eol_value = false ;
	/* here we use not value directly but
	 * is_eol poiner in order to reduce complexity of the following lines
	 * because we will pass this variable through reference*/
	bool * is_eol = & is_eol_value;

	/*the following code only reads text from file
	 * and fills the lines to appropriate fields of cfg file
	 * for string strcpy is used, for other types just
	 * assigning from approriate data type conversion*/
	/* TODO: should we use a concept of a LINE in cfg_struct? I think no*/
	/* TODO: with strcpy the regions of data may overlap. How can we check it
	 * but avoiding the usage of fixed var lengths and additional .cfg lines?*/

	/*line 1*/
	read_from_file ( file_to_read , buff , is_eol );
	strcpy (cfg_file -> station_name , buff );

	read_from_file ( file_to_read , buff , is_eol );
	strcpy (cfg_file -> rec_dev_id , buff );

	read_from_file ( file_to_read , buff , is_eol );
	cfg_file -> rev_year = atoi ( buff );

	/*line 2*/
	*is_eol = false ; 

	/*same again, but nA and nD fields in the cfg file
	 * are omitted with the additional line of code*/
	read_from_file ( file_to_read , buff , is_eol );
	cfg_file -> TT = atoi ( buff );

	read_from_file ( file_to_read , buff , is_eol );
	buff [ strlen( buff ) ] = '\0' ; /*omit the last char as it should be A or D*/
	cfg_file -> nA = atoi ( buff );

	read_from_file ( file_to_read , buff , is_eol );
	buff [ strlen( buff ) ] = '\0' ; 
	cfg_file -> nD = atoi ( buff );

	/*line 3...3+nA*/
	*is_eol = false ; 

	/* this code creates array of analog channels according to the nA number
	 * and fills into them info from text cfg file*/
	/*this function read_analog_channels is only user for the brevity*/
	read_analog_channels ( file_to_read, buff, cfg_file, is_eol );

	/*line 3+nA...3+TT*/
	/*simultaneously for the digital channels*/
	*is_eol = false ; 

	read_digital_channels ( file_to_read, buff, cfg_file, is_eol );

	/*line 4+TT*/
	*is_eol = false ; 

	read_from_file ( file_to_read , buff , is_eol );
	cfg_file -> lf = atof ( buff );

	/*line 5+TT*/
	*is_eol = false ; 

	read_from_file ( file_to_read , buff , is_eol );
	cfg_file -> nrates = atoi ( buff );

	/*line 6+TT..6+TT+nrates*/
	*is_eol = false ; 

	read_sampling_data ( file_to_read, buff, cfg_file, is_eol );

	/*line 7+TT+nrates*/
	*is_eol = false ; 

	/* TODO: add following rows*/

	fclose( file_to_read ) ;

	return;
}
