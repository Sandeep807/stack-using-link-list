#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *link;
};

struct stack *top=NULL;
void push();
void pop();
void display();
void peak();
int length();
int main()
{
    int ch;
    while (1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.peak\n");
        printf("4.Display\n");
        printf("5.Length\n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peak();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("%d\n",length());
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }


    }
    
    return 0;
}

void push()
{
    struct stack *temp;
    temp = (struct stack*)malloc(sizeof(struct stack));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    temp->link=top;
    top = temp;
}

void pop()
{
    struct stack *temp;
    if (top == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        temp = top;
        printf("Deleted %d\n",temp->data);
        top = top->link;
        free(temp);
        
    }   
}


void peak()
{
    if (top == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("%d\n",top->data);
    }
}

void display()
{
    struct stack *temp = top;
    if (top == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->link;
        }
        
    }
    
}

int length()
{
    int count=0;
    struct stack *temp = top;
    if (top == NULL)
    {
        return count;
    }
    else
    {
        while (temp != NULL)
        {
            count++;
            temp = temp->link;
        }
        return count;
        
    }   
}