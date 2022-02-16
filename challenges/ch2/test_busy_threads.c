#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>

/* How many threads (aside from main) to create */
#define THREAD_CNT 3

/* pthread_join is not implemented in homework 2 */
#define HAVE_PTHREAD_JOIN 0

/* Each counter goes up to a multiple of this value. If your test is too fast
 * use a bigger number. Too slow? Use a smaller number. See the comment about
 * sleeping in count() to avoid this size-tuning issue.
 */
#define COUNTER_FACTOR 10000000

/* Waste some time by counting to a big number.
 *
 * Alternatively, introduce your own sleep function to waste a specific amount
 * of time. But make sure it plays nice with your scheduler's interrupts (HINT:
 * see the man page for nanosleep, and its possible ERROR codes).
 */
void *count(void *arg) {
	unsigned long int c = (unsigned long int)arg;
	int i;
	for (i = 0; i < c; i++) {
		if ((i % 100000) == 0) {
			printf("id: 0x%lx counted to %d of %ld\n",
			       pthread_self(), i, c);
		}
	}
	return NULL;
}

/*
 * Expected behavior: THREAD_CNT number of threads print increasing numbers
 * in a round-robin fashion. The first thread finishes soonest, and the last
 * thread finishes latest. All threads are expected to reach their maximum
 * count.
 *
 * This isn't a great test for `make check` automation, since it doesn't
 * actually fail when things go wrong. Consider adding lock() and unlock()
 * functions to let your threads "pause" the scheduler occasionally to
 * compare the current state of each thread's counters (you may also need to
 * have an array of per-thread counters). See man pages for sigprocmask,
 * sigemptyset, and sigaddset.
 */
int main(int argc, char **argv) {
	pthread_t threads[THREAD_CNT];
	int i;
	for(i = 0; i < THREAD_CNT; i++) {
		pthread_create(&threads[i], NULL, count,
		               (void *)(intptr_t)((i + 1) * COUNTER_FACTOR));
	}

#if HAVE_PTHREAD_JOIN == 0
	/* Wait for longer than the most busy of the other threads */
	count((void *)(intptr_t)((i + 1) * COUNTER_FACTOR));
#else
	/* Collect statuses of the other threads, waiting for them to finish */
	for(i = 0; i < THREAD_CNT; i++) {
		pthread_join(threads[i], NULL);
	}
#endif
	return 0;
}
