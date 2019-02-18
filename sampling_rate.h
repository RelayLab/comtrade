#ifndef SAMPLING_RATE_H
	#define SAMPLING_RATE_H 1

struct sampling_rate{
	/*sampling rate in Hz
	 * critical
	 * 1 to 32 chars*/
	double samp;

	/* number of last sample with given sample rate
	 * critical
	 * 1 to 10 chars*/
	int endsamp;
};

typedef struct sampling_rate sampling_rate;
#endif
