#include <stdio.h>
#include <stdlib.h>

int v,e;
int a[100][100];
int visited[100];

int stack[5];
int top = -1;

void push(int element){
    if(top==4){
        printf("Stack overflow\n");
        return ;
    }
    top++;
    stack[top] = element;
}

int pop(){
    if(top==-1){
        printf("Stack underflow");
        return -1;
    }
    return stack[top--];
}

void display_stack(){
    for(int i=0;i<=top;i++){
        printf("%d\n",stack[i]);
    }

}

void DFS(){

    push(0);

    do{
        int element = pop();
        printf("%d ",element);

        for(int i=0;i<v;i++){
            if(a[element][i] == 1 && visited[i] == 0){
                push(i);
                visited[i] = 1;
            }
        }
    }while(top != -1);

}

int main()
{

    printf("Enter how many vertices : ");
    scanf("%d",&v);

    printf("Enter how many edges are there : ");
    scanf("%d",&e);

    for(int i=0;i<e;i++){
        int x,y;
        printf("Enter %d edge from and to  : ",i+1);
        scanf("%d%d",&x,&y);
        a[x][y] = 1;
        // a[y][x] = 1; // undirected
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("DFS of the graph is : ");
    DFS();

    return 0;

}
 /*
 Enter how many vertices : 5
Enter how many edges are there : 7
Enter 1 edge from and to  : 0 1
Enter 2 edge from and to  : 0 4
Enter 3 edge from and to  : 1 3
Enter 4 edge from and to  : 1 4
Enter 5 edge from and to  : 4 3
Enter 6 edge from and to  : 3 2
Enter 7 edge from and to  : 2 1
0 1 0 0 1
0 0 0 1 1
0 1 0 0 0
0 0 1 0 0
0 0 0 1 0
DFS of the graph is : 0 4 3 2 1
Process returned 0 (0x0)   execution time : 82.586 s
Press any key to continue.
*/
