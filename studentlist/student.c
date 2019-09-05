#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "student.h"
#include<stdio.h>
#include<string.h>



List* slist_new()
{

List *list;
list=(List*)malloc(sizeof(List));

list->head=NULL;

list->length=0;
return list;



}



List* slist_free(List *list)
{
Node *cur,*p;
if(slist_length(list)>0)
{
assert(list->head);
cur=list->head;
list->head=NULL;

while(cur!=NULL)
{
p=cur;
cur=cur->next;
free(p);
--list->length;
}


}


return list;

}

static Node* _list_node_new_(Student data)
{
Node* node=(Node*)malloc(sizeof(Node));
int i;
node->data.total=0;
strcpy(node->data.name,data.name);
node->data.rollnumber=data.rollnumber;
node->data.rollnumber=data.rollnumber;
for(i=0;i<5;i++)
{
node->data.marks[i]=data.marks[i];
node->data.total += data.marks[i];
}
node->next=NULL;
return node;

}


List* slist_add(List *list,Student data)
{
Node *node=_list_node_new_(data);
node->next=list->head;
list->head=node;

++list->length;
assert(( list->length==1 ) || list->length>0 );
//printf("added %d\n",data);
return list;
}


uint32_t slist_length(const List *list)
{
return list->length;

}
/*
uint32_t slist_lookup(const List *list,int32_t key)
{
Node *node=list->head;
for(node=list->head;node!=NULL;node=node->next)
{
if(node->data==key)break;
}
return (node!=NULL);
}
*/





List* slist_delete_head(List *list)
{

Node *node;
if(list->head!=NULL)
{

node=list->head;
list->head=list->head->next;
assert(list->length>0);

--list->length;

if(list->head==NULL)
{

assert(list->length==0);

}
free(node);
}
return list;

}



void showstudent(List *list)
{

Node *temp;
int i;
printf("\n");

for(temp=list->head;temp!=NULL;temp=temp->next)
{
printf("\n=====================");

printf("\nStudent name : %s\nStudent roll number : %d\nmarks :",temp->data.name,temp->data.rollnumber);
for(i=0;i<5;i++)
printf(" %f ",temp->data.marks[i]);
printf("\ntotal : %f",temp->data.total);
printf("\n=======================");

}
printf("\n\n\n");

}



List* sort(List *list)
{
Node *i,*j;
char a[20];

for(i=list->head;i->next!=NULL;i=i->next)
{
printf("\nemtered");
for(j=i;j!=NULL;j=j->next)
{printf("\nagain");
//printf("%s %s",i->data.name,j->data.name);
if(strcmp(i->data.name,j->data.name)>0)
{
//printf("\ncompared");

strcpy(a,i->data.name);
strcpy(i->data.name,j->data.name);
strcpy(j->data.name,a);

}

}
}


return list;




}



