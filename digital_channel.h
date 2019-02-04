/*this file contains description of a digital channel information
 * in the IEEE COMTRADE document it is also called "status" channels*/

#ifndef DIGITAL_CHANNEL_H
#define DIGITAL_CHANNEL_H 1

struct digital_channel{

	/*critical
	 * digital channel index number
	 * should be sequental in this file from 1 to nD
	 * value from 1 to 999999
	 * 1 to 6 chars*/
	int Dn;

	/*critical
	 * any name for the channel
	 * from 1 to 128 chars*/
	char ch_id[128];

	/*non-critical
	 * phase identification
	 * ?????????????????????
	 * from 0 to 2 chars*/
	char ph[2];

	/*non-critical
	 * circuit component name
	 * any name for the object for which this channel is written 
	 * from 0 to 64 chars*/
	char ccbm[64];

	/*critical
	 * the channel normal status
	 * only for human recognition of what state is correct
	 * only 0 or 1 */
	int y;

};
typedef     struct digital_channel    digital_channel;//short name

#endif
