#ifndef  _INCLUDED_SLIST_
#define _INCLUDED_SLIST_
#include<stdint.h>

typedef struct _node_ Node;
typedef struct _slist_ List;
typedef struct _student_ Student;
struct _slist_
{
Node *head;


uint32_t length;
};

struct _student_
{

char name[20];
int rollnumber;
float marks[5];
float total; 

};
struct _node_
{
Student data;
Node *next;
};




List* slist_new();
uint32_t slist_length(const List *list);
List* slist_free(List*);

List* sort(List *list);
//uint32_t slist_lookup(const List *list,int32_t key);
List* slist_add(List *list,Student data);
//List* slist_add_tail(List *list,int32_t data);
//List* slist_delete(List *list);
void showstudent(List *list);
//List* slist_delete_tail(List *list);
//List* slist_add_on_data(List *list,int32_t data,uint32_t key); 
//List* slist_delete_on_data(List *list,int32_t data); 
#endif
