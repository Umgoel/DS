#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

void push (struct node **head_ref, int new_data)
{
  struct node *new_node = (struct node *) malloc (sizeof (struct node));
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

void append (struct node **head_ref, int new_data)
{
  struct node *new_node = (struct node *) malloc (sizeof (struct node));
  struct node *last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL)
    {
      *head_ref = new_node;
      return;
    }
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  return;
}

void insert_pos(struct node **head_ref, int new_data, int pos){
    struct node *new_node = (struct node *) malloc (sizeof (struct node));
    struct node *ptr = *head_ref;
    int i;
    new_node->data = new_data;
    for(i=1;i<pos-1;i++){
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}
void display (struct node *n)
{
  while (n != NULL)
    {
      printf ("\n%d", n->data);
      n = n->next;
    }
}

int main ()
{
  printf ("start\n");
  struct node *head = NULL;
  append (&head, 10);
  append (&head, 20);
  insert_pos(&head, 2, 2);
  display (head);
}