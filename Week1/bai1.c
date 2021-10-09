#include <stdio.h>
#define size 50
int sosanh(int a[],int b[],int n1,int n2){
	int i;
	int S=0;
		for (i=0;i<n1;i++){
			if (a[i]!=b[i])
			S++;
		}
		if (S==0) return 1 ;else return 0; 
}
void nhap(int a[],int b[],int n1){
	int i;
	for (i=0;i<n1;i++){
		printf("Nhap phan tu thu %d lan luot cua mang a va mang b:",i+1);
		scanf("%d %d",&a[i],&b[i]);
	}
}
int main(){
	int a[size],b[size];
	int n1,n2;
	printf("Nhap so phan tu lan luot cua mang a va mang b:");
	scanf("%d %d",&n1,&n2);
	if (n1!=n2) printf("Hai mang ko bang nhau");
	else{
	nhap(a,b,n1);
	if (sosanh(a,b,n1,n2)==0) printf("Hai mang ko bang nhau") ;
	else printf("Hai mang bang nhau");
	return 0;
}
}
