#include "priority_scheduler.h"

bool
is_priority_scheduler (struct priority_scheduler *ps)
{
	return ps != NULL;
}

/* Initializes all 64 queues for the priority_schedular. */
void
priority_scheduler_init (struct priority_scheduler *ps)
{
	ASSERT(is_priority_scheduler(ps));
	for (int i = 0; i <= PRI_MAX; ++i)
	{
		list_init(&ps->queues[i]);
	}
	ps->size = 0;
}

/* Inserts the given thread in the appropriate queue using it's current priority. */
void
insert (struct priority_scheduler *ps, struct thread *to_be_added)
{
	ASSERT(is_priority_scheduler(ps));
	ASSERT(to_be_added->priority >= PRI_MIN && to_be_added->priority <= PRI_MAX);
	list_push_back(&ps->queues[to_be_added->priority], &to_be_added->elem);
	ps->size++;
}

/* Removes the thread from the priority_schedular by finding its appropriate queue using it's priority. */
void
remove (struct priority_scheduler *ps, struct thread *to_be_removed)
{
	ASSERT(is_priority_scheduler(ps));
	ASSERT(to_be_removed->priority >= PRI_MIN && to_be_removed->priority <= PRI_MAX);
	ASSERT(!list_empty(&ps->queues[to_be_removed->priority]));
	list_remove(&to_be_removed->elem);
	ps->size--;
}

/* Given a thread that is already in the priority_schedular and a new priority, It sets the given thread 
   to the new priority adjusting it to the appropriate queue. */
void
update (struct priority_scheduler *ps, struct thread *to_be_updated, int new_priority)
{
	remove(ps, to_be_updated);
	to_be_updated->priority = new_priority;
	insert(ps, to_be_updated);
}

/* Returns the thread with the largest priority and removes it. It is done by iterating
   descending on the priorities to get the first queue that is non-empty. If the priority_schedular
   is empty, returns its NULL. */
struct thread *
pop_max_thread (struct priority_scheduler *ps)
{
	ASSERT(is_priority_scheduler(ps));
	struct list *q = ps->queues;
	for (int i = PRI_MAX; i >= 0; --i)
	{
		if (!list_empty(&q[i]))
		{
			ps->size--;
			return list_entry(list_pop_front(&q[i]), struct thread, elem);
		}
	}
	return NULL;
}

/* Same as pop_max_thread, however it retrieves the maximum priority, but does not remove the thread. If the
   priority_schedular is empty, returns its -1. */
int
peek_max_priority (struct priority_scheduler *ps)
{
	ASSERT(is_priority_scheduler(ps));
	struct list *q = ps->queues;
	for (int i = PRI_MAX; i >= 0; --i)
	{
		if (!list_empty(&q[i]))
			return i;
	}

	return -1;
}

/* Returns the number of threads in the priority_schedular. */
int
get_size (struct priority_scheduler *ps)
{
	ASSERT(is_priority_scheduler(ps));
	return ps->size;
}
