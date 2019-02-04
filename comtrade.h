/*this is a header file
 containing description of the COMTRADE 2003 standart
 for measuring records*/

#ifndef ANALOG_CHANNEL_H
	#include <analog_channel>
#endif
#ifndef DIGITAL_CHANNEL_H
	#include <digital_channel>
#endif

#ifndef CFG_FILE_H
#define CFG_FILE_H 1

struct cfg_file{

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
	int rev_year[4];
	
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

	

};

//define more usable name
typedef struct cfg_file cfg_file;

#endif
