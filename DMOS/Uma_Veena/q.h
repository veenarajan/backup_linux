//To implement a circular queue using doubly linked list
#include "TCB.h"

void initQ(TCB_t *head);
void AddQ(TCB_t **h, TCB_t *item);
void RotateQ(TCB_t **head);
TCB_t* DelQ(TCB_t **head);

void initQ(TCB_t *head)
{
	head = NULL;
}

void AddQ(TCB_t **head, TCB_t* item)
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

TCB_t* DelQ(TCB_t **head)
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

void RotateQ(TCB_t **head)
{
	TCB_t *tmp;
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = tmp;
	tmp->next = (*head);
}
