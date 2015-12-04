//To implement a circular queue using doubly linked list
#include "TCB.h"

void initQueue(TCB_t *head);
void AddQueue(TCB_t **h, TCB_t *item);
void RotateQueue(TCB_t **head);
TCB_t* DelQueue(TCB_t **head);

void initQueue(TCB_t *head)
{
	head = NULL;
}

void AddQueue(TCB_t **head, TCB_t* item)
{
	TCB_t *tmp;
	if(*head == NULL)
	{
		// queue is empty
		(*head) = item;
		(*head)->next = item;
		(*head)->prev = item;
	}
	else
	{
		tmp = *head;
		while(tmp->next != *head)
			tmp = tmp->next;
		item->next = *head;
		item->prev = tmp;
		tmp->next = item;
		(*head)->prev = item;
	}
}

TCB_t* DelQueue(TCB_t **head)
{
	TCB_t *tmp = NULL;
	if(*head == NULL)
		printf("Queue is empty. No element to delete.\n");
	else if ((*head)->next == *head)
	{
		tmp = *head;
		*head = NULL;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	else
	{
		tmp = *head;
		*head = (*head)->next;
		(*head)->prev = tmp->prev;
		tmp->prev->next = *head;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	return tmp;
}

void RotateQueue(TCB_t **head)
{
/*	TCB_t *tmp;
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = tmp;
	tmp->next = (*head);
*/

	TCB_t *tmp;
	tmp = DelQueue(head);
	AddQueue(head, tmp);	

}
