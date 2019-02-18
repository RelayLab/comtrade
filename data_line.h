#ifndef DATA_LINE_H
#define DATA_LINE_H 1

struct data_line {
	/*sample number
	 * critical, integer, numeric
	 * 1 to 10 chars
	 * val from 1 to 9 999 999 999 */
	int n;

	/*timestamp
	 * critical if nrates and samp = 0 both
	 * integer, numeric,
	 * 1 to 13 chars */
	int timestamp;

	double * A_values;
	int * D_values;
	
};
typedef struct data_line  data_line;
#endif
