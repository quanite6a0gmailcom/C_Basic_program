#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct{
	char name[25];
	int old;
	float suggest[6];
	float ss;
}result;
void giaodien(){
	printf("\n****************************************************************\n");
	printf("**                  TRO CHOI DOAN SO                            **\n");
	printf("**                   1.Khoi dong                                **\n");
	printf("**                   2.Doan So                                  **\n");
	printf("**                   3.Tong hop ket qua                         **\n");
	printf("**                   4.Thoat tro choi                           **\n");
	printf("******************************************************************\n");
}

void nhaplieu(result total[],int n){
	int i;
	int j;
	
	for (i=0;i<n;i++){
		int S=0;
		printf("Nhap ten cua nguoi choi %d:",i+1);
		do{
		fflush(stdin);
		gets(total[i].name);
		for (j=0;j<strlen(total[i].name);j++){
			if (total[i].name[j]==' ')
			S++;
		}
		if (S==0) {
		printf("\nNhap lai ten !!!\n");
		continue;}
	}while (S==0);
	}
	printf("\nDanh Sach Nguoi Choi:\n");
	for (i=0;i<n;i++){
		printf("%d  \t  %s\n",i+1,total[i].name);
	}
}
int dodaimax(result total[],int n){
	int S=0;
	int i;
	for(i=0;i<n;i++){
		if (strlen(total[i].name)>S)
		S=strlen(total[i].name);
	}
	return S;
}
void doanso(result total[],int n,float m){
	int i;
	int j;
	for (i=0;i<n;i++){
		printf("Nhap cac su doan cua nguoi choi %s:",total[i].name);
		for (j=0;j<6;j++){
			printf ("\nNhap du doan lan %d:",j+1);
			scanf("%f",&total[i].suggest[j]);
			if (total[i].suggest[j]==m)
			break;
			else if (total[i].suggest[j]>m)
			printf("\nSo vua nhap lon hon so can tim\n");
			else printf("\nSo Vua nhap nhon hon so can tim\n");
		}
	}
	
		for(i=0;i<n;i++){
		int p;
		
		p=dodaimax(total,n)-strlen(total[i].name);
		printf("\n%s",total[i].name);
		for(j=0;j<p;j++){
			printf(" ");
		}
		for (j=0;j<6;j++){
			printf("      %0.1f ",total[i].suggest[j]);
	}
}
	}
void sailech(result total[],int n,float m){
	int i;
	int j;
	for (i=0;i<n;i++){
		int S=0;
		for (j=0;j<6;j++){
			if (total[i].suggest[j]==m)
			S++;
			if (S!=0) total[i].ss=0;
			else total[i].ss=fabs((total[i].suggest[5]/m)-1);
		}
	}
}
void sapxep(result total[],int n,float m){
	result temp;
	int i,j;
	for (i=1;i<n;i++)
	for(j=0;j<n-1;j++){
		if (total[j].ss>total[j+1].ss){
			temp=*(total+j);
			*(total+j)=*(total+j+1);
			*(total+j+1)=temp;
		}
	}
	
		for(i=0;i<n;i++){
		int p;
		
		p=dodaimax(total,n)-strlen(total[i].name);
		printf("\n%d\t%s",i+1,total[i].name);
		for(j=0;j<p;j++){
			printf(" ");
		}		
			printf("      %0.3f ",total[i].ss);
	
}
	
}
	
int main(){
	result total[100];
	int n;
	float m;
	int key;
	menu:
		giaodien();
		printf("Nhap su lua chon:");
		scanf("%d",&key);
		switch(key){
			case 1:
				printf("Ban da chon chuc nang 1:\n");
				printf("Nhap so nguoi choi:");
				do{
				scanf("%d",&n);
			}while(n<=0||n>5);
			printf("\nNhap so can doan:");
			do{
				scanf("%f",&m);
			}while(m<1||m>100);
				nhaplieu(total,n);
				goto menu;
			case 2:
				printf("Ban da chon chuc nang thu 2:\n");
				doanso(total,n,m);
				goto menu;
			case 3:
				printf("Ban da chon chuc nang 3:\n");
				sailech(total,n,m);
				sapxep(total,n,m);
				goto menu;
		}
}
