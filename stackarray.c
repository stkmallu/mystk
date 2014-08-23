#include<stdio.h>
#include<stdlib.h>


struct stack
{
  int top;
  int capacity;
  int *array;
};


struct stack *createstack (int capacity);
void push (struct stack *stack, int value);
int pop (struct stack *stack);


main ()
{

  int val = 0;
  struct stack *Stack = createstack (5);

  push (Stack, 1);
  push (Stack, 2);
  push (Stack, 3);
  push (Stack, 4);
  push (Stack, 5);
  push (Stack, 6);

  val = pop(Stack);
  printf ("Value = %d\n", val);

  val = pop(Stack);
  printf ("Value = %d\n", val);
}

struct stack *
createstack (int capacity)
{
  struct stack *stack = (struct stack *) malloc(sizeof (struct stack));
  if (stack == NULL)
    {
      return NULL;
    }

  stack->capacity = capacity;
  stack->top = -1;
  stack->array = malloc (5 * sizeof (int));

  if (stack->array == NULL)
    return NULL;

  return stack;
}


void push(struct stack *stack, int value)
{
    if(stack->top == (stack->capacity - 1))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = value;
}

int pop(struct stack * stack)
{
    int val = 0;
    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    val = stack->array[stack->top--];
    return val;
}
Enter file contents here
