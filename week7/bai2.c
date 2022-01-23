#include <stdio.h>
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
int main(){
    int a[100];
    int i=0;
    for (i=0;i<100;i++)
    a[i]=i;
    if(Binary_Search(a,12)!=-1){
        printf("Tim thay %d tai vi tri %d!!\n",a[Binary_Search(a,12)],Binary_Search(a,12));
    }
    else {
        printf("Khong tim thay!!!\n");
    }


}