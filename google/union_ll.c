#include "ll.c"
// TODO: rectify logic 
struct node* find_union(struct node* list_1, struct node* list_2)
{
	struct node* temp;
	while(list_1 && list_2)
	{
		if (list_1->data < list_2->data)
		{
			if(temp == NULL)
				temp = list_1;
			else
				{
					temp->next = list_1;
					list_1 = list_1->next;
				 }
		}
		else
		{
			if (temp == NULL)
			{
				temp = list_2;
			}
			else
			{
				temp->next = list_2;
				list_2 = list_2->next;
				
			}
			//temp = temp->next;
		}
	}

	if (list_1)
	{
		temp->next = list_1;
	}
	else
	{
		temp->next = list_2;
	}
	return temp;
}


struct node* get_middle(struct node* head)
{
	struct node* fast = head;
	struct node* slow = head;
	struct node* middle = head;

	while(fast!= NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	middle = slow;

	return middle;
}

int identical_list(struct node* list_1, struct node* list_2)
{
	int flag = 0;
	while(list_1 && list_2)
	{
		if (list_1->data == list_2->data)
		{
			list_1 = list_1->next;
			list_2 = list_2->next;
		}
		else
		{
			return 0;
		}


	}

	return 1;
}

struct node* add_list(struct node* list_1, struct node* list_2)
{
	int carrier = 0;
	int sum = 0;
	int i;
	int size = 0;
	int tsum = 0;
	struct node* temp1 = list_1;

	struct node* temp2 = list_2;
	struct node* restult = NULL;
	while(temp1 && temp2)
	{
		for (i = 0; i < 1-size ; i++)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		//print(temp2);
		tsum = carrier + temp1->data + temp2->data;

		carrier = tsum / 10;
		tsum = tsum % 10; 
		//printf("tsum :: %d , sum :: %d , carrier %d\n",tsum , sum, carrier );
		insert_athead(&restult, tsum);

		temp2 = list_2;
		temp1 = list_1;

		size++;

		if (size == 2)
		{
			if (carrier > 0)
			{
				insert_athead(&restult, carrier);
			}
			break;
		}
	}


	return restult;

}
void delete_multiple(struct node* head, int skip, int del)
{
	struct node* temp = head;
	struct node* temp1;
	int i;
	

	//while(head)
	//{
		for (i = 1; i < skip && head; i++)
		{
			head = head->next;
		}

		if (head == NULL)
		{
			return;
		}
		
		temp1 = head->next;
		
		for (i = 1; i <= del && head; i++)
		{
			struct node* t = temp1;
			temp1 = temp1->next;
			free(t);
		}
		//printf("%d\n",temp1->data );
		
		head->next = temp1;
		
		head = temp1;

	//}

		//return head;


}

struct node* rotate_list(struct node* head, int n)
{
	struct node* temp;
	
	temp = move_to_head(head);
	while(--n)	
		temp = move_to_head(temp);
		
	return temp;
}

 
int main()
{
	
	struct node* list_1 = NULL;
	insert_athead(&list_1, 9);
	insert_athead(&list_1, 9);
	//insert_athead(&list_1, 30);
	//insert_athead(&list_1, 40);
	//insert_athead(&list_1, 50);

	//print(list_1);

	struct node* list_2 = NULL;
	insert_athead(&list_2, 1);
	insert_athead(&list_2, 0);
	//insert_athead(&list_2, 30);
	//insert_athead(&list_2, 40);
	//insert_athead(&list_2, 50);

	//print(list_2);

	struct node* un = get_middle(list_1);
	printf("%d\n",un->data );

	int k = identical_list(list_1, list_2);
	if (k==0)
	{
		printf("not identical\n");
	}
	else
	{
		printf("identical\n");
	}

	struct node*  sum = add_list(list_1, list_2);
	//print(sum);

	struct node* head = NULL;
	insert_athead(&head, 10);
	insert_athead(&head, 20);
	insert_athead(&head, 30);
	insert_athead(&head, 40);
	insert_athead(&head, 50);
	insert_athead(&head, 60);
	insert_athead(&head, 70);
	print(head);
	printf("***********************\n");
	delete_multiple(head, 2,2);
	print(head);
	printf("******************\n");
	struct node* ro = rotate_list(head,3);
	print(ro);
	return 0;

}