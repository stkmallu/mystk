#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node{
int data;
struct node *next;
};

void push(struct node **head, int val);
int pop(struct node **head);

main()
{

struct node *head = NULL;
int val;

push(&head, 1);
push(&head, 2);
push(&head, 3);

val = pop(&head);
printf("value = %d\n",val);


val = pop(&head);
printf("value = %d\n",val);
}

void push(struct node **head, int val)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if(node == NULL)
    {
        printf("No Memory\n");
        exit(EXIT_FAILURE);
    }
    
    node->data = val;
    node->next = *head;
    *head = node;
}

int pop(struct node **head)
{

    int val;
    struct node *temp;
    if(*head == NULL)
    {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    val = (*head)->data;
    temp = *head;
    *head = (*head)->next;
    free(temp);

    return val;
}
