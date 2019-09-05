#include<assert.h>
#include "student.h"
#include "student.c"
#include<stdio.h>

/*
void test_slist()
{
int look;
List *list=slist_new();
assert(list->length==0);
list=slist_add_head(list,10);
showstack(list);
list=slist_add_head(list,20);
showstack(list);
list=slist_add_head(list,30);
showstack(list);
list=slist_add_head(list,40);
showstack(list);
assert(list->length==4);
list=slist_delete_head(list);
showstack(list);
list=slist_delete_head(list);
showstack(list);
list=slist_delete_head(list);
showstack(list);
assert(list->length==1);
list=slist_add_head(list,20);
showstack(list);
list=slist_add_head(list,20);
showstack(list);
list=slist_add_head(list,20);
showstack(list);
look=slist_lookup(list,20);
assert(look==1);
//printf("%d %p %p %d",list->length,list->head,list->tail,look);
assert(slist_length(list)==4);
list=slist_free(list);
assert(list->length==0);
//assert(list->head==NULL && list->tail==NULL);
}
*/







int main()
{
int choice,i;
Student s;


List *list=slist_new();



do
{
printf("\n\n\n\n 1:add student\n 2:view student\n 3:sort\n 4:exit\nenter your choice : ");
scanf("%d",&choice);

switch(choice)
{
case 1:
printf("\nenter name : ");
scanf("%s",s.name);
printf("\nenter rollnumber : ");
scanf("%d",&s.rollnumber);
printf("\nenter 5 marks :");
for(i=0;i<5;i++)
scanf("%f",&s.marks[i]);


list=slist_add(list,s);

break;

case 2:
showstudent(list);
break;

case 3:
list=sort(list);
break;
default:
exit(0);


}
}while(choice!=4);

return 0;


}
