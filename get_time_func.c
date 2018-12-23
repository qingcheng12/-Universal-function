/*****************************************************************************
 Copyright(C) .
 All rights reserved.

 @file   : get_time_func.c
 @brief  : Get current time.
 @author : zhanghao
 @history:
           2018-12-23    zhanghao    Created file
******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <inttypes.h>

// get microseconds of current time
unsigned long current_time(void){
	unsigned long   int         us; // Microseconds
  	time_t          s;  // Seconds
	struct timespec spec;
	clock_gettime(CLOCK_REALTIME, &spec);
	s  = spec.tv_sec;
  
  	// Convert nanoseconds to microseconds
  	us = /*round*/(spec.tv_nsec / 1.0e3); 
  
 	 return us;
}


// get seconds of current time
unsigned long getsecs(void){

	unsigned long            us; // Microseconds
  	time_t          s;  // Seconds
	struct timespec spec;
	clock_gettime(CLOCK_REALTIME, &spec);
	s  = spec.tv_sec;
	return s;

}


int main(int argc, char** argv)
{
   current_time();
   getsecs();

  return 0;
}




