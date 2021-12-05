#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int top=-1;
int Isempty(){
    if (top==-1)
    return 1;
    else return 0;
}
int Isfull(int capacity){
    if (top>=capacity-1)
    return 1;
    else return 0;
}
void push(char stack[],char a[],int capacity){
   int i;
   if (Isfull(capacity)==1){
       printf("\nStack is over full!!!!\n");
   }else{
       for (i=0;i<strlen(a);i++){
           top++;
           stack[top]=a[i];
           
       } 
   }
}
char pop(char stack[],char t){
     if (Isempty()==1)
     printf("Stack is empty!!!\n");
     else{
         t=stack[top];
         top--;
         return t;
     }
}
int main(){
    int capacity;
    char stack[20];
    char a[20];
    
    char t;
    printf("Nhap do dai chuoi :");
    scanf("&d",&capacity);
    printf("\nNhap chuoi:");
    fflush(stdin);
    gets(a);
    printf("Chuoi dao nguoc:");
    puts(stack);
    return 0;

}