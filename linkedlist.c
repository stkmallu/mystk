#include<stdio.h>
#include<stdlib.h>


struct node{
int data;
struct node *next;
};


void printlist(struct node *head);
void add(struct node **head, int num);
void delete(struct node **head, int num);
void printMiddle(struct node *head);
int printNth(struct node *head, int n);

main()
{
    struct node *head = NULL;
    int input,num;

    while(1)
    {
        printf("Add: 1, Delete: 2, Print: 3, Exit: 4 , Middle: 5:, printNth: 6 : ");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                printf("Enter the Number:");
                scanf("%d",&num);
                add(&head, num);
                break;

            case 2:
                printf("Enter the Number:");
                scanf("%d",&num);
                delete(&head, num);
                break;

            case 3:
                printlist(head);
                break;

            case 4:
                exit(0);
                break;

            case 5:
                printMiddle(head);
                break;

            case 6:
                printf("Enter the node number:");
                scanf("%d",&num);
                printNth(head, 1, num);
                break;

        }
    }
}

void printlist(struct node *head)
{
    printf("\n");
    while(head != NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
    }
}

void add(struct node **head, int num)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = num;

    node->next = *head;
    *head = node;
}

void delete(struct node **head, int num)
{
    struct node *temp = *head;
    struct node *prev = NULL;
    if(temp != NULL && temp->data == num)
    {
        *head = (*head)->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != num)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void printMiddle(struct node *head)
{
struct node *slow_ptr = head;
struct node *fast_ptr = head;

while(fast_ptr != NULL && fast_ptr->next != NULL)
{
    slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next->next;

}

printf("\nMiddle Element = %d\n",slow_ptr->data);
}

int printNth(struct node *head, int found, int n)
{
    struct node *ref1 = head;
    struct node *ref2 = head;

    int len = 0;

    while (ref1 != NULL && len < n)
    {
        ref1 = ref1->next;
        len++;
    }

    if(len != n)
    {
        printf("\nThe list does not have enough number of elements\n");
        return;
    }

    while(ref1 != NULL)
    {
        ref1 = ref1->next;
        ref2 = ref2->next;
    }

printf("\nThe %d-th element is %d\n",n,ref2->data); */

}
