#include <internal/syscall.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int puts(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0') {
		len++;
	}

	if (syscall(__NR_write, 1, str, len) < 0) {
		return -1;
	}

	if (syscall(__NR_write, 1, "\n", 1) < 0) {
		return -1;
	}

	return 1;
}