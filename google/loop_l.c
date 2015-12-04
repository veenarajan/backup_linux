#include "ll.c"

int loop(struct node* head)
{
	struct node* fast = head;
	struct node* slow = head;
	int flag = 0;
	while(fast!=NULL && fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
		{
			printf("fast%d\n", fast->data);
			printf("slow%d\n", fast->data);
			return 1;
		}
	}

	

	return 0;
}


int main(int argc, char const *argv[])
{
	struct node* head[5];
	head[0]  = getnewnode(5);
	head[1]  = getnewnode(6);
	head[2]  = getnewnode(7);
	head[3]  = getnewnode(8);
	head[4]  = getnewnode(9);

	head[0]->next = head[1];
	head[1]->next = head[2];
	head[2]->next = head[3];
	head[3]->next = head[4];
	head[4]->next = head[2];

	int k = loop(*head);
	printf("%d\n",k );
	 
	return 0;
}