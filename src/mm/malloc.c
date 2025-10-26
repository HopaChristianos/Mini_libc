// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	if (size == 0) {
		return NULL;
	}

	void *p = mmap(NULL, size, PROT_READ | PROT_WRITE,
					MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (p == MAP_FAILED) {
		return NULL;
	}

	if (mem_list_add(p, size) < 0) {
		munmap(p, size);
		return NULL;
	}

	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	void *p = malloc(nmemb * size);

	if (p == NULL) {
		return NULL;
	}

	memset(p, 0, nmemb * size);

	return p;
}

void free(void *ptr)
{
	if (ptr == NULL) {
		return;
	}

	struct mem_list *mem = mem_list_find(ptr);

	if (mem) {
		munmap(mem->start, mem->len);
		mem_list_del(ptr);
	}
}

void *realloc(void *ptr, size_t size)
{
	struct mem_list *mem = mem_list_find(ptr);

	if (!mem) {
		return NULL;
	}

	void *p = malloc(size);

	if (p == NULL) {
		return NULL;
	}

	if (size < mem->len) {
		memcpy(p, ptr, size);
	} else {
		memcpy(p, ptr, mem->len);
	}

	free(ptr);
	return p;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return realloc(ptr, nmemb * size);
}
