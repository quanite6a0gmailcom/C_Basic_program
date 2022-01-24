#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[20];
}person;

int main(){
    person nameList[26];
    int i=0,n;
    char name[20];
    FILE *ptr;
    ptr=fopen("input.txt","r");
    while(fscanf(ptr,"%s",name)!=EOF){
        strcpy(nameList[i].name,name);
        i++;
    }
    n=i;
    for (i=0;i<n;i++){
        printf("%s\n",nameList[i].name);
    }
    fclose(ptr);
}