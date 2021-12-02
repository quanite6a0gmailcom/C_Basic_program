#include <stdio.h>
#include <stdlib.h>

typedef struct _StackNode{
    int item;
    struct _StackNode *next;
}StackNode;
typedef struct _Stack{
    StackNode *top;
}Stack;
Stack *createstack(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    if(s==NULL) {
        printf("Error in memory allocation\n");
        exit(0);
    }
    s->top=NULL;
    return s;
}
int isEmpty(Stack *s){
    if(s==NULL) return 1;
    if(s->top==NULL) return 1;
    else return 0;
}
void push(Stack *s,int X){
    if (s==NULL) return;
    StackNode *newnode=(StackNode*)malloc(sizeof(StackNode));
    if(newnode==NULL) {
        printf("Error in memory allocation\n");
        exit(0);
    }
    newnode->item=X;
    newnode->next=NULL;
    newnode->next=s->top;
    s->top=newnode;
}
int pop(Stack *s){
    if (s==NULL) return -20000000;
    if(isEmpty(s)) return -2000000;
    int X=s->top->item;
    StackNode *tg=s->top;
    s->top=s->top->next;
    free(tg);
    return X;
}
void StackDestroy(Stack *s){
    while (!isEmpty(s))
    {
        pop(s);
    }
    free(s);
    
}
void chuyen_co_so(Stack *s,int a,int b){
    int X;
    while (a!=0)
    {
        X=a%b;
        push(s,X);
        a=a/b;
    }
    while(!isEmpty(s))
    printf("%d\n",pop(s));
    
}
int main(){
    Stack *s=NULL;
    s=createstack();
    push(s,5);
    push(s,2);
    push(s,7);
    while(!isEmpty(s))
    printf("%d\n",pop(s));
    
    chuyen_co_so(s,100,2);
    StackDestroy(s);
    return 0;
}