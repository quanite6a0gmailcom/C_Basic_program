#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxlength 100
typedef struct Address{
    char name[20];
    char phonenumber[12];
    char email[25];
}Diachi;
typedef struct {
    Diachi SV[maxlength];
    int top_idx;
}Stack;
void makenullstack(Stack *pQ){
    pQ->top_idx=-1;
}
int emptyStack(Stack S){
    return S.top_idx==-1;
}
int fullStack(Stack S){
    return S.top_idx==maxlength;
}
void push(Diachi X,Stack *pS){
    if (fullStack(*pS))
    printf("Nhan xep day\n");
    else 
    pS->SV[++pS->top_idx]=X;
}
void pop(Stack *pS){
    if (emptyStack(*pS))
      printf("Ngan Xep Rong \n");
      else 
      pS->top_idx--;
}
Diachi top(Stack S){
    if (emptyStack(S))
    printf("Ngan xep rong\n");
    else return S.SV[S.top_idx];
}
void readStack(Stack *S){
    int n,i;
    Diachi X;
    printf("Cho biet so luong sinh vien can nhap vao :");
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        printf("Nhap thong tin sinh vien thu :  %d\n:",i);
        printf("Nhap ten:");
        fflush(stdin);
        gets(X.name);
        printf("\nNhap so dien thoai:");
        fflush(stdin);
        gets(X.phonenumber);
        printf("\nNhap dia chi email:");
        fflush(stdin);
        gets(X.email);
        push(X,S);
    }
}
void printstack(Stack S){
    printf("Thong tin cua cac sinh vien:\n");
    while(!emptyStack(S)){
        printf("\n----------------\n");
        printf("%s",top(S).name);
         printf("\n%s",top(S).phonenumber);
          printf("\n%s",top(S).email);
        pop(&S);
    }
}
int main(){
      FILE *ptr,*ptr1;
       Stack S;
       Diachi Add;
       ptr=fopen("newfile.txt","r");
       ptr1=fopen("newfile1.txt","w+");
       makenullstack(&S);
       while(fscanf(ptr,"%s %s %s",Add.name,Add.phonenumber,Add.email)!=EOF){
           push(Add,&S);
       }
    while(!emptyStack(S)){
        printf("\n----------------\n");
        fprintf(ptr1,"%s %s %s\n",top(S).name,top(S).phonenumber,top(S).email);
        pop(&S);
    }
    fclose(ptr);
    fclose(ptr1);
       return 0;
}



