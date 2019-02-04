#ifndef ANALOG_CHANNEL_H
#define ANALOG_CHANNEL_H 1

/*the struct represents analog channel data in cfg file
 * total number of analog channels provided in the begining of
 * the cfg file, each struct instance corresponds
 * to a line in the cfg file*/
struct analog_channel{

	/*critical
	 * channel index number. should be sequental from 1 to nA for each line
	 * could be from 1 to 999999, max length = 6*/
	int An;

	/*critical
	 * channel identifier -- name of the channel, from 1 to 128 channels*/
	char ch_id[128];

	/*non-critical
	 * ??????????????
	 * phase identification -- from 0 to 2 chars*/
	char ph[2];

	/*non-critical
	 * id of circuit component being monitored
	 * from 0 to 64 chars*/
	char ccbm[64];

	/*critical
	 * channel units (kV, V, kA, A and so on)
	 * from 1 to 32 chars
	 * may be used with k,m,M,n and so on
	 * NONE for unitless values*/
	char uu[32];

	/*critical
	 * channel multiplier from 1 to 32 chars
	 * floating point notation could be used
	 * every value in chanel will be multiplied with this koeff*/
	double a;

	/*critical
	 * channel offset from 1 to 32 chars
	 * used for efficient data representation in the dat file
	 * exact value are count as ax+b, where x is the value from dat file*/
	double b;
	 
	/*critical
	 * channel time skew in microseconds from start of sample period
	 * from 1 to 32 channels
	 * useful when channels have same sampling freq but have
	 * constant offset in time (like several channels in one ADC)*/
	double skew;

	/*critical
	 * max and min channel value, from 1 to 13 chars*/
	double min;
	double max;

	/*critical
	 * measuring transformer primary and secondary ratio from 1 to 32 chars*/
	double primary;
	double secondary;

	/*critical
	 * represents in primary or secondary values dat file is written
	 * only could be pPsS. If no transformer is used, should be 1:1*/
	char PS;
};
typedef struct analog_channel analog_channel;

#endif
