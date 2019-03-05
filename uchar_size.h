/*file: uchar_size.h
 * this header file intended to only hold info
 * about user's encoding
 * Generally, the IEEE Comtrade 2011 4.1.3 states
 * that UTF-8 could be used in cfg and dat files
 * along with ASCII encoding. As long as UTF-8 has
 * different size of a symbol, max length of 4 of a
 * symbol is used in order to allocate enough space
 *
 * For the sake of simplicity, the usage of multibyte
 * variables uchar and wchar is avoided, as long as
 * the text of cfg files only proceeded here, not decoded*/


#ifndef UCHAR_SIZE_H
	#define UCHAR_SIZE_H 1
	#define UCHAR_SIZE 4
#endif
