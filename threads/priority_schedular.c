

#include "priority_schedular.h"

bool
is_priority_schedualr (struct priority_schedular *ps) {
	return ps != NULL;
}
void
priority_schedular_init (struct priority_schedular *ps) {
	ASSERT(is_priority_schedualr(ps));
	for (int i = 0; i <= PRI_MAX; ++i) {
		list_init(&ps->queues[i]);
	}
}

void
insert (struct priority_schedular *ps, struct thread *to_be_added) {
	ASSERT(is_priority_schedualr(ps));
	ASSERT(to_be_added->priority >= PRI_MIN && to_be_added->priority <= PRI_MAX);
	list_push_back(&ps->queues[to_be_added->priority], &to_be_added->elem);
}
struct thread 
*getMax (struct priority_schedular *ps) {
	ASSERT(is_priority_schedualr(ps));
	struct list *q = ps->queues;
	for (int i = PRI_MAX; i >= 0; --i) {
		if (!list_empty(&q[i])) {
			return list_entry(list_pop_front(&q[i]), struct thread, elem);
		}
	}
	return NULL;
}

void 
remove (struct priority_schedular *ps, struct thread *to_be_removed) {
	ASSERT(is_priority_schedualr(ps));
	ASSERT(to_be_removed->priority >= PRI_MIN && to_be_removed->priority <= PRI_MAX);
	ASSERT(!list_empty(&ps->queues[to_be_removed->priority]));
	list_remove(&to_be_removed->elem); 
}

void 
update (struct priority_schedular *ps, struct thread *to_be_updated, int new_priority) {
	remove(ps, to_be_updated);
	to_be_updated->priority = new_priority;
	insert(ps, to_be_updated);
}


