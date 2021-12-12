#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[30];
    char phonenumber[20];
}address;

struct lisk{
    address data;
    struct lisk *Next;
};
typedef struct lisk Node;
Node *createnewnode(address X){
    Node *temp;
    temp=(Node *)malloc(sizeof(struct lisk));
    temp->data=X;
    temp->Next=NULL;
    return temp;
}
Node *addhead(Node *head,address X){
     Node *newnode;
     newnode=createnewnode(X);
     if (head==NULL)
     head=newnode;
     else{
        newnode->Next=head;
     } 
     return newnode;
}
Node *deHead(Node *head){
    if (head=NULL)
    printf("Cha co gi de xoa het!!\n");
    else{
        Node *temp;
        temp=head;
        head=head->Next;
        free(temp);
    }
    return head;
}
void search(Node *head,char s[],FILE *ptr1){
     while(head!=NULL){
         if (strcmp(head->data.name,s)==0)
         fprintf(ptr1,"%s  %s",head->data.name,head->data.phonenumber);
         head=head->Next;
     }
}
int main(){
    Node *head=NULL;
    address X;
    char s[30];
    FILE *ptr,*ptr1;
    ptr=fopen("new.txt","r");
    ptr1=fopen("file1.txt","w");
    while(fscanf(ptr,"%s %s ",X.name,X.phonenumber)!=EOF){
       head=addhead(head,X);
    }
    printf("Nhap ten can tim kiem:");
    fflush(stdin);
    gets(s);
    search(head,s,ptr1);
    fclose(ptr);
    fclose(ptr1);
    return 0;

   
    
    
    
    
}