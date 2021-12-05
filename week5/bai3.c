#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define maxlength 100
typedef struct {
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
    return (Q.rear-Q.front+1)%maxlength==0;
}
int front(queue Q){
    return Q.element[Q.front];
}
void dequeue(queue *pQ){
    if (pQ->front==pQ->rear)
    makenullqueue(pQ);
    else 
    pQ->front=(pQ->front+1)%maxlength;
}
void enqueue(int X,queue *pQ){
    if (fullqueue(*pQ)) printf("hang day!!!\n");
    else{
        if (emptyqueue(*pQ)) pQ->front=0;
        pQ->rear=(pQ->rear+1) %maxlength;
        pQ->element[pQ->rear]=X;
    }
}
void readqueue(queue *pQ){
    int n,i;
    int X;
    printf("Nhap so phan tu cua hang doi:");
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        printf("Nhap phan tu thu %d:",i);
        scanf("%d",&X);
        enqueue(X,pQ);
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