#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *top=NULL;
void push()
{
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("   The data to be entered in node : ");
    scanf("%d",&new_node->data);

    if(top==NULL)
    {
        top = new_node;
        new_node->next = NULL;
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }

}
void pop()
{
    if(top == NULL)
    {
        printf("   Stack is Empty\n");
        return;
    }
    struct node *temp;
    temp =top;
    printf("   [%d] is poped out from stack \n",temp->data);
    top = temp->next;
    free(temp);

}
void display()
{
    if(top == NULL)
    {
        printf("   Stack is Empty\n");
        return;
    }
    struct node *temp;
    temp =top;
    while(temp != NULL)
    {
        printf(" %d ",temp->data);
        temp = temp->next;
    }
}


int main()
{
    int choice;
    do
    {
        printf("\n 1.push  2.Pop  3.Display  4.Exit \n");
        printf("   Enter the choice : ");
        scanf("%d",&choice);

        switch(choice)
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
            printf("\nExiting from the program.... :) \n");
            break;
        }
    }while(choice != 4);
    return 0;
}
