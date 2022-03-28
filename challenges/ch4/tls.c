#include "tls.h"

/*
 * This is a good place to define any data structures you will use in this file.
 * For example:
 *  - struct TLS: may indicate information about a thread's local storage
 *    (which thread, how much storage, where is the storage in memory)
 *  - struct page: May indicate a shareable unit of memory (we specified in
 *    homework prompt that you don't need to offer fine-grain cloning and CoW,
 *    and that page granularity is sufficient). Relevant information for sharing
 *    could be: where is the shared page's data, and how many threads are sharing it
 *  - Some kind of data structure to help find a TLS, searching by thread ID.
 *    E.g., a list of thread IDs and their related TLS structs, or a hash table.
 */

/*
 * Now that data structures are defined, here's a good place to declare any
 * global variables.
 */

/*
 * With global data declared, this is a good point to start defining your
 * static helper functions.
 */

/*
 * Lastly, here is a good place to add your externally-callable functions.
 */ 

int tls_create(unsigned int size)
{
	return 0;
}

int tls_destroy()
{
	return 0;
}

int tls_read(unsigned int offset, unsigned int length, char *buffer)
{
	return 0;
}

int tls_write(unsigned int offset, unsigned int length, const char *buffer)
{
	return 0;
}

int tls_clone(pthread_t tid)
{
	return 0;
}
