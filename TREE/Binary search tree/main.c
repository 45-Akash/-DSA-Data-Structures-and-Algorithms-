#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

void insert(struct node *root, struct node *new_node);
void preorder(struct node *root);
void inorder(struct node *root,int);
void postorder(struct node *root);
struct node *find_min(struct node* root);
struct node *find_max(struct node* root);
struct node *Delete(struct node *root, int data);
int a[50]={};

void insert(struct node *root, struct node *new_node)
{
     if(new_node->data < root->data)
    {
        if(root->lchild == NULL)
        {
            root->lchild = new_node;
            return ;
        }
        else
        {
            insert(root->lchild,new_node);
        }
    }
    else
    {
        if(root->rchild == NULL)
        {
            root->rchild = new_node;
            return;
        }
        else
        {
            insert(root->rchild,new_node);
        }

    }

}
void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d\t",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }

}
void inorder(struct node *root,int index)
{

     if(root==NULL)
    {
        return;
    }

        inorder(root->lchild,index);
        printf("%d\t",root->data);
        inorder(root->rchild,index);

   return;

}
void postorder(struct node *root)
{
     if(root != NULL)
    {

        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d\t",root->data);
    }

}
struct node *find_min(struct node* root)
{

    while(root->lchild != NULL)
    {
        root = root->lchild;
    }

    return root;

}
struct node *find_max(struct node* root)
{
    while(root->rchild != NULL)
    {
        root = root->rchild;
    }

    return root;

}
struct node *Delete(struct node *root, int data)
{
    struct node*temp;
    if(root == NULL)
    {
        return root;
    }
    else if(data < root->data)
    {
        root->lchild = Delete(root->lchild,data);
    }
    else if(data > root->data)
    {
        root->rchild = Delete(root->rchild,data);
    }
    else
    {
        if(root->lchild==NULL && root->rchild == NULL)
        {
            free(root);
            root=NULL;
            return root;
        }
        else if(root->rchild ==NULL)
        {
            temp=root;
            root=root->lchild;
            free(temp);
            return root;
        }
        else if(root->lchild ==NULL)
        {
            temp=root;
            root=root->rchild;
            free(temp);
            return root;
        }
        else
        {
            temp = find_min(root->rchild);
            root->data = temp->data;
            root->rchild = Delete(root->rchild,temp->data);
        }
    }

    return root;
}

int count_nodes(struct node* root)
{
    int count =0;
    if(root != NULL)
    {

       count++;
       count += count_nodes(root->lchild);
       count += count_nodes(root->rchild);

    }

     return count;

}

int leaf_nodes(struct node* root)
{


    if(root==NULL)
    {
        return 0;
    }
    if(root->lchild==NULL && root->rchild==NULL)
    {
        return 1;
    }
    else
    {
        return leaf_nodes(root->rchild)+leaf_nodes(root->lchild);
    }


}

int internal_nodes(struct node* root)
{

   return count_nodes(root) - leaf_nodes(root);

}

int IS_BST(struct node* root)
{

    if(root==NULL)
    {
        return 1;
    }
    if(root->lchild!=NULL && root->lchild->data > root->data)
    {
        return 0;
    }
    if(root->rchild!=NULL && root->rchild->data < root->data)
    {
        return 0;
    }
    if(!IS_BST(root->lchild) || !IS_BST(root->rchild))
    {
        return 0;
    }
    return 1;

}
void mirror(struct node*root)
{
      if(root != NULL)
    {

        mirror(root->lchild);
        mirror(root->rchild);
        struct node * temp = root->rchild;
        root->rchild = root->lchild;
        root->lchild= temp;

    }

}
int height(struct node *root)
{
 int h = 0;
  if(root != NULL)
  {
    int lHeight = height(root->lchild);
    int rHeight = height(root->rchild);
    int maxHeight;
    if(lHeight > rHeight)
    {
        maxHeight = lHeight;
    }
    else
    {
        maxHeight = rHeight;
    }
    h = maxHeight + 1;
  }
  return h;

}



int main()
{
    struct node* root = NULL;
    struct node* new_node;
    struct node *temp;
    int del_element;
    static int count=0;
    int choice;
    do
    {
        printf("\n\n1:INSERT  2:PREORDER  3:INORDER  4:POSTORDER  5:FIND_MIN  6:FIND_MAX  7:DELETE  \n8:COUNT_NODES  9LEAF_NODES  10INTERNAL_NODES  11:IS_BST  12:MIRROR  13:HEIGHT  14:EXIT ");
        printf("\n   Enter the choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

                new_node=(struct node* )malloc(sizeof(struct node));
                printf("   Enter the data to be inserted :");
                scanf("%d",&new_node->data);

                new_node->lchild = NULL;
                new_node->rchild = NULL;

                if(root == NULL)
                {
                    root = new_node;
                }
                else
                {
                    insert(root,new_node);
                }
                break;

            case 2:
                preorder(root);
                break;

            case 3:
                inorder(root,0);
                break;

            case 4:
                postorder(root);
                break;

            case 5:

                temp = find_min(root);
                printf("\tThe minimum element present in tree is :%d\n",temp->data);
                break;

            case 6:

                temp = find_max(root);
                printf("\tThe maximum element present in tree is :%d\n",temp->data);
                break;

            case 7:

                printf("   Enter the data u want to delete :");
                scanf("%d",&del_element);
                root = Delete(root,del_element);
                break;

            case 8:
                count=0;
                if(root==NULL)
                {
                    printf("   Number of nodes is : 0\n");
                }
                else
                {
                  count=count_nodes(root);
                  printf("   The number of node are :%d",count);
                }
                break;

            case 9:
                  count=leaf_nodes(root);
                  printf("   The number of leaf nodes are :%d\n",count);
                  break;

            case 10:
                  count=internal_nodes(root);
                  printf("   The number of internal nodes are :%d\n",count);
                  break;
            case 11:
                  if(IS_BST(root))
                  {
                      printf("The given tree is BST\n");
                  }
                  else
                  {
                      printf("The given tree is not a BST\n");
                  }
                  break;
            case 12:
                 mirror(root);
                 printf("   Mirroring is done...\n");
                 break;
            case 13:
                printf("   The height of given tree is : %d\n",height(root));
                break;

            case 14:
                printf("\nEXIT...........!\n");
                break;

        }
    }while(choice != 14);

    return 0;
}
