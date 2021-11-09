#include <stdio.h>
#include <stdlib.h>
int binary_search(int a[],int X,int N){
int low,mid,high,dem;
low=0;high=N-1;
dem=0;
while(low<=high){
mid = (low+high)/2;
dem++;
if (a[mid]<X){
    
    low=mid+1;
}
else if(a[mid]>X){
    
    high=mid-1;
}
else {
    
    return dem;
}
}

}
int main(){
  int a[100];
  int X,i;
  int index;
  for ( i=0;i<100;i++){
      a[i]=i+1;
  }
  printf("%d",binary_search(a,50,100));


}