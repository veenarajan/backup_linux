#include "TCB.h"

#include <stdio.h>

#include <stdlib.h>


struct TCB_t q_element;

TCB_t *head;

void InitQueue (TCB_t *element)
{
    element = NULL; //set the new element to null initially
}

TCB_t *NewItem()
{
          TCB_t *item;                              //create object of struct tcb_t
          item = (TCB_t*) malloc (sizeof(TCB_t));   //assign the object size
          return item;

}

void AddQueue (TCB_t **element, TCB_t *item)
{
    TCB_t *temp = NULL;
    if (*element == NULL)  //check if the head provided in the function is null
        {
            *element = item;                    //if null then assign the item provided
            (*element)->prev = *element;    //assign prev pointer to element
            (*element)->next = *element;        //set next pointer of the element to element
        }

    else
        {
            temp = (*element)->prev;            //assign element's prev pointer to temp
            temp->next = item;                      //set temp's next to item
            temp = temp->next;                      //set temp pointer goes to temp.next
            temp->next = *element;                  //set temp.next=element
            temp->prev = (*element)->prev;  //and temp's prev to element's prev
            (*element)->prev = temp;            //set element's prev to temp
        }
}

TCB_t *DelQueue (TCB_t **element)
{
        TCB_t *temp;

        if ( *element == NULL)
        {
            printf("empty queue\n");        //element pointer provided is null so Queue is empty
            return NULL;
        }
        else if ((*element)->next == *element)
        {
            temp = *element;
            *element = NULL;
            return temp;
        }
        else
        {
            temp = *element;
            (*element) = (*element)->next;
            (*element)->prev = temp->prev;
            temp->prev->next=*element;
            temp->next = NULL;
            temp->prev = NULL;
            return temp;
        }
}

void RotateQ(TCB_t **element)
{
            if ( *element == NULL)
            {
                printf("Queue Empty");
                return;
            }

            *element = (*element)->next;
}
