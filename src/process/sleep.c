#include <internal/syscall.h>
#include <time.h>
//#include <errno.h>

unsigned int sleep(unsigned int seconds)
{
	struct timespec req = { .tv_sec = seconds, .tv_nsec = 0};
	struct timespec rem;

	while (nanosleep(&req, &rem) == -1) {
		req = rem;
	}

	return 0;
}
