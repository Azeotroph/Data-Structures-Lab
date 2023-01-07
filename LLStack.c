#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE *link;
};

typedef struct NODE Node;
Node *top, *new;

void push()
{
    if (top == NULL)
    {
        top = (Node *)malloc(sizeof(Node));
        printf("enter the element\n");
        scanf("%d", &top->data);
        top->link=NULL;
        return;
    }
    else
    {
        new = (Node *)malloc(sizeof(Node));
        new->link = top;
        top = new;
        printf("enter the element\n");
        scanf("%d", &new->data);
        return;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    else
    {
        Node *temp = top;
        printf("deleted: %d\n", top->data);
        top = top->link;
        free(temp);
    }
}

void display()
{
    if (top == NULL)
    {
        printf("stack underflow\n");
        return;
    }
    else
    {
        Node *temp;
        temp = top;
        do
        {
            printf("%d\n", temp->data);
            temp = temp->link;
        } while (temp != NULL);
    }
}

int main(){
    int choice;
    do{
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("enter a valid chocie\n");
            break;
        }
    }while(choice!=4);
    return 0;
}
