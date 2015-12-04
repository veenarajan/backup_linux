#include "ll.c"


struct node* find_common_node(struct node* head_1, struct node* head_2)
{
	struct node* common = NULL;
	
	int it = abs(head_1->size - head_2->size);
	while(it)
	{
		if (head_1->size > head_2->size)
		{
			head_1 = head_1->next;
		
		}
		else
		{
			head_2 = head_2->next;

		}
		it--;
	}
	while(head_1!=NULL && head_2!=NULL)
	{
		if (head_1 == head_2)
		{
			printf("common node found !! \n");
			common  = head_1;
			return common;
		}
		else
		{
			head_1 = head_1->next;
			head_2 = head_2->next;
		}
	}

	return common;
}

int main(int argc, char const *argv[])
{
	struct node* head_1 = NULL;
	struct node* newnode = getnewnode(100);
	
	head_1 = insert_attail(head_1, 10);
	head_1 = insert_attail(head_1, 20);
	head_1 = insert_attail(head_1, 30);
	head_1 = insert_attail(head_1, 40);
	head_1 = insert_attail(head_1, 50);
	
	newnode->next  = head_1->next->next->next;
	head_1->next->next = newnode;

	struct node* head_2 = NULL;
	head_2 = insert_attail(head_2, 11);
	head_2 = insert_attail(head_2, 22);
	head_2 = insert_attail(head_2, 33);
	head_2 = insert_attail(head_2, 99);
	 
	newnode->next  = head_2->next->next;
	head_2 ->next = newnode;

	struct node* common  = find_common_node(head_1, head_2);
	if (common!=NULL)
	{
		printf("Data is %d\n",common->data);
	}
	else
	{
		printf("No node commo \n");
	}
	return 0;
}