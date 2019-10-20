#include "main.h"

int read_from_binary_file (
		FILE * file_to_read,
		int N){

	char LSB, MSB, next_to_LSB, next_to_MSB ;
	int value = 0;

	if ( N == 2 ) {
		LSB = getc ( file_to_read );
		MSB = getc ( file_to_read );
		value =   MSB * 256 + LSB;
	}
	else{
		LSB = getc ( file_to_read );
		next_to_LSB = getc ( file_to_read );
		next_to_MSB = getc ( file_to_read );
		MSB = getc ( file_to_read );
		value = MSB*256*256*256 + next_to_MSB *256*256 + next_to_LSB * 256 + LSB;

	}
	return value;	
}
