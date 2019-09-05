#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "sslist.h"

List* slist_new()
{

 List *list;
 list = (List*) malloc(sizeof(List));
 list-> head = NULL;
 list-> tail = NULL;
 list-> length = 0;
 return list;

}

uint32_t slist_length(const List *list)

{

 return list->length;

}

List* slist_free(List *list)

{

    Node *cur,*p;
    if(slist_length(list)>0)

 {

    assert(list->head && list->tail);
    cur=list->head;
    list->head=NULL;
    list->tail=NULL;
    while(cur!=NULL)

   {

    p=cur;
    cur=cur->next;
    free(p);
    --list -> length;

   }

 }

 return list;

}

static Node* _list_node_new_(int32_t data)

{

 Node* node=(Node*)malloc(sizeof (Node));
 node-> data=data;
 node-> next=NULL;
 return node;
}

List* slist_add_head(List *list, int32_t data)

{

  Node *node=_list_node_new_(data);
  node-> next=list-> head;
  list-> head=node;
  if(list->tail==NULL)

 {

   list->tail=node;

 }

 ++list->length;

 assert((list->length==1 && list->head==list->tail)||(list->length>0 && list->head!=list->tail));
 return list;

}

List* slist_add_tail(List *list, int32_t data)

{

 Node *node= _list_node_new_(data);
 if(list ->tail!=NULL)

 {

  list ->tail->next=node;
  list->tail=node;

 }
  else
 {

  list->head=list->tail=node;

 }

 ++list->length;
 return list;

}

List* slist_delete_head(List *list)

{
  Node *node;
  if(list->head!=NULL)

  {

   assert(list->length>0);
   node=list->head;
   list->head=list->head->next;
   --list->length;

   if(list->head==NULL)

    {

      list->tail==NULL;
      assert(list->length==0);

     }

      free(node);

  }

    return list;

}

List* slist_delete_tail(List *list)

{

  assert(list!=NULL);
  Node *tail=list->tail;
  Node *node;
  if(list->tail==list->head)

 {

   list->head=list->tail=NULL;

 }
  else
  {

   for(node=list->head; node->next!=list->tail; node=node->next);
   
    {

   	 list->tail=node;
     list->tail->next=NULL;
     free(tail);

    }

   --list->length;

 }

 return list;

}

uint32_t slist_lookup(const List *list, int32_t key)

{

  Node *node=list->head;
  for(node=list->head; node!=NULL;node=node->next)

 {

  if(node->data==key)break;

 }

 return(node!=NULL);

}

List* slist_add_on_data(List *list,int32_t data)

{

 if(list->head !=NULL)

 {

  Node *cur=list->head;
  Node *node=_list_node_new_(data);
  for(;cur!=NULL && cur->data !=data;cur=cur->next);

  if(cur!=NULL)

   {

    node->next=cur->next;
    cur->next=node;
    if(node->next==NULL)

    {

     list->tail=node;

    }

   }

  ++list->length;

 }

 return list;

}

List* slist_add_on_key(List *list,int32_t data,int32_t key)

{

 if(list->head !=NULL)

  {

   Node *cur=list->head;
 
   Node *node1=_list_node_new_(key);
   for(;cur!=NULL && cur->data !=data;cur=cur->next);

   if(cur!=NULL)

   {

     node1->next=cur->next;
     cur->next=node1;
     if(node1->next==NULL)

     {

       list->tail=node1;

     }

    }

    ++list->length;

  }

 return list;

}

List* slist_delete_on_data(List *list,int32_t data)

{

 if(list->head !=NULL)

 {

  Node *cur,*p;
  cur=list->head;
  if(cur->data==data)

   {

    list->head=cur->next;

   }
   else
   {

     p=cur;
     cur=cur->next;
     while(cur!=NULL)

     {

      if(cur->data==data)

       {
          p=cur->next;

        }
      else
       { 

         p=cur;
         cur=cur->next;

        }

     }

     if(cur==list->tail)

      {

        list->tail=p;

      }

    }

    if(list->head==NULL)

    {

      list->tail=NULL;

    }

    free(cur);
    --list->length;

 }

}




