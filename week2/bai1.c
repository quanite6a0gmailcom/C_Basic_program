#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	char *ptr1,*ptr2,*ptr;
	int n1,n2;
	printf("Nhap kich co cua xau 1:");
	scanf("%d",&n1);
	printf("\nNhap kich co cua xau :");
	scanf("%d",&n2);
	ptr1=(char *)malloc(n1*sizeof(char));
	ptr2=(char *)malloc(n2*sizeof(char));
	if (ptr1==NULL||ptr2==NULL){
			printf("Co loi khong the cap phat bo nho duoc!!!");
		exit(0);
	}
	ptr=(char *)malloc((n1+n2)*sizeof(char));
	printf("\nNhap chuoi thu nhat:");
	fflush(stdin);
	gets(ptr1);
	printf("\nNhap chuoi thu 2:");
	fflush(stdin);
	gets(ptr2);
	strcpy(ptr,ptr1);
	strcat(ptr,ptr2);
	printf("\nChuoi ghep la:");
	fflush(stdin);
	puts(ptr);
	free(ptr1);
	free(ptr2);
	free(ptr);
	
	
	
}
