#ifndef DAT_FILE_2003_H
#define DAT_FILE_2003_H 1

/*this file has pretty simple structure
 * compared to the cfg file
 * each line contains specific timestamp data
 * number of lines equals to the last "endstamp"
 * field in the cfg file*/

#include "data_line.h"

struct dat_file_2003{

	data_line * data_lines;
	
};

typedef struct dat_file_2003  dat_file_2003;

#endif
