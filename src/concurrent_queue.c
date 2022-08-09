#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

typedef struct __node_t {
	int								value;
	struct __node_t		*next;
} node_t;

typedef struct __queue_t {
	node_t						*head;
	node_t						*tail;
	pthread_mutex_t		headLock;
	pthread_mutex_t		tailLock;
} queue_t;

void QueueInit(queue_t *q) {
	node_t *tmp = malloc(sizeof(node_t));
	tmp->next = NULL;
	q->tail = tmp;
	q->head = tmp;
	pthread_mutex_init(&q->headLock, NULL);
	pthread_mutex_init(&q->tailLock, NULL);
}

void QueueEnqueue(queue_t *q, int value) {
	node_t *tmp	= malloc(sizeof(node_t));
	assert(tmp != NULL);
	tmp->value	= value;
	tmp->next		=  NULL;

	pthread_mutex_lock(&q->tailLock);
	q->tail->next = tmp;
	q->tail				= tmp;
	pthread_mutex_unlock(&q->tailLock);
}

int QueueDequeue(queue_t *q, int *value) {
	pthread_mutex_lock(&q->headLock);
	node_t *tmp = q->head;
	node_t *new_head = tmp->next;
	if (new_head == NULL) {
		pthread_mutex_unlock(&q->headLock);
		return -1;	/** queue was empty */
	}
	*value = new_head->value;
	q->head = new_head;
	pthread_mutex_unlock(&q->headLock);
	free(tmp);
	return 0;
}

int QueueTraverse(queue_t *q) {
	node_t *tmp;
	tmp = q->head;
	while (tmp->next != NULL) {
		printf("value = %d\n", tmp->next->value);
		tmp = tmp->next;
	}
}

void testQueue() {
	queue_t *q = malloc(sizeof(queue_t));
	/** queue_t *q = { NULL }; <] [> NULL pointer exception */
	QueueInit(q);
	QueueEnqueue(q, 1);
	QueueEnqueue(q, 2);
	QueueTraverse(q);
}

int main() {
	testQueue();
}
