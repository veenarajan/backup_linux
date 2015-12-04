#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

void MorrisTraversal(struct node *root)
{
	struct node *current,*pre;

	if(root == NULL)
		return; 

	current = root;
	
	while(current != NULL)
	{				 
		if(current->left == NULL)
		{
			printf("upper%d  ", current->data);
			current = current->right;	 
		} 
		else
		{
			/* Find the inorder predecessor of current */
			pre = current->left;
			while(pre->right != NULL && pre->right != current)
				pre = pre->right;

			/* Make current as right child of its inorder predecessor */
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}
			
			/* Revert the changes made in if part to restore the original tree i.e., fix the right child of predecssor */
			else
			{
				pre->right = NULL;
				printf("lower%d ",current->data);
				current = current->right;	 
			} 
		} 
	} 
}

struct node* newnode(int data)
{
	struct node* node = (struct node*)
					malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

int main()
{

	/* Constructed binary tree is
			1
		/ \
		2	 3
	/ \
	4	 5
	*/
	struct node *root = newnode(1);
	root->left	 = newnode(2);
	root->right	 = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5); 

	MorrisTraversal(root);

	return 0;
}
