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
  newnode->next = NULL;
  newnode->data = data;
  return newnode; 
}

struct node* insertattail(struct node* head, int data)
{
  struct node* temp = head;
  if (temp == NULL)
   {
     temp = getnewnode(data);
     return temp;
   }
   
   struct node* newnode = getnewnode(data);
   while(temp->next!=NULL)
   {
    temp = temp->next;
  }
  temp->next = newnode;
  newnode->next = NULL;

  return head; 

}

struct node* insertathead(struct node* head, int data)
{
  struct node* temp = head;
  if (temp == NULL)
   {
     temp = getnewnode(data);
     return temp;
   }
   
  struct node* newnode = getnewnode(data);
  newnode->next = temp;
  return newnode; 

}

struct node* delete(struct node* head, int x)
{
  struct node* temp = head;
  if (temp->data == x)
  {
    temp = head->next;
    free(head);
    head->next = NULL;
    return temp;
  }

  
  //temp >next ->next concept
  /*
  while(temp->data!=x)
  {
      temp = temp->next;
  }
  if (temp->next==NULL)
  {
      free(temp);
      return head
  }

  */
  return head;
}

struct node* insertatn(struct node* head, int n, int x)
{
    int i = 0;
    struct node* temp = head;
    struct node* newnode;
  
    for (i = 0; i < n-1; i++){
      temp = temp->next;
    }
    newnode = getnewnode(x);
    if (temp->next!=NULL)
    {
      newnode->next = temp->next;
      temp->next = newnode;
    }
    
    return head;
}

struct node* reverse(struct node* head)
{
  struct node* new_head = NULL;
  while (head) 
  {
    struct node* next =6633 head->next;
    head->next = new_head;
    new_head = head;
    head = next;
  }
  return new_head;
}

void print(struct node* head)
{
  struct node* temp = head;
  while(temp!=NULL)
  {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}

int main(int argc, char const *argv[])
{
  struct node* head;
  head = insertattail(head, 10);
  head = insertattail(head, 20);
  head = insertattail(head, 40);
  head = insertattail(head, 60);

  print(head);

  printf("************************************\n");

  head = insertathead(head, 11);
  head = insertathead(head, 22);
  head = insertathead(head, 43);
  head = insertathead(head, 64);

  print(head);


  printf("***************************\n");
  
  head = insertatn(head, 4, 99);
  print(head);


  printf("***************************\n");
  
  head = reverse(head);
  print(head);

  return 0;
}