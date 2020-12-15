#ifndef PRIORITY_SCHEDULAR_H
#define PRIORITY_SCHEDULAR_H

#include <list.h>
#include "threads/thread.h"
struct priority_schedular {
	struct list queues[PRI_MAX+1];
};

void priority_schedular_init(struct priority_schedular *ps);
void insert (struct priority_schedular *ps, struct thread *to_be_added);
struct thread *getMax (struct priority_schedular *ps);
void remove (struct priority_schedular *ps, struct thread *to_be_removed);
void update (struct priority_schedular *ps, struct thread *to_be_updated, int new_priority);
int get_max_priority (struct priority_schedular *ps); 

#endif 
