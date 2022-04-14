#include <stdio.h>
#include <stdlib.h>

#define size 5

int queue[size];
int front = -1;
int rear = -1;

void enqueue(int n){

    if(front == -1 && rear == -1){
        front++;
        rear++;
        queue[rear] = n;
    }else{
        if(rear>=4){
            printf("Queue Overflow\n");
            return ;
        }
        rear++;
        queue[rear] = n;
    }
}

int dequeue(){
    int result;
    if(front==-1 && rear == -1){
        printf("Queue Underflow\n");
        return -1;
    }
    else{
        if(front == rear){
            result = queue[rear];
            rear = -1;
            front = -1;

        }
        else {
            result = queue[front++];
        }
    }
    return result;
}

void display_queue(){
    if(front==-1 && rear == -1){
        return ;
    }
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }printf("\n");
}

int v,e;
int a[100][100];
int visited[100];

void BFS(){

    enqueue(0);

    do{
        int element = dequeue();
        printf("%d ",element);
        for(int i=0;i<v;i++){
            if(a[element][i] == 1 && visited[i] == 0){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }while(front != -1);

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

    printf("BFS of Graph is : ");
    BFS();

    return 0;

}
/*
Enter how many vertices : 3
Enter how many edges are there : 3
Enter 1 edge from and to  : 0 1
Enter 2 edge from and to  : 1 2
Enter 3 edge from and to  : 0 2
0 1 1
0 0 1
0 0 0
BFS of Graph is : 0 1 2
Process returned 0 (0x0)   execution time : 38.006 s
Press any key to continue.
*/
