#include "main.h"

int main(){

	char filename[] = "./example.cfg";
	char buff [MAX_STRING_LENGTH];
	/*open cfg file to read from*/
	FILE * file_to_read = fopen ( filename , "r" );
	cfg_file_2003 * cfg_file = malloc ( sizeof ( cfg_file_2003 ) );

	/*line 1*/
	/*the following lines only reads text from file
	 * and fills them to appropriate fields of cfg file
	 * for string strcpy is used, for other types just
	 * assigning from approriate data type conversion*/
	read_from_file ( file_to_read , buff );
	strcpy (cfg_file -> station_name , buff );

	read_from_file ( file_to_read , buff );
	strcpy (cfg_file -> rec_dev_id , buff );

	read_from_file ( file_to_read , buff );
	cfg_file -> rev_year = atoi ( buff );

	/*line 2*/
	/*again, but nA and nD fields in the cfg file
	 * are omitted wit additional line of code*/
	read_from_file ( file_to_read , buff );
	cfg_file -> TT = atoi ( buff );

	read_from_file ( file_to_read , buff );
	buff [ strlen( buff ) ] = '\0' ; /*omit the last char as it should be A or D*/
	cfg_file -> nA = atoi ( buff );

	read_from_file ( file_to_read , buff );
	buff [ strlen( buff ) ] = '\0' ; 
	cfg_file -> nD = atoi ( buff );

	/*line 3*/
	/* this code creates array of analog channels according to the nA number
	 * and fills into them info from text cfg file*/
	cfg_file -> a_channels = malloc (  sizeof ( analog_channel ) * cfg_file -> nA );
	int i = 0;
	for ( i = 0 ; i < cfg_file -> nA ; i++ ){

		read_from_file ( file_to_read , buff );
		cfg_file ->  a_channels [ i ] . An = atoi ( buff );

		read_from_file ( file_to_read , buff );
		strcpy (cfg_file ->  a_channels [ i ] . ch_id , buff );

		read_from_file ( file_to_read , buff );
		strcpy (cfg_file ->  a_channels [ i ] . ph , buff );

		read_from_file ( file_to_read , buff );
		strcpy (cfg_file ->  a_channels [ i ] . ccbm , buff );

		read_from_file ( file_to_read , buff );
		strcpy (cfg_file ->  a_channels [ i ] . uu , buff );

		read_from_file ( file_to_read , buff );
		cfg_file ->  a_channels [ i ] . a = atof ( buff );

		read_from_file ( file_to_read , buff );
		cfg_file ->  a_channels [ i ] . b = atof ( buff );

		read_from_file ( file_to_read , buff );
		cfg_file ->  a_channels [ i ] . skew = atof ( buff );

		read_from_file ( file_to_read , buff );
		cfg_file ->  a_channels [ i ] . min = atof ( buff );

		read_from_file ( file_to_read , buff );
		cfg_file ->  a_channels [ i ] . max = atof ( buff );

		read_from_file ( file_to_read , buff );
		cfg_file ->  a_channels [ i ] . primary = atof ( buff );

		read_from_file ( file_to_read , buff );
		cfg_file ->  a_channels [ i ] . secondary = atof ( buff );

		read_from_file ( file_to_read , buff );
		cfg_file ->  a_channels [ i ] . PS = buff[0];
	}
	
	/*test area*/
	printf( "%s\n", cfg_file -> station_name );
	printf( "%s\n", cfg_file -> rec_dev_id );
	printf( "%d\n", cfg_file -> rev_year );
	printf( "%d\n", cfg_file -> TT );
	printf( "%d\n", cfg_file -> nA );
	printf( "%d\n", cfg_file -> nD );
	fclose( file_to_read ) ;

	free ( cfg_file -> a_channels );
	free ( cfg_file );

	return 0;
};
