#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char name[20];
	char tel[11];
	char email[25];
}phoneaddress;

int main(){
	FILE *fb;
	phoneaddress *phonearr;
	int i,n,irc;
	printf("read from 2sd data to 3rd data :\n");
	fb=fopen("C:\\lab1w.txt","r+b");
	if (fb==NULL){
		printf("Can not open!!!!!!");
		exit(1);
	}
	phonearr=(phoneaddress *)malloc(2*sizeof(phoneaddress));
	if (phonearr==NULL){
		printf("Memory allocation failed:\n");
		exit(1);
	}
	if (fseek(fb,1*sizeof(phoneaddress),SEEK_SET)!=0)
	{
		printf("Fseek failed!\n");
		exit(1);
	}
	irc=fread(phonearr,sizeof(phoneaddress),2,fb);
	for(i=0;i<2;i++){
		printf("%s-",phonearr[i].name);
		printf("%s-",phonearr[i].tel);
		printf("%s-",phonearr[i].email);
	}
	strcpy(phonearr[1].name,"Lan Hoa");
	strcpy(phonearr[1].tel,"0923456");
	strcpy(phonearr[1].email,"lovelybuffalo@sis.hust.edu.vn");
	fseek(fb,1*sizeof(phoneaddress),SEEK_SET);
	irc=fwrite(phonearr,sizeof(phoneaddress),2,fb);
	printf("fwrite return code= %d\n",irc);
	fclose(fb);
	free(phonearr);
	
}
