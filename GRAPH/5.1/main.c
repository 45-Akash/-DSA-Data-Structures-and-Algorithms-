#include <stdio.h>
 #include <stdlib.h>
 #define MAX 100

int n, adj[MAX][MAX];
void create();
void display();
void ins(int, int);
void del(int, int);
int main()
{
      int ch, org, dest;
      create();
      while(1)
      {
            printf("\n1.Insert Edge \n2.Delete Edge \n3.Display\n4.Exit\nEnter your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                  case 1:     printf("\nEnter the edge to be inserted: ");
                                    scanf("%d %d",&org,&dest);
                                    ins(org,dest);
                                    break;
                  case 2:     printf("\nEnter the edge to be deleted: ");
                                    scanf("%d %d",&org,&dest);
                                    del(org,dest);
                                    break;
                  case 3:     display();
                                    break;
                  case 4:     exit(1);
                  default:    printf("\nInvalid choice");
            }
      }
      return 0;
 }
void create()
{
      int i,org,dest;
      printf("Enter no. of vertices: ");
      scanf("%d",&n);
      for(i=1;i<=n*(n-1);i++)
      {
            printf("Enter Edge %d: ",i);
            scanf("%d %d",&org,&dest);
            if(org==-1 && dest==-1)
                  break;
            if(org<=0 || dest<=0 || org>n || dest>n)
            {
                  printf("Invalid Edge\n");
                  i--;
            }
            else
                  adj[org][dest]=1;
      }
 }
void ins(int org, int dest)
 {
      if(org<=0 || org>n)
      {
            printf("Invalid origin\n");
            return;
      }
      if(dest<=0 || dest>n)
      {
            printf("Invalid destination\n");
            return;
      }
      adj[org][dest]=1;
      printf("Edge inserted.\n");
}
void del(int org, int dest)
{
      if(org<=0 || org>n || dest<=0 || dest>n || adj[org][dest]==0)
      {
            printf("Edge does not exist.\n");
            return;
      }
      adj[org][dest]=0;
      printf("Edge deleted.\n");
 }
void display()
{
      int i,j;
      for(i=1;i<=n;i++)
      {
            for(j=1;j<=n;j++)
            {
                  printf("%d ",adj[i][j]);
            }
            printf("\n");
      }
}
