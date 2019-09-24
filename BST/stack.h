#ifndef _INCLUDE_STACK_H_
#define _INCLUDE_STACK_H_
#include "BST.h"
#include<stdio.h>
#include<stdint.h>
#define MAX_DEPTH 32

struct _stack_ 
{

uint32_t size;
int32_t top;
TreeNode* data[MAX_DEPTH];


};



typedef struct _tree_node_ TreeNode;


typedef struct _stack_ Stack;

#define RESULT_INVALID 0
#define STACK_OK 1
#define STACK_FULL 2
#define STACK_EMPTY 4

struct _stack_result_
{

TreeNode *data;
uint32_t status;


};

typedef struct _stack_result_ StackResult;

Stack stack_new(uint32_t size);
uint32_t stack_full(const Stack *stk);
uint32_t stack_empty(const Stack *stk);
Stack* stack_push(Stack *stk,TreeNode *data,StackResult *result);
Stack* stack_pop(Stack *stk,StackResult *result);
Stack* stack_peek(Stack *stk,StackResult *result);
#endif
