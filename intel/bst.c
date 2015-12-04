#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	struct node* right;
	struct node* left;
};

struct node* getnewnode(int x)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->right = NULL;
	newnode->left = NULL;
	newnode->data = x;
	return newnode;
}

struct node* insert(struct node* root, int x)
{
	if (root == NULL)
	{
		root = getnewnode(x);
		return root;
	}

	if (root->data > x)
	{
		root->left = insert(root->left, x);
	}
	else if (root->data <x)
	{
		root->right = insert(root->right, x);	
	}

	return root;
}

void inorder_print(struct node* root)
{
	if (root == NULL)
		{
			return;
		}
	inorder_print(root->left);
	printf("%d\n", root->data);
	inorder_print(root->right);	
}

struct node* mirror_bst(struct node* root)
{
	struct node* temp;
	if (root == NULL)
		return;
	root->right = mirror_bst(root->right);
	root->left =mirror_bst(root->left);

	temp = root->left;
	root->left = root->right;
	root->right = temp;
	
	return root;
}

int search(struct node* root, int data)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		if (root->data == data)
		{
			return data;
		}
		else if (root->data < data)
		{
			search(root->left, data);
		}
		else
		{
			search(root->right, data);	
		}
	}
}


/*int verify(struct node* root)
{
	if (root==NULL)
	{
		return;
	}
	else
	{
		if (root->left->data < root->right->data)
		{
			verify(root->left);
			verify(root->right);
		}
	}
}
*/


// travrse in order and check if it is sorted

/*int verify(struct node* root)
{
	static struct node* prev = NULL;
	if (root!=NULL)
	{
		if (!verify(root->left))
			return -1;

		if (prev!=NULL && root->data <= prev->data)
		{
			return -1;
		}

		prev = root;

		return verify(root->right);	   
	}

	//return 1;
}*/


/* Returns true if a binary tree is a binary search tree */
int isBST(struct node* root) 
{ 
  if (root == NULL) 
    return(true); 
     
  /* false if the max of the left is > than us */
  if (root->left!=NULL && maxValue(root->left) > root->data) 
    return(false); 
     
  /* false if the min of the right is <= than us */
  if (root->right!=NULL && minValue(root->right) < root->data) 
    return(false); 
   
  /* false if, recursively, the left or right is not a BST */
  if (!isBST(root->left) || !isBST(root->right)) 
    return(false); 
     
  /* passing all that, it's a BST */
  return(true); 
} int main(int argc, char const *argv[])
{
	
	struct node* root = NULL;
	int k;
	root = insert(root, 5);
	root = insert(root, 7);
	root = insert(root, 9);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 8);

	inorder_print(root);

	mirror_bst(root);
	printf("***********************************************");
	inorder_print(root);

	k= search(root, 8);
	printf("kkkkk%d\n", k);


	k= verify(root);

	printf("kkkkk%d\n", k);



	return 0;
}
