#include<stdio.h>
#include<stdlib.h>


struct node{
int val;
struct node *next;
};

struct Queue{
struct node *front;
struct node *rear;
};

struct Queue *createqueue();
void enqueue(struct Queue *q, int val);
int dequeue(struct Queue *q);

main()
{
    struct Queue *q = createqueue();
    int val;
    if (q == NULL)
    {
        printf("Memeory Allocation Failed\n");
        return 1;
    }

    enqueue(q,1);
    enqueue(q,2);

    val = dequeue(q);
    printf("Removed; %d\n",val);
    val = dequeue(q);
    printf("Removed; %d\n",val);
}

struct Queue *createqueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->rear = q->front = NULL;
    if(q == NULL)
        return NULL;

    return q;
}


void enqueue(struct Queue *q, int val)
{

    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->val = val;
    node->next=NULL;

    if(q->rear == NULL)
    {
        q->rear = node;
        q->front = node;
    }
    else
    {
        q->rear->next = node;
        q->rear = node;
    }
}


int dequeue(struct Queue *q)
{
    int val;
    struct node *temp;
    if(q->front == NULL)
    {
        printf("List is Empty\n");
        return -1;
    }
    temp = q->front;
    val = temp->val;
    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;
    free(temp);
    return val;
}

