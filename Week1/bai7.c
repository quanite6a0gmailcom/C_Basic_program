#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void swap(FILE *fp1,FILE *fp2){
	char c;
	while((c=fgetc(fp1))!=EOF){
		if (c>='a'&&c<='z') c=c-32;
		else if(c>='A'&&c<='Z') c+=32;
		else c=c;
		fputc(c,fp2);
		putchar(c);
	}
}
int main(){
	FILE *fp1,*fp2;
	fp1=fopen("C:\\lab1.txt","r");
	fp2=fopen("C:\\lab1w.txt","w");
	swap(fp1,fp2);
	fclose(fp1);
	fclose(fp2);
	
}
