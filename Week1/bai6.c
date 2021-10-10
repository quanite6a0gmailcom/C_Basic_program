#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void CharReadWrite(FILE *fptr1,FILE *fptr2){
	char c;
	while((c=fgetc(fptr1))!=EOF){
		fputc(c,fptr2);
	
	}
}
int main(){
	FILE *fptr1,*fptr2;
	fptr1=fopen("C:\\lab1.txt","r");
	fptr2=fopen("C:\\lab1w.txt","w");
	CharReadWrite(fptr1,fptr2);
	fclose(fptr1);
	fclose(fptr2);
	return 0;
	
	
}
