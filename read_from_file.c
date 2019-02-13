#include "main.h"

void read_from_file (
		FILE * file_to_read,
		char * buff ,
		bool * is_eol ){

	int char_from_file, i;

	if (*is_eol == true){ /*if eol has been reached then return zero till manual reset*/
		buff[0] = '\0'; }
	else{

		for ( i = 0 ; i < MAX_STRING_LENGTH-1 ; i++ ){
			char_from_file = getc ( file_to_read );
			if (char_from_file == ',' ) {
				buff[i] = '\0';	
				break;
			}
			else if (char_from_file == '\n'){
				*is_eol = true;
				buff[i] = '\0';	
				break;
			}
			else {
				buff[i] = char_from_file ;
			}
		}
	}
	return;	
}
