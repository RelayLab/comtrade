#ifndef MAIN_H
#define MAIN_H

#include "cfg_file_2013.h"
#include "dat_file_2013.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 512 /*field of cfg file should not be very long*/
#define MAX_FILENAME_LENGTH 512+8 /*so we do not exepect very long names*/
#define true 1
#define false 0
typedef unsigned int bool;

/*functions declarations*/
void read_cfg_file (
		cfg_file_2013 * cfg_file , /*pointer to .cfg struct*/ 
		char * filename_prefix ) ; /*file to open*/        

void read_ascii_dat_file (
		dat_file_2013 * dat_file ,
		char * filename_prefix ,
		int nA ,
		int nD ,
		int rows );

void read_binary_dat_file (
		dat_file_2013 * dat_file ,
		char * filename_prefix ,
		int nA ,
		int nD ,
		int N,
		int rows );

void read_from_file ( FILE * file_to_read, char * buff , bool *is_eol );
int read_from_binary_file ( FILE * file_to_read, int N );

void read_analog_channels ( 
		FILE * file_to_read,
		char * buff,
		cfg_file_2013 * cfg_file,
		bool *is_eol);

void read_digital_channels ( 
		FILE * file_to_read,
		char * buff,
		cfg_file_2013 * cfg_file,
		bool *is_eol);

void read_sampling_data ( 
		FILE * file_to_read,
		char * buff,
		cfg_file_2013 * cfg_file,
		bool *is_eol);

void write_to_csv (
		cfg_file_2013 * cfg_file,
		dat_file_2013 * dat_file ,
		char * filename_prefix ) ;


#endif

