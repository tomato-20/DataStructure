//static implementation of stack (ie. using array)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 25

typedef struct Stack
{
    int items[MAX];
    int top;
} st;

void create_empty_stack(st *);
void push(st *, int);
int pop(st *);
int top(st *);
int is_empty(st *);
int is_full(st *);
void display(st *);

int main(void)
{
    int opt, data, flag = 1;
    st s, *sp;
    sp = malloc(sizeof(st));
    create_empty_stack(sp);
    printf("1.PUSH\n2.POP\n3.Peek\n4.Display\n5.Exit\n\n");

    do
    {
        printf("Choose an option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &data);
            push(sp, data);
            break;
        case 2:
            printf("%d is popped.\n", pop(sp));
            break;
        case 3:
            printf("%d is in top of the stack.\n", top(sp));
            break;
        case 4:
            display(sp);
            break;
        case 5:
            flag = 0;
            printf("Exiting..!\n");
            break;
        default:
            printf("Invalid input!!\n");
        }
    } while (flag);

    return 0;
}

//create an stack
void create_empty_stack(st *s)
{
    s->top = -1;
}

// check if stack is empty
int is_empty(st *s)
{
    return s->top == -1;
}

// check if stack is full
int is_full(st *s)
{
    return s->top == (MAX - 1);
}

// insert an element into the stack
void push(st *s, int data)
{
    if (is_full(s))
        printf("Stack overflow!!\n");
    else
        s->items[++(s->top)] = data;
}

// delete an elemet from the stack
int pop(st *s)
{
    if (is_empty(s))
    {
        printf("Stack Underflow!!\n");
        return INT_MIN;
    }
    else
    {
        int popped_item = s->items[s->top];
        s->top--;
        return popped_item;
    }
}

//return an element from top of the stack without deletion
int top(st *s)
{
    if (is_empty(s))
    {
        printf("stack is empty!!\n");
        return INT_MIN;
    }
    else
    {
        return s->items[s->top];
    }
}

//display contents of the stack
void display(st *s)
{
    if (is_empty(s))
    {
        printf("Stack is empty!!\n");
    }
    else
    {
        printf("Items in stack: ");
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}