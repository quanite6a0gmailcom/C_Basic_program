#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    char phonenumber[20];
    char email[30];
}address;

int main(){
address sv[100],temp;
FILE *ptr;
int i=0;
char s[20];
ptr=fopen("new.txt","r");
while (fscanf(ptr,"%s %s %s",temp.name,temp.phonenumber,temp.email)!=EOF)
{
    sv[i]=temp;
    i++;
}
printf("NHap ten sinh vien muon tim kiem:");
fflush(stdin);
gets(s);
while(i>=0){
    if (strcmp(sv[i].name,s)==0) 
    printf("%s %s %s",sv[i].name,sv[i].email,sv[i].phonenumber);
    i--;
}
fclose(ptr);
return 0;


}