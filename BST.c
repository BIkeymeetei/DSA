#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "BST.h"
#include "queue.c"
#include "stack.c"


BST bst_new(){

	BST tree={NULL,0};
	return tree;

}

static TreeNode* _make_tree_Node_(int32_t key)
{
	TreeNode *tnode=(TreeNode*) malloc(sizeof(TreeNode));
	tnode->key=key;
	tnode->left=tnode->right=NULL;
	return tnode;


}


BST* bst_add(BST *tree,int32_t key)
{
	TreeNode *root,*parent;
	root =parent=tree->root;
	while(root!=NULL && root->key!=key)
	{
		parent = root;
		if(key<root->key)
		{
			
			root=root->left;

		}

		else if(key>root->key)
		{
			
			root=root->right;

		}

	}



	if(root==NULL)
	{

		TreeNode *tnode=_make_tree_Node_(key);
		if(parent==NULL)
		{
			//printf("\nNULL");
			tree->root=tnode;

		}

		else if(key<parent->key)
		{
			//printf("\nleft");
			parent->left=tnode;

		}


		else
		{
			//printf("\right");
			parent->right=tnode;

		}
		




	}

	++(tree->mass);
	//printf("\nadded");

	return tree;
}



uint32_t bst_find(BST *tree,int32_t key)
{

	TreeNode *root=tree->root;
	while(root!=NULL)
	{
//printf("\n%d %d",root->key,key);
		
		if(key<root->key)
		{
			root=root->left;
		}

		else if(key>root->key)
		{
			root=root->right;

		}
		else
		{
			break;
		}
	}
	if(root!=NULL)
		return 1;
	else
		return 0;
}



uint32_t bst_mass(BST *tree)
{

	return tree->mass;


}


static uint32_t _height_(TreeNode *node)
{
	uint32_t height;
	uint32_t lheight,rheight;

	if(node==NULL)
	{
		height=0;
	}
	else

	{

		lheight=_height_(node->left);
		rheight=_height_(node->right);
		if(lheight>rheight)
		{
			height=lheight+1;
		}
		else
		{

			height=rheight+1;
		}

	}
}




static TreeNode* _find_min_(TreeNode *root)
{

	if(root->left==NULL)
	{
		return root;

	}
	else
	{

		return ( _find_min_(root->left));

	}

}


uint32_t bst_height(BST *tree)
{

	return (_height_(tree->root));
}



TreeNode* _bst_delete_(BST *tree,TreeNode *root , int32_t key)
{
	TreeNode *temp;
	if(root==NULL)
	{
		return root;

	}

	else if(key<root->key)
	{

		root->left=_bst_delete_(tree,root->left,key);
	}
	else if(key>root->key)
	{

		root->right=_bst_delete_(tree,root->right,key);
	}

	else if(root->left && root->right)
	{
		temp = _find_min_(root->right);
		root->key=temp->key;
		root->right=_bst_delete_(tree,root->right,root->key);

	}


	else
	{
		//printf("\n%d deleted",root->key);
		temp=root;
		if(root->left==NULL)
		{

			root=root->right;

		}



		else
		{

			root=root->left;


		}
		free(temp);--tree->mass;
	}
	
//printf("mass here %d \n",tree->mass);


	return root;
}




BST* bst_delete_reccursive(BST *tree,int32_t key)
{

	TreeNode *root=_bst_delete_(tree,tree->root,key);
	tree->root=root;
	return tree;
}

static void _inorder_(TreeNode *root){

	if(root)
	{

		_inorder_(root->left);
		printf("%d\t",root->key);
		_inorder_(root->right);


	}

}


BST* bst_traverse_inorder_reccursive(BST *tree)
{

_inorder_(tree->root);
return tree;

}

static void _pre_order_(TreeNode *root)
{

	if(root)
	{
		printf("%d\t",root->key);
		_pre_order_(root->left);

		_pre_order_(root->right);


	}


}

BST* bst_traverse_preorder_reccursive(BST *tree)
{

	_pre_order_(tree->root);

	return tree;

}



static void _post_order_(TreeNode *root)
{

	if(root)
	{

		_post_order_(root->left);

		_post_order_(root->right);

		printf("%d\t",root->key);
	}


}


BST* bst_traverse_postorder_reccursive(BST *tree)
{

	_post_order_(tree->root);
	return tree;



}



BST* bst_traverse_levelorder(BST *tree)
{

	Queue q=queue_new(20);

	QueueResult res;
	int i=0;
	TreeNode *root = tree->root;
	queue_add(&q,root,&res);
	for(;;)
	{
	
	root=q.q[q.head];

if(root!=NULL)
{
printf("\t%d",q.q[q.head]->key);
}

		queue_remove(&q,&res);
		if(root)
		{

			
			if(root->left)
			{
				queue_add(&q,root->left,&res);
				
				

			}
			if(root->right)
			{
				queue_add(&q,root->right,&res);
				

			}

		}

		else
		{
			break;
		}


	}

	return tree;
}



BST* bst_traversal_inorder_iterative(BST *tree)
{
	Stack stk=stack_new(10);

	StackResult res;

	TreeNode *root=tree->root;

	while(root!=NULL || !stack_empty(&stk))
	{
		if(root)
		{
			//printf("\t%d",root->key);
			stack_push(&stk,root,&res);
			root=root->left;



		}

		else
		{	
			//if(root==NULL)printf("\nelse");
			
			stack_pop(&stk,&res);
			root=res.data;
			printf("%d\t",res.data->key);
			root=root->right;

		}

		



	}


	//stack_delete(&stk);
	return tree;


}
