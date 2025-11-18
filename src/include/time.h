#ifndef _CUSTOM_TIME_H
#define _CUSTOM_TIME_H

#include <internal/types.h>
//#include <stdint.h>

struct timespec {
	size_t tv_sec;
	size_t tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int seconds);


#endif
