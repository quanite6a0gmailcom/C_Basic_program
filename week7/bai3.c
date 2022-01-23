#include <stdio.h>
#include <time.h>
int Binary_Search(int a[],int X){
   int low,mid,high,dem=0;
   low=0;high=99;
   while(low<=high){
       mid=(low+high)/2;
       if (a[mid]<X){
       dem++;
       low=mid+1;
       }
       else if (a[mid]>X){
       dem++;
       high=mid-1;
       }
       else{
          dem++;
          return mid;
       }
   }
   return -1;

}
int recursive_BinarySearch(int a[],int X,int Low,int high){
    int mid;
    if (Low>high) return -1;
    mid=(Low+high)/2;
    if (a[mid]<X) return recursive_BinarySearch(a,X,mid+1,high);
    else if (a[mid]>X) return recursive_BinarySearch(a,X,Low,mid-1);
    else return mid;

    return -1;
}
int main(){
    int a[100];
    int i=0;
    time_t start,start1,end,end1;
    double time_use,time_use1;
    for (i=0;i<100;i++)
    a[i]=i;
    start=clock();
    if(recursive_BinarySearch(a,12,0,99)!=-1){
        printf("Tim thay %d tai vi tri %d!!\n",a[recursive_BinarySearch(a,12,0,99)],recursive_BinarySearch(a,12,0,99));
    }
    else {
        printf("Khong tim thay!!!\n");
    }
    end=clock();
    time_use=(double)(end-start)/CLOCKS_PER_SEC;
    start1=clock();
    if(Binary_Search(a,12)!=-1){
        printf("Tim thay %d tai vi tri %d!!\n",a[Binary_Search(a,12)],Binary_Search(a,12));
    }
    else {
        printf("Khong tim thay!!!\n");
    }
    end1=clock();
    time_use1=(double)(end1-start1)/CLOCKS_PER_SEC;
    printf("THoi gian chay vs de quy la:%f",time_use);
    printf("\nTHoi gian chay khong de quy la:%f",time_use1);
    return 0;


}