#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* getnewnode(int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));

	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = data;

	return newnode;
}

struct node* insert(struct node* root, int data)
{
	//struct node* newnode = getnewnode(data);
	if (root == NULL)
	{
		return getnewnode(data);
	}

	if (data < root->data)
	{
		root->left = insert(root->left, data);
	}else
	{
		root->right = insert(root->right, data);
	}

	return root;
}


void print(struct node* root)
{
	if (root == NULL)
	{
		return;
	}
	print(root->left);
	printf("%d\n", root->data);
	print(root->right);
}

void mirror(struct node* root)
{
	if (root == NULL)
	{
		return;
	}

	mirror(root->left);
	mirror(root->right);

	struct node* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

int max(int a, int b)
{
	return a > b ? a : b; 
}

int getheight(struct node* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1+max(getheight(root->left), getheight(root->right));
}

void print_atlevel(struct node* root, int level)
{
	int i;
	if (root == NULL)
	{
		return;
	}
	if (level == 1)
	{
		printf("%d\n", root->data);
	}
	else if(level > 1)
	{
		
		print_atlevel(root->left, level-1);
		
		print_atlevel(root->right, level-1);
	
	}
}

void traverse(struct node* root)
{
	int height  = getheight(root);
	printf("%d\n",height );
	int i = 0;
	for (i = 1; i <= height; i++)
	{
		printf("%d\t", i);
		print_atlevel(root, i);
	}
}
int main(int argc, char const *argv[])
{
	struct node* root = NULL;
	root = insert(root, 10);
	root = insert(root, 2);
	root = insert(root, 30);
	root = insert(root, 4);
	root = insert(root, 50);


	print(root);


	//mirror(root);
	//print(root);


	printf("******************************\n");

	traverse(root);
	return 0;
}