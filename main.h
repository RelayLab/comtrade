#ifndef MAIN_H
#define MAIN_H

#include "cfg_file_2003.h"
#include "dat_file_2003.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 512
#define true 1
#define false 0
typedef unsigned int bool;

/*functions declarations*/
void read_cfg_file ( cfg_file_2003 * cfg_file , char * filename) ;
void read_dat_file (
		dat_file_2003 * dat_file ,
		char * filename_prefix ,
		int columns ,
		int rows );

void read_from_file ( FILE * file_to_read, char * buff , bool *is_eol );

void read_analog_channels ( 
		FILE * file_to_read,
		char * buff,
		cfg_file_2003 * cfg_file,
		bool *is_eol);

void read_digital_channels ( 
		FILE * file_to_read,
		char * buff,
		cfg_file_2003 * cfg_file,
		bool *is_eol);

void read_sampling_data ( 
		FILE * file_to_read,
		char * buff,
		cfg_file_2003 * cfg_file,
		bool *is_eol);


#endif

