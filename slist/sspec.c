#include<assert.h>
#include "sslist.h"
#include "sslist.c"
#include<stdio.h>
void test_slist()
{
 int look;
 List *list=slist_new();


 assert(list->length==0);

 list=slist_add_head(list,10);
 list=slist_add_head(list,20);
 list=slist_add_head(list,30);
 list=slist_add_head(list,40);


 assert(list->length==4);



 list=slist_add_tail(list,50);
 list=slist_add_tail(list,60);
 list=slist_add_tail(list,70);
 list=slist_add_tail(list,80);


 assert(list->length==8);

 list=slist_delete_head(list);
 list=slist_delete_head(list);
 list=slist_delete_head(list);


 assert(list->length==5);

 list=slist_delete_tail(list);
 list=slist_delete_tail(list);
 list=slist_delete_tail(list);


 assert(list->length==2);

 look=slist_lookup(list,10);
 assert(look==1);

 list=slist_delete_on_data(list,80);
 assert(list->length==1);



}

 int main()

{

 test_slist();
 

 printf("\n executed successfully\n");
 return 0;

}
