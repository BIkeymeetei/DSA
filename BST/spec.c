#include<stdio.h>
#include "BST.c"

void test_bst()
{

	BST bst_instance=bst_new();
	BST *bst=&bst_instance;
	bst=bst_add(bst,10);
	


	bst=bst_add(bst,5);
	bst=bst_add(bst,15);
	assert(bst->mass==3);
	bst=bst_add(bst,3);
	bst=bst_add(bst,25);
	

	
	
	assert(bst_find(bst,5)==1);
	assert(bst_find(bst,15)==1);
printf("\nlevel order\t");
	bst_traverse_levelorder(bst);	

	
	printf("\ninorder iterative\t");
	bst_traversal_inorder_iterative(bst);

	
	

	printf("\ninorder reccursive\t");
	bst_traverse_inorder_reccursive(bst);


	

	printf("\npreorder reccursive\t");
	bst_traverse_preorder_reccursive(bst);


	printf("\npostorder reccursive\t");
	bst_traverse_postorder_reccursive(bst);



	bst=bst_delete_reccursive(bst,15);
	//printf("mnass %d\n",bst->mass);
	assert(bst->mass==4);

	assert(_height_(bst->root)==3);



}

void main()
{

	test_bst();

	printf("\nexecuted successfully\n");
}
