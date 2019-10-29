#ifndef _BinHeap_H
#define _BinHeap_H

typedef int32_t ElementType;
typedef struct _heapstruct_ *PriorityQueue;

PriorityQueue initilize(int32_t MaxElement);

void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void insert(ElementType X; PriorityQueue H);

ElementType Deletion(PriorityQueue H);
ElementType Findmin(PriorityQueue H);

int32_t IsEmpty(PriorityQueue H);
int32_t IsFull(PriorityQueue H);

#endif

