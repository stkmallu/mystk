#include<stdio.h>
#include<stdlib.h>

struct queue{
int front, rear, size;
int capacity;
int *array;
};

struct queue *createqueue(int capacity);
void enqueue(struct queue *queue, int val);
int dequeue(struct queue *queue);

main()
{
    int option,num;
    struct queue *queue = createqueue(5);

    for(;;)
    {
        printf("\n ENQUEUE:1 DEQUEUE:2 FRONT:3 REAR:4 EXIT:5 :");
        scanf("%d",&option);

        switch(option)
        {

            case 1:
                printf("Enter the number:");
                scanf("%d",&num);
                enqueue(queue,num);
                break;

            case 2:
                num = dequeue(queue);
                printf("NUM = %d\n",num);
                break;

            case 3:
                //num = front(queue);
                printf("FRONT = %d\n",queue->front);
                break;

            case 4:
                //num = rear(queue);
                printf("REAR = %d\n",queue->rear);
                break;

            case 5:
                exit(0);

            default:
                printf("\n Invalid Input\n");
        }
    }
}

struct queue *createqueue(int capacity)
{
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
    if (queue == NULL)
        return NULL;

    queue->capacity = capacity;
    queue->front = queue->rear = queue->size = 0;

    queue->array = (int *)malloc(queue->capacity * sizeof(int));

    if(queue->array == NULL)
    {
        free(queue);
        return NULL;
    }

    return queue;
}


void enqueue(struct queue *queue, int val)
{
    if(queue->size == queue->capacity)
    {
        printf("Queue if Full\n");
        return;
    }

    queue->array[queue->rear] = val;
    queue->size++;
    queue->rear = (queue->rear +1) %5;
}


int dequeue(struct queue *queue)
{
    int val;
    printf("Size = %d\n",queue->size);
    if(queue->size == 0)
    {
        printf("Queue Empty\n");
        return -1;
    }

    val = queue->array[queue->front];
    queue->front = (queue->front +1) % 5;
    queue->size--;
    return val;
}
