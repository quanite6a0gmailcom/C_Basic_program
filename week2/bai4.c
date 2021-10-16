#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[20];
    char phone_number[12];
	char email[50];	
}phoneaddress;

int main(){
	phoneaddress phonearr[100];
	int n,i,irc,inc;
	FILE *fb;
	printf("Nhap so tai khoan dien thoai can ghi:");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		printf("name:");
		fflush(stdin);
		gets(phonearr[i].name);
		printf("\nphone_number:");
		fflush(stdin);
		gets(phonearr[i].phone_number);
		printf("\nemail:");
		fflush(stdin);
		gets(phonearr[i].email);
	}
	fb=fopen("C:\\lab1w.txt","w+b");
	if (fb==NULL){
		printf("Can not open:\n\n ");
		exit(1);
	}
irc=	fwrite(phonearr,sizeof(phoneaddress),n,fb);
	inc=fread(phonearr,sizeof(phoneaddress),n,fb);
	printf("fread return code:%d\n",irc);
	for (i=0;i<n;i++){
		fflush(stdin);
		puts(phonearr[i].name);
		puts(phonearr[i].email);
		puts(phonearr[i].phone_number);
	}
	fclose(fb);
}
