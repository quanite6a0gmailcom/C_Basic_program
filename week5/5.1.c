#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxlength 100

typedef struct {
      char name[23];
      char phonenumber[13];
      char email[30];
}address;
typedef struct queue{
      address SV[maxlength];
      int front,rear;
}queue;
void makenullqueue(queue *pQ){
    pQ->front=-1;
    pQ->rear=-1;
}
int emptyqueue(queue Q){
    return Q.front==-1;
}
int isfullqueue(queue Q){
    return Q.rear-Q.front+1==maxlength;
}
address front1(queue Q){
    if (!emptyqueue(Q))
    return (Q.SV[Q.front]);
    else printf("Hang rong\n");
}
void dequeue(queue *pQ){
    if (emptyqueue(*pQ))
    printf("Hang rong\n");
    else if(pQ->front==pQ->rear)
    makenullqueue(pQ);
    else pQ->front++;
}
void enqueue(queue *pQ,address X){
    if (!isfullqueue(*pQ)){
        if (emptyqueue(*pQ)) pQ->front=0;
        if (pQ->rear==maxlength-1)
        {
            int i;
            for(i=pQ->front;i<pQ->rear;i++)
              pQ->SV[i-pQ->front]=pQ->SV[i];
              pQ->rear=pQ->rear-pQ->front;
              pQ->front=0;
        }
        pQ->rear++;
        pQ->SV[pQ->rear]=X;
    }else
    printf("\nHang day!!\n");
}
void printQueue(queue Q){
    address Z;
    printf("cac sinh vien trong tep:");
    while(!emptyqueue(Q)){
        Z=front1(Q);
        printf("%s\n",Z.name);
        dequeue(&Q);
    }
}

int main(){
    FILE *ptr,*ptr1;
    queue Q;
    address temp;
    makenullqueue(&Q);
    ptr=fopen("newfile.txt","r");
    ptr1=fopen("test.txt","w");
    while(fscanf(ptr,"%s %s %s",temp.name,temp.phonenumber,temp.email)!=EOF){
           enqueue(&Q,temp);
    }
   while (!emptyqueue(Q))
   {
       temp=front1(Q);
       fprintf(ptr1,"%s %s %s\n",temp.name,temp.phonenumber,temp.email);
       dequeue(&Q);
   }
   
   fclose(ptr);
   fclose(ptr1);
   return 0;
    
        
}