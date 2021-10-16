#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	int i,n,S=0;
	int *a;
	printf("Nhap so phan tu cua day so ");
	scanf("%d",&n);
	a=(int *)malloc((n+1)*sizeof(int));
	if (a==NULL){
		printf("Co loi ko the cap phat bo nho duoc!!!\n");
		exit(0);
	}
	for (i=0;i<n+1;i++){
		if (i==0) *(a+i)=n; else{
		
		printf("Nhap phan tu thu %d:",i+1);
		scanf("%d",a+i);
	}
	}
	fp=fopen("C:\\out.txt","w");
	if (fp==NULL){
		printf("Can not open file!!!\n");
		exit(0);
	}
	for (i=1;i<n+1;i++){
		S+=*(a+i);
	}
	for (i=n;i>=0;i--){
		if (i==0) fprintf(fp,"%d ",S);
		else fprintf(fp,"%d ",*(a+i));
	}
	fclose(fp);
	free(a);
}
