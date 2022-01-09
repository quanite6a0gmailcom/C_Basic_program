#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getrandom(int min,int max){
    return min +(int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void InserttionSort(int a[],int n){
    int i,j;
    for(i=1;i<n;i++){
        j=i;
        while((j>0)&&(a[j]<a[j-1])){
            swap(&a[j],&a[j-1]);
            j--;
        }
    }
}
int findpivot(int a[],int i,int j){
    int firstkey;
    int k;
    k=i+1;
    firstkey = a[i];
    while(k<=j && a[k]==firstkey) k++;
    if (k>j) return -1;
    if (a[k] > firstkey) return k;
 return i;
}
int Partition(int a[],int i,int j,int pivot){
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
void Quicksort(int a[],int i,int j){
     int pivot;
     int pivotindex,k;
     pivotindex=findpivot(a,i,j);
     if (pivotindex!=-1){
         pivot=a[pivotindex];
         k=Partition(a,i,j,pivot);
         Quicksort(a,i,k-1);
         Quicksort(a,k,j);
     }
}
void printdata(int a[],int n){
    int i;
    for(i=0;i<n;i++){
     printf("%d ",a[i]);
    }
}
int main(){
    int n,i;
    int a[500],a1[500];
    time_t start,start1,end,end1;
    double time_use,time_use1;
    printf("Nhap so phan tu cua mang:");
    scanf("%d",&n);
    printf("\n");
     for (i=0;i<n;i++){
        a[i]=getrandom(1,n);
    }
    for (i=0;i<n;i++){
        a1[i]=getrandom(1,n);
    }
    start=clock();
    InserttionSort(a,n);
    printdata(a,n);
    end=clock();
    time_use=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n");
    start1=clock();
    Quicksort(a1,0,n-1);
    printdata(a1,n);
    end1=clock();
    time_use1=(double)(end1-start1)/CLOCKS_PER_SEC;
  //if (time_use1<time_use) printf("Thuat toan hieu qua hon vs QuickSort");
  //else printf("Thuat toan hieu hon vs insertsort");
    printf("THoi gian chay vs insertsort la:%f",time_use);
    printf("\nTHoi gian chay vs quicksort la:%f",time_use1);
    return 0;
}
