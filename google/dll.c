#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* prev;
	struct node* next;
};

struct node* getnewnode(int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
}

// insert at head

void insert(struct node** head_ref, int data)
{
	struct node* newnode = getnewnode(data);
	newnode->next = *head_ref;
	newnode->prev = NULL;

	// connect to the other node !

	if ((*head_ref) != NULL)
	{
		(*head_ref)->prev = newnode;
	}

	(*head_ref) = newnode;
}

struct node* insert_at_tail(struct node* head, int data)
{
	struct node* temp = head;

	while(head->next!=NULL)
	{
		head= head->next;
	}

	struct node* newnode = getnewnode(data);

	newnode->next = NULL;
	head->next = newnode;

	return temp;
}


void delete_from_head(struct node** head_ref)
{
	struct node* temp = (*head_ref);
	*head_ref = (*head_ref)->next;
	temp->next = NULL;
	free(temp);
}

struct node* delete_from_tail(struct node* head)
{
	struct node* temp = head;
	while(head->next->next!=NULL)
	{
		head = head->next;
	}

	free(head->next);
	head->next = NULL;
	return temp; 
}

int search(struct node* head, int data)
{
	int flag = 0;
	if(head == NULL)
		return 0;
	else
	{
		while(head->next!=NULL)
		{
			if(head->data == data)
			{
				return 1;
			}
			head = head->next;
		}
	}
	return 0;
}


struct node* insert_at_n(struct node* head, int data, int position)
{
	struct node* temp = head;
	int i = 0;
	struct node* newnode = getnewnode(data);
	for (i = 0; i < position-2; i++)
	{
		head = head->next;
	}

	newnode->next = head->next->next;
	head->next = newnode;

	return temp;
}

struct node* delete_at_n(struct node* head, int position)
{
	struct node* temp = head;
	struct node* ptr;
	int i = 0;
	for(i = 0; i < position-2; i++)
	{
		head = head->next;
	}
	
	ptr = head->next;
	head->next = head->next->next;
	head->next->prev = head;

	ptr->next = NULL;
	ptr->prev = NULL;
	free(ptr);

	return temp;
}

void reverse(struct node** head_ref)
{
	struct node *temp = NULL; 
	struct node *current = *head_ref;
	
	/* swap next and prev for all nodes of 
	doubly linked list */
	while (current != NULL)
	{
	temp = current->prev;
	current->prev = current->next;
	current->next = temp;			 
	current = current->prev;
	}	 
	
	/* Before changing head, check for the cases like empty 
		list and list with only one node */
	if(temp != NULL )
		*head_ref = temp->prev;
}
void print_list(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}


int main(int argc, char const *argv[])
{
	struct node* head = NULL;

	insert(&head, 10);
	insert(&head, 20);
	insert(&head, 30);
	insert(&head, 40);
	insert(&head, 50);
	insert(&head, 60);
	insert(&head, 70);

	//print_list(head);

	head = insert_at_tail(head, 11);
	head = insert_at_tail(head, 12);
	head = insert_at_tail(head, 13);
	head = insert_at_tail(head, 14);
	head = insert_at_tail(head, 15);

	//print_list(head);

	delete_from_head(&head);
	//print_list(head);

	head = delete_from_tail(head);
	//print_list(head);
	
	int k = search(head, 99);
	//printf("%d\n", k);
	
    head = insert_at_n(head, 99, 5);
    //print_list(head);

    head = delete_at_n(head, 5);
    print_list(head);

    reverse(&head);
    print_list(head);

	return 0;
}
