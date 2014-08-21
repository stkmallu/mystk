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
