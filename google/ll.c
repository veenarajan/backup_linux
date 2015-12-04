#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* getnewnode(int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

void insert_athead(struct node** head_ref, int data)
{
	struct node* newnode;
	if (*head_ref == NULL)
	{
		newnode = getnewnode(data);
		*head_ref = newnode;
		return;
	}

	newnode = getnewnode(data);
	newnode->next = *head_ref;
	*head_ref= newnode;
}

struct node* insert_attail(struct node* head_ref, int data)
{
	struct node* newnode;
	struct node* temp = head_ref;
	if (head_ref == NULL)
	{
		newnode = getnewnode(data);
		temp = head_ref = newnode;
	}
	else
	{
		while(head_ref->next!=NULL)
		{
			head_ref = head_ref->next;
		}
		newnode = getnewnode(data);
		head_ref->next = newnode;
	}

	return temp;
}

void remove_fromhead(struct node** head_ref)
{
	struct node* temp = *head_ref;
	*head_ref = (*head_ref)->next;
	temp->next = NULL;
	free(temp);
}


struct node* remove_fromtail(struct node* head_ref)
{
	struct node* temp = head_ref;

	while(head_ref->next->next!=NULL)
	{
		head_ref = head_ref->next;
	}

	free(head_ref->next);
	head_ref->next = NULL;
	
	return temp; 

}

struct node* add_at_n(struct node* head, int position, int data)
{
	struct node* temp  = head;
	struct node* newnode;
	int i = 0;
	
	for (i = 0; i < position-2; i++)
	{
		head = head->next;
	}

	newnode = getnewnode(data);
	newnode->next = head->next;
	head->next = newnode;

	return temp; 
}

struct node* remove_at_n(struct node* head, int position, int data)
{
	struct node* temp  = head;
	struct node* newnode;
	struct node* prev;
	int i = 0;
	
	for (i = 0; i < position-1; i++)
	{
		prev = head;
		head = head->next;
	}

	prev->next = head->next;
	free(head);

	return temp; 	
}

void print(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

void print_rec(struct node* head)
{
	if (head==NULL)
	{
		return;
	}
	printf("%d\n", head->data);
	print_rec(head->next);
}

void number(struct node* head)
{
	int count= 0;
	while(head)
	{
		count++;
		head = head->next;
	}

	printf("COUNT %d\n", count);
}


void search(struct node* head, int data)
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
		printf("Found\n");
	}
	else
	{
		printf("not found\n");
	}
}
int rec_search(struct node* head, int data)
{
	if (head== NULL)
	{
		return;
	}
	if(head->data == data)
		return 1;
	rec_search(head->next, data);

}
// hand run to understand !!

void reverse(struct node** head_ref)
{
	struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;

}
// 1. use a stack and check
// push on to stack and while pooing compare if same

//2. reverse the linked list and compare if same.

void palindrome(struct node* head)
{
	int count = 0;
	int i = 0;
	
	printf("here");
	struct node *temp = head;
	//printf("%d\n", temp->next->data);
	while(head)
	{
		count++;
		head = head->next;

	}
	// revers the linked list
	//printf("%d", count);
	reverse(&head);
	printf("%d\n", head == NULL ? 1: 0);
	print(head);
	i = count/2;
	while(i)
	{
		//if (head->next->data == temp->next->data)
		{
			i--;
		}
		//else
		{
			break;
		}

	}

	if (i==count/2)
	{
		printf("palindrome\n");
	}
	else
	{
		printf("not a palindrome\n");
	}
}

struct node* move_to_head(struct node*  head)
{
	struct node* temp = head;
	struct node* prev = NULL;
	while(head->next)
	{
		prev = head;
		head = head->next;
	}

	//printf("%d,%d\n", head->data, prev->data);
	prev->next = NULL;
	head->next = temp;
	temp = head;

	return temp;


}
#if 0
int main()
{
	struct node* head = NULL;
	insert_athead(&head, 10);
	insert_athead(&head, 20);
	insert_athead(&head, 30);
	insert_athead(&head, 40);
	insert_athead(&head, 50);
	insert_athead(&head, 60);

	print(head);
	printf("*******************************\n");

	print_rec(head);
	printf("*******************************\n");

	head = insert_attail(head, 11);

	print(head);
	printf("**************************************\n");

	remove_fromhead(&head);

	print(head);
	printf("**************************************\n");

	head = remove_fromtail(head);

	print(head);
	
	printf("**************************************\n");

	head = add_at_n(head, 3, 99);

	print(head);
	
	printf("**************************************\n");

	head = remove_at_n(head, 3, 99);

	print(head);
	printf("**************************************\n");

	number(head);


	printf("***********************\n");

	search(head, 40);

	printf("****************\n");

	printf("%d\n", rec_search(head, 101));

	printf("****************\n");

	reverse(&head);

	print(head);

	/*struct node* check = NULL;
	insert_athead(&check, 1);
	insert_athead(&check, 1);
	insert_athead(&check, 0);
	insert_athead(&check, 1);
	insert_athead(&check, 1);

	print(check);

	palindrome(check);
	*/

	struct node* check = move_to_head(head);
	printf("node moved to head\n");
	print(check);
	return 0;
}


#endif

