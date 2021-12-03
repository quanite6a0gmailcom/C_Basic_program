#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include <malloc.h>
struct Node
{  
    int Element;
    struct Node *next;
};
typedef struct Node *position;
typedef struct {
    position front,rear;
}queue;
void makenullqueue(queue *pQ){
      position header;
      header=(position)malloc(sizeof(struct Node));
      header->next=NULL;
      pQ->front=header;
      pQ->rear=header; 
}
int isempty(queue Q){
    return Q.front==Q.rear;
}
int frontq(queue Q){
    return Q.front->next->Element;
}
void deQueue(queue *pQ){
    position T;
    T=pQ->front;
    pQ->front=T->next;
    free(T);
}
void enqueue(int X,queue *pQ){
    position T;
    T=(position)malloc(sizeof(struct Node));
    T->Element=X;
    T->next=NULL;
    pQ->rear->next=T;
    pQ->rear=T;
}
void readqueue(queue *pQ){
    int i,n;
    int X;
    printf("So phan tu cua hang:");
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        printf("Nhap phan tu thu %d:",i);
        scanf("%d",&X);
        enqueue(X,pQ);
    }
}
void printfqueue(queue Q){
    while(!isempty(Q)){
        printf("%d\n",frontq(Q));
        deQueue(&Q);
    }
}
int main(){
    queue Q;
    makenullqueue(&Q);
    readqueue(&Q);
    
    
    printfqueue(Q);
    return 0;
}