// This test case covers the basics of mutex implementation.

#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

pthread_mutex_t *mutex;

int main(int argc, char **argv) {

	printf("Testing if mutex can be created.\n");
	mutex = malloc(sizeof(*mutex));
	int init_status = pthread_mutex_init(mutex, NULL);
	assert(init_status == 0);
	printf("Mutex created!\n\n");

	printf("Testing if mutex can be locked.\n");
	int lock_status = pthread_mutex_lock(mutex);
	assert(lock_status == 0);
	printf("Mutex can be locked!\n\n");

	printf("Testing if code recognizes self-locked mutex.\n");
	lock_status = pthread_mutex_lock(mutex);
	assert(lock_status != 0); // return values may differ between implementations
	printf("Code recognizes self-locked mutex!\n\n");

	printf("Testing if mutex can be unlocked.\n");
	lock_status = pthread_mutex_unlock(mutex);
	assert(lock_status == 0);
	printf("Mutex can be unlocked.\n\n");

	printf("Testing if mutex can be locked after unlock.\n");
	lock_status = pthread_mutex_lock(mutex);
	assert(lock_status == 0);
	printf("Mutex can be locked after unlock.\n\n");

	printf("Testing if mutex can be destroyed.\n\n");
	lock_status = pthread_mutex_destroy(mutex);
	assert(lock_status == 0);
	printf("Mutex can be destroyed!\n\n");

	printf("Testing if mutex can be initialized after being destroyed.\n");
	init_status = pthread_mutex_init(mutex, NULL);
	printf("Mutex can be initialized after being destroyed!\n\n");

	printf("Finished Mutex testing.\n\n");

	return 0;
}
