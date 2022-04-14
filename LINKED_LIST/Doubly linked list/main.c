#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start=NULL;

void Insert_beg()
{
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("   Enter the data in the node: ");
    scanf("%d",&new_node->data);

    if(start==NULL)
    {
        start = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        new_node->next = start;
        start->prev = new_node;
        start = new_node;
        new_node->prev = NULL;
    }
}
void Insert_end()
{
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("   Enter the data in the node: ");
    scanf("%d",&new_node->data);

    if(start==NULL)
    {
        start = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        struct node *temp;
        temp = start;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = NULL;

    }

}
void Display()
{
    printf("\n");
    struct node *temp;
    temp = start;
    if(start == NULL)
    {
        printf("   Doubly linked list is empty\n");
        return;
    }
    else
    {
        while(temp != NULL)
        {
            printf("   %d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
void Update()
{
    struct node *temp;
    int actual_data,update_data,f=0;
    temp = start;

    printf("   Enter the actual data which need to be updated : ");
    scanf("%d",&actual_data);
    printf("   Enter the updated data : ");
    scanf("%d",&update_data);

    while(temp != NULL)
    {
        if(temp->data == actual_data)
        {
            f=1;
            break;
        }
        temp = temp->next;
    }

    if(f==1)
    {
        while(temp->data != actual_data)
        {
            temp = temp->next;

        }

        temp->data = update_data;
    }
    else
    {
        printf("\n   Entered actual data is not present in the list\n");
        return;
    }

}
void Delete()
{
    struct node *temp;
    struct node *pretemp;
    struct node *posttemp;
    int number;

    printf("   Enter the number to be deleted from list : ");
    scanf("%d",&number);
    temp = start;
    while(temp->data != number)
    {
        pretemp = temp;
        temp = temp->next;
    }
    posttemp = temp->next;
    pretemp = temp->prev;

    if(temp == start)
    {
        if(temp->next == NULL && temp->prev == NULL)
        {
            start = NULL;
            free(temp);
            return;
        }
        else
        {
            posttemp->prev=NULL;
            start = posttemp;
            free(temp);
        }
    }
    else if(posttemp == NULL)
    {
        pretemp->next = NULL;
        free(temp);
    }

    else
    {
        pretemp->next = posttemp;
        posttemp->prev = pretemp;
        free(temp);
    }

}
void Insert_after()
{
    struct node * new_node;
    int element,f=0;
    struct node *temp,*posttemp;

    printf("   Enter the element after which you want to insert the data : ");
    scanf("%d",&element);

    temp = start;
    while(temp != NULL)
    {
        if(temp->data == element)
        {
            f=1;
        }
        temp = temp->next;
    }

    if(f==0)
    {
        printf("   The entered element is not present in the list\n");
        return;
    }
    else
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("   Enter the data you want to insert in list : ");
        scanf("%d",&new_node->data);
        temp = start;
        while(temp->data != element)
        {
            temp=temp->next;
        }
        posttemp = temp->next;

        if(posttemp == NULL)
        {
            temp->next = new_node;
            new_node->prev = temp;
            new_node->next = NULL;
        }
        else
        {
            temp->next = new_node;
            new_node->next = posttemp;
            new_node->prev = temp;
            posttemp->prev = new_node;
        }


    }


}
void Display_reverse()
{
    printf("\n");
    struct node *temp;
    temp = start;
    if(start == NULL)
    {
        printf("   DLL is empty\n");
        return;
    }
    else
    {

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        while(temp != NULL)
        {
            printf("   %d ",temp->data);
            temp = temp->prev;
        }

    }
    printf("\n");
}
void Reverse_DLL()
{
    if(start == NULL)
    {
      printf("   DLL is empty\n");
      return;
    }
    struct node *forward;
    struct node *backward;
    forward = start;
    backward = start;
    int l=0;

    while(backward->next != NULL)
    {
        l++;
        backward = backward->next;
    }

    l=(l+1)/2;

    while(l--)
    {
        int temp = forward->data;
        forward->data = backward->data;
        backward->data = temp;

        forward = forward->next;
        backward = backward->prev;

    }



}

int main()
{
    int choice;

    do
    {
        printf("\n 1.Insert_beg  2.Insert_end  3.Display  4.Update  5.Delete  6.Insert_after  7.Display_reverse  8.Reverse_DLL  9.Exit\n");
        printf("   Enter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                Insert_beg();
                break;
            case 2:
                Insert_end();
                break;
            case 3:
                Display();
                break;
            case 4:
                Update();
                break;
            case 5:
                Delete();
                break;
            case 6:
                Insert_after();
                break;
            case 7:
                Display_reverse();
                break;
            case 8:
                Reverse_DLL();
                break;
            case 9:
                printf("\nEXIT...............\n");
                break;

        }
    }while(choice!=9);

    return 0;
}
