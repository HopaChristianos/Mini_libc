// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	while ((*destination++ = *source++) != '\0') {}
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	size_t i = 0;

	for (; i < len && source[i] != '\0'; ++i) {
		destination[i] = source[i];
	}

	for (; i < len; ++i) {
		destination[i] = '\0';
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	strcpy(destination + strlen(destination), source);
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	while (*destination != '\0') {
		destination++;
	}

	strncpy(destination, source, len);
	destination[len] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while(*str1 && (*str1 == *str2)) {
		str1++;
		str2++;
	}

	return (unsigned char)*str1 - (unsigned char)*str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	if (len == 0) {
		return 0;
	}

	while (len-- && *str1 && (*str1 == *str2)) {
		if (len == 0) {
			return 0;
		}

		str1++;
		str2++;
	}

	return (unsigned char)*str1 - (unsigned char)*str2;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while(*str != (char)c) {
		if (*str == '\0') {
			return NULL;
		}

		str++;
	}

	return (char *)str;
}

char *strrchr(const char *str, int c)
{
	const char *final = NULL;

	while (*str != '\0') {
		if (*str == (char)c) {
			final = str;
		}

		str++;
	}

	if (c == '\0') {
		return (char *)str;
	}

	return (char *)final;
}

char *strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0') {
		return (char *)haystack;
	}

	const char *h, *n;

	while (*haystack != '\0') {
		h = haystack;
		n = needle;

		while (*h != '\0' && *n != '\0' && *h == *n) {
			h++;
			n++;
		}

		if (*n == '\0') {
			return (char *)haystack;
		}

		haystack++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	if (*needle == '\0') {
		return (char *)haystack;
	}

	const char *final = NULL;
	const char *h = haystack;

	while ((h = strstr(h, needle)) != NULL) {
		final = h;
		h++;
	}

	return (char *)final;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	unsigned char *d = destination;
	const unsigned char *s = source;

	while (num--) {
		*d++ = *s++;
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	unsigned char *d = destination;
	const unsigned char *s = source;

	if (d == s || num == 0) {
		return destination;
	}

	if (d < s) {
		memcpy(d, s, num);
	} else {
		unsigned char *d_end = d + num;
		const unsigned char *s_end = s + num;

		while (num--) {
			*(--d_end) = *(--s_end);
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char *p1 = ptr1;
	const unsigned char *p2 = ptr2;

	while (num--) {
		if (*p1 != *p2) {
			return (int)(*p1 - *p2);
		}

		p1++;
		p2++;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	unsigned char *p = source;

	while (num--) {
		*p++ = (unsigned char)value;
	}

	return source;
}
