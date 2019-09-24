#ifndef  _INCLUDED_QUEUE_
#define _INCLUDED_QUEUE_
#include<stdint.h>
#include "BST.h"
#define MAX_QUEUE_LEN 32



typedef struct _queue_ Queue;
typedef struct _queue_result_ QueueResult;

struct _queue_
{
uint32_t size;
uint32_t count;
uint32_t head;
uint32_t tail;
TreeNode* q[MAX_QUEUE_LEN];

};

struct _queue_result_
{
TreeNode *data;
uint32_t status;

};

#define QUEUE_OK 1
#define QUEUE_FULL 2

Queue queue_new(uint32_t size);
Queue* queue_add_head(Queue *q,int32_t data,QueueResult *result);
Queue* queue_remove(Queue *q,QueueResult *result);
uint32_t queue_full(Queue *q);
uint32_t queue_empty(Queue *q);


#endif
