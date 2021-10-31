#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
char pop(char stack[]){
	char value;
	if (IsEmpty()==1)
	printf("\nStack is empty!!!!!\n");
	else {
		value=stack[top];
		top--;
		return value;
	}
	
}
void infix(char stack[],char str[],char a[],int capacity){
	int i;
	int k;
	int j=0;
	for (i=0;i<strlen(str);i++){
		
		if (str[i]>='0'&&str[i]<='9'){
		    a[j]=str[i];
		    j++;
		}
		if (str[i]=='*'||str[i]=='/'){
				if (stack[top]=='*'||stack[top]=='/'){
				a[j]=pop(stack);
				j++;
					push(stack,str[i],capacity);
			}else
				push(stack,str[i],capacity);
		}
		
		if (str[i]=='+'||str[i]=='-'){
			if (stack[top]=='*'||stack[top]=='/'){
				a[j]=pop(stack);
				j++;
					push(stack,str[i],capacity);
			}else
				push(stack,str[i],capacity);
		}
		if (str[i]=='('){
				push(stack,str[i],capacity);
		}
		if (str[i]==')'){
			while(stack[top]!='('){
				a[j]=pop(stack);
				j++;
			}
			if(stack[top]=='(')
			pop(stack);
		}
		
		
		for(k=top;k>-1;k--){
			if (i==strlen(str)-1) 
			{
				a[j]=stack[k];
				j++;
			}
			
		}
		
	}
}
		

		
	
int main(){
	int capacity;
   char stack[capacity];
   char str[capacity];
   char a[50];
   int i;
   printf("Nhap so phan tu ngan xep: ");
   scanf("%d",&capacity);
   printf("Nhap bieu thuc toan hoc o dang trung to:");
   fflush(stdin);
   gets(str);
   infix(stack,str,a,capacity);
   fflush(stdin);
   printf("\nMa hau to la :");
   for(i=0;i<strlen(a);i++)
   printf("%c ",a[i]);
   
	
	
}
