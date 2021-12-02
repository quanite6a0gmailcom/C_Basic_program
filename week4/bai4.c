#include <stdio.h>
#include <stdlib.h>

typedef struct _StackNode{
    int temp;
    struct _StackNode *next;
}StackNode;
typedef struct _Stack{
    StackNode *top;
}Stack;
Stack *createstack(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    
}