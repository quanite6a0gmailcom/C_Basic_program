#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void swap(char *a,char *b){
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int findpivot(char a[],int i,int j){
    char firstkey;
    int k;
    k=i+1;
    firstkey = a[i];
    while(k<=j && a[k]==firstkey) k++;
    if (k>j) return -1;
    if (a[k] > firstkey) return k;
 return i;
}
int Partition(char a[],int i,int j,char pivot){
    int L,R;
    L=i;
    R=j;
    while(L<=R){
        while(a[L]<pivot) L++;
        while(a[R]>=pivot) R--;
        if (L<R) swap(&a[L],&a[R]);
    }
    return L;

}
void Quicksort(char a[],int i,int j){
     char pivot;
     int pivotindex,k;
     pivotindex=findpivot(a,i,j);
     if (pivotindex!=-1){
         pivot=a[pivotindex];
         k=Partition(a,i,j,pivot);
         Quicksort(a,i,k-1);
         Quicksort(a,k,j);
     }
}
void printdata(char a[],int n){
    int i;
    for(i=0;i<n;i++){
     printf("%c ",a[i]);
    }
}
int main(){
     char a1[100];
     printf("Nhap xau ki tu:\n");
     fflush(stdin);
     gets(a1);
     
     Quicksort(a1,0,strlen(a1)-1);
    printdata(a1,strlen(a1));
}