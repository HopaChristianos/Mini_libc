#ifndef _CUSTOM_TIME_H
#define _CUSTOM_TIME_H

#include <internal/types.h>
#include <stdint.h>

struct timespec {
	long long tv_sec;
	long long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int seconds);


#endif
