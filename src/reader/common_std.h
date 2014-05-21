/**
 * Definitions of integers. ROOT CINT has problems parsing stdint.h file.
 * this file defines commonly used integers to avoid problems with CINT.
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef uint32_t
typedef unsigned __INT32_TYPE__ uint32_t;
#endif

#ifndef int32_t
typedef __INT32_TYPE__ int32_t;
#endif

#ifndef uint16_t
typedef unsigned __INT16_TYPE__ uint16_t;
#endif

#ifndef int16_t
typedef __INT16_TYPE__ int16_t;
#endif
/*
#ifndef uint8_t
typedef unsigned __INT8_TYPE__ uint8_t;
#endif

#ifndef int8_t
typedef __INT8_TYPE__ int8_t;
#endif
*/
/**
 * End 
 */
