/*this is a header file
 containing description of the COMTRADE 2003 standart
 for measuring records*/

/*this is header files, used by this file
 * enclosed in special "header brackets"
 * in order to include them only once and
 * in a correct way*/
#include "analog_channel.h"
#include "digital_channel.h"
#include "sampling_data.h"
#include "uchar_size.h"

#ifndef CFG_FILE_2003_H
#define CFG_FILE_2003_H 1

struct cfg_file_2003{

	/*LINE 1 of the cfg specifies next three fields:
	 * station_name, rec_dev_id, rev_year*/

	/* any general short info about the place where record have been made
	 * critical
	 * alphanumeric
	 * 0 to 64 chars*/
	char station_name [64*UCHAR_SIZE] ;

	/* any info about recording device
	 * critical
	 * alphanumeric
	 * 0 to 64 chars*/
	char rec_dev_id [64*UCHAR_SIZE] ;

	/* COMTRADE standart version, which is used across the file
	 * can only be equal to 1991, 1999, 2013. if empty counts as 1991
	 * critical
	 * numeric
	 * 4 chars */
	int rev_year;
	
	/* LINE 2 contains general data about recorded channels
	 * TT, nA, nD*/

	/* total number of channels from 1 to 999999
	 * should be equal to the sum of nA and nD variables, e.g.
	 * analog and digital channels
	 * critical
	 * numeric
	 * 1 to 6 chars
	 * 1 to 999999 val*/
	int TT;

	/* total number of analog and digital channels
	 * alphanumeric value from 0A to 999999A (with A letter at the end)
	 * for analog channels, 0D to 999999D for the digital ones
	 * N.B. here integer is used as these values only are ints + A or D letter
	 * critical
	 * alphanumeric
	 * 2 to 7 chars
	 * 0 to 999999 val*/
	int nA;
	int nD;

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
	
	/*NEXT LINE contains only info about power system frequency
	 * from which samples in analog and digital channels
	 * were obtained (usually 50 Hz)
	 * critical
	 * real
	 * 0 to 32 chars*/
	double lf;

	/*NEXT LINE means a total number of samples (points) in dat file
	 * critical
	 * integer
	 * 1 to 3 chars
	 * 0 to 999 val*/
	int nrates;

	/* sampling rate for each set of data in dat file
	 * critical*/
	/*WARNING: if nrates and samp are zero, the TIMESTAMP becomes critical
	 * and ENDSAMP must be set to the number of the last sample in the file*/
	sampling_data * s_data;

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

	/* NEXT LINE the same for trigger moment
	 * specifies additional place in the recod for convinience*/
	int trig_dd;
	int trig_mm;
	int trig_yyyy;
	int trig_hh;
	int trig_min;
	double trig_ss_ssssss;

	/* NEXT LINE data file type
	 * could be ASCII,binary,binary32,float32
	 * critical
	 * alphabetic
	 * 5 to 8 chars*/
	char ft [8*UCHAR_SIZE];

	/* NEXT LINE. time multiplier for long records
	 * critical
	 * real
	 * 1 to 32 chars*/
	float timemult;

	/* NEXT LINE. time zone code , specified by the separate IEEE C37.232 standart
	 * critical 
	 * alphanumeric
	 * 1 to 6 chars*/
	char time_code[6*UCHAR_SIZE];
	/* difference between UTC and local time of the record in IEEE C37.232 form
	 * critical
	 * alphanumeric
	 * 1 to 6 chars*/
	char local_code[6*UCHAR_SIZE];

	/*THE LAST LINE*/
	/* device's clock quality in the terms of IEEE37.118 
	 * critical
	 * hexadecimal
	 * 1 char*/
	int tmq_code;
	/* leap second indicator (???)
	 * critical
	 * integer
	 * 1 char*/
	int leapsec;
};

//define more usable name
typedef struct cfg_file_2003 cfg_file_2003;

#endif
