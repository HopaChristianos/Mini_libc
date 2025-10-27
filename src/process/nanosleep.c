#include <internal/syscall.h>
#include <time.h>
//#include <errno.h>


int nanosleep(const struct timespec *req, struct timespec *rem)
{
	long ret = syscall(__NR_nanosleep, req, rem);

	return (int)ret;
}
