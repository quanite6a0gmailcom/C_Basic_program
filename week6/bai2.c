#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sequentinal_search(int *a,int count,int key){
  int i;
  for (i=0;i<count;i++)
      if (key==a[i]) return i;
    
  return 0;
}
int main(){
    int a[10];
    int i;
    int key;
    int index;
    for (i=0;i<11;i++){
        if (i==10) 
        {
            printf("\nNhap linh canh :");
            scanf("%d",&key);
        }else{
             printf("\nNhap phan tu thu %d cua mang:",i+1);
             scanf("%d",&a[i]);  
        }
    }
     index=sequentinal_search(a,10,key);
     printf("%d",index);


}