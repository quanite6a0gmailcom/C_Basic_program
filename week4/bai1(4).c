#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int top=-1;
int IsFull(int capacity){
	if (top>=capacity-1)
	return 1;
	else return 0;
	
}

int IsEmpty(){
	if (top==-1)
	return 1;
	else return 0;
	
}
void push(char stack[],char value,int capacity){
	if (IsFull(capacity)==1)
	printf("\nStack is full.!!!!\n");
	else{
		++top;
		stack[top]=value;
	}
}
int pop(char value,char stack[]){
	if (IsEmpty()==1)
	printf("\nStack is Empty!!!!\n");
	else{
		value=stack[top];
		--top;
		return value;
	}
}
int top1(char stack[]){
	return stack[top];
}
int size(int top){
	return top+1;
}
int main(){
	int capacity;
	char stack[capacity];
	char s;
	int i=0;
	printf("Nhap do dai chuoi:");
	scanf("%d",&capacity);
	for (i=0;i<capacity;i++){
    printf("Nhap:");
    fflush(stdin);
    scanf("%c",&s);
    push(stack,s,capacity); 
}
	while(top>-1){
	printf("%c",pop(stack[top],stack));
}
	
}
