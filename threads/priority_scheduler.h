#ifndef PRIORITY_SCHEDULER_H
#define PRIORITY_SCHEDULER_H

#include <list.h>
#include "threads/thread.h"

/* Provides basic implementation for a priority queue for the threads. The idea is since the priority of threads
   is limited between PRI_MIN and PRI_MAX i.e 0 and 64 respectively. We can create a simple priority queue by creating
   64 queues for every priority. This also ensures that if there are multiple threads with the same priority that they
   are ordered in FIFO fashion. Thus we can do insertion, deletion, pop in O(1) time complexity. */
struct priority_scheduler
{
	int size;
	struct list queues[PRI_MAX + 1];
};

void priority_scheduler_init(struct priority_scheduler *ps);
void insert(struct priority_scheduler *ps, struct thread *to_be_added);
void remove(struct priority_scheduler *ps, struct thread *to_be_removed);
void update(struct priority_scheduler *ps, struct thread *to_be_updated, int new_priority);
int peek_max_priority(struct priority_scheduler *ps);
struct thread *pop_max_thread(struct priority_scheduler *ps);

#endif
