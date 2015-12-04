#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* next;
	struct node* prev;
	int data;
}node;

node* getnewnode(int data)
{
	node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
}

void insert(node** head, int data)
{
	node* newnode = getnewnode(data);
	newnode->next = *head;
	newnode->prev = NULL;

	if (*head !=NULL)
	{
		(*head)->prev = newnode;
	}

	(*head) = newnode;
}


node* insert_attail(node* head, int data)
{
	node* temp = head;
	node* newnode = getnewnode(data);
	
	while(head->next!=NULL)
	{

		head = head->next;
	}
	head->next = newnode;
	newnode->prev = head;

	return	temp;

}

void search(node* head, int data)
{
	int flag = 0;
	while(head)
	{
		if (head->data == data)
		{
			flag = 1;
			break;
		}
		head = head->next;
	}

	if (flag)
	{
		printf("found\n");
	}
	else
	{
		printf("not found\n");
	}
}

node* insert_at_n(node* head, int position, int data)
{
	int count = 0;
	int i;
	node* temp = head;
	mode* newnode = getnewnode(data);
	while(head)
	{
		count++;
		head = head->next;
	}
	head = temp;
	if (position >count)
	{
		return;
	}
	for (i = 0; i < position-1; i++)
	{
		head = head->next;
	}


}
void print(node* head)
{
	while(head)
	{
		printf("%d\t", head->data);
		head = head->next;
	}

	printf("\n");
}


int main()
{
	node* head = NULL;
	
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);

	print(head);

	head = insert_attail(head, 6);
	head = insert_attail(head, 7);

	print(head);

	search(head, 7);

	return 0;
}
