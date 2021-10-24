#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	char name[20];
	char tel[19];
	char email[20];
}address;
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
void push(address stack[],address value,int capacity){
	if (IsFull(capacity)==1)
	printf("\nStack is full.!!!!\n");
	else{
		++top;
		stack[top]=value;
	}
}
address pop(address value,address stack[]){
	if (IsEmpty()==1)
	printf("\nStack is Empty!!!!\n");
	else{
		value=stack[top];
		--top;
		return value;
	}
}


int main(){
	address stack[100];
	address sv1[100];
	FILE *ptr=fopen("add.txt","r");
	FILE *ptr1=fopen("po.txt","w+");
	int i=0;
	
	
    for (;;){
	fscanf(ptr,"%s %s %s",sv1[i].name,sv1[i].tel,sv1[i].email);
	push(stack,sv1[i],100);
	i++;
    if(feof(ptr)){
    	break;
	}

}
while(top>-1){
address node=pop(stack[top],stack);
fputs(node.name,ptr1);
fputs("   ",ptr1);
fputs(node.tel,ptr1);
fputs("   ",ptr1);
fputs(node.email,ptr1);
fputs("\n",ptr1);

}
	
	fclose(ptr);
	fclose(ptr1);
}
