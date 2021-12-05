#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxlength 100
typedef struct queue{
    int element[maxlength];
    int front,rear;
}queue;
void makenullqueue(queue *pQ){
    pQ->front=-1;
    pQ->rear=-1;
}
int emptyqueue(queue Q){
    return Q.front==-1;
}
int fullqueue(queue Q){
    return Q.rear-Q.front+1==maxlength;
}
int front(queue Q){
    if (!emptyqueue(Q))
    return (Q.element[Q.front]);
    else printf("Hang rong\n");
}
void dequeue(queue *pQ){
    if (emptyqueue(*pQ))
    printf("\nHang rong\n");
    else if (pQ->front==pQ->rear)
    makenullqueue(pQ);
    else pQ->front++;
}
void enqueue(queue *pQ,int X){
    if (!fullqueue(*pQ)){
         if (emptyqueue(*pQ)) pQ->front=0;
         if(pQ->rear==maxlength-1){
             int i;
             for (i=pQ->front;i<=pQ->rear;i++)
             pQ->element[i-pQ->front]=pQ->element[i];
             pQ->rear=pQ->rear-pQ->front;
             pQ->front=0;
         } 
         pQ->rear++;
         pQ->element[pQ->rear]=X;
    }else
    printf("\nHang day\n");
    
}
void readqueue(queue *pQ){
    int n,i;
    int X;
    printf("Nhap so phan tu cua hang doi:");
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        printf("Nhap phan tu thu %d:",i);
        scanf("%d",&X);
        enqueue(pQ,X);
    }
}
void printqueue(queue Q){
    printf("cac phan tu trong hang:");
    while(!emptyqueue(Q)){
        printf("%d\n",front(Q));
        dequeue(&Q);
    }
}
int main(){
    queue Q;
    makenullqueue(&Q);
    readqueue(&Q);
    printqueue(Q);
    return 0;
}


