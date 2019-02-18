/*this is a header file
 containing description of the COMTRADE 2003 standart
 for measuring records*/

/*this is header files, used by this file
 * enclosed in special "header brackets"
 * in order to include them only once and
 * in a correct way*/
#include "analog_channel.h"
#include "digital_channel.h"
#include "sampling_rate.h"

#ifndef CFG_FILE_STRUCT_H
#define CFG_FILE_STRUCT_H 1

struct cfg_file_struct{

	/*the first line of the cfg specifies next three fields:
	 *
	 * critical
	 * any general short data about
	 * max length = 64 characters*/
	char station_name[64];

	/*critical
	 * any info about recording device*/
	char rec_dev_id[64];

	/*critical
	 * COMTRADE standart version, which is used across the file
	 * can only be equal to 1991, 1999, 2013
	 * if empty counts as 1991
	 */
	int rev_year;
	
	/*the second line contains general data about recorded channels
	 *
	 * critical
	 * total number of channels from 1 to 999999
	 * should be equal to the sum of nA and nD variables, e.g.
	 * analog and digital channels*/
	int TT;

	/*critical
	 * total number of analog and digital channels
	 * alphanumeric value from 0D to 999999D*/
	char nA[7];
	char nD[7];

	/*following rows represent analog channels
	 * lines quantity should be equal to nA variable value (in decimal)
	 * this struct represenst each line and defined in separate file
	 * if nA = 0 then no analog channels provided hence there is no rows
	 * here they presented as a variable length array*/
	analog_channel * a_channels;

	/*simulateosly, the next group of rows
	 * represents digital (discrette) signals
	 * and their number should be equal to nD variable*/
	digital_channel * d_channels;
	
	/*the next line contains only info about power system frequency
	 * from which samples in analog and digital channels
	 * were obtained (usually 50 Hz)
	 *
	 * critical
	 * 0 to 32 chars*/
	double lf;

	/*total number of samples (points) in dat file*/
	int nrates;

	/* sampling rate for each set of data in dat file
	 * critical*/
	/*WARNING: if nrates and samp are zero, the TIMESTAMP becomes critical
	 * and ENDSAMP must be set to the number of the last sample in the file*/
	sampling_rate * s_rates;

	/*following lines represent timestamps for
	 * the first point of the file
	 * and for the "trigger" time, it means that part of the file
	 * before the "trgger" time represents pre-fault operation
	 * written in a form of dd/mm/yyyy hh:mm:ss.ssssss*/

	/* day of month
	 * critical
	 * 1 to 2 chars
	 * 01 to 31*/
	int start_dd;
	/* month
	 * critical
	 * 1 to 2 chars
	 * 01 to 12*/
	int start_mm;
	/* year
	 * critical
	 * 4 chars
	 * 1900 to 9999*/
	int start_yyyy;
	/* hour
	 * critical
	 * 2 chars
	 * 00 to 23*/
	int start_hh;
	/* minutes
	 * critical
	 * 2 chars
	 * 00 to 59*/
	int start_min;
	/* seconds
	 * critical
	 * 9 to 12 chars
	 * 00.000000 to 59.999999999*/
	double start_ss_ssssss;

	int trig_dd;
	int trig_mm;
	int trig_yyyy;
	int trig_hh;
	int trig_min;
	double trig_ss_ssssss;

	/*data file type
	 * could be ASCII,binary,binary32,float32
	 * 5 to 8 chars*/
	char ft[8];

	/*1 to 32 chars*/
	float timemult;

	/*1 to 6 chars*/
	char time_code[6];
	/*1 to 6 chars*/
	char local_code[6];

	/*1 char*/
	int tmq_code;
	/*1 char*/
	int leapsec;
};

//define more usable name
typedef struct cfg_file_struct cfg_file_struct;

#endif
