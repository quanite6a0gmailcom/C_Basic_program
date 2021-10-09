#include <stdio.h>
#include <string.h>
#define string_len 50
void doi(char s[],char a,char b){
	int i;
	for (i=0;i<strlen(s);i++){
		if (s[i]==a)
		s[i]=b;
	}
	
}
int main(){
	char s[string_len];
	int i,n=0;
	char a,b;
	printf("Nhap xau ki tu :");
	fflush(stdin);
	gets(s);
	for (i=0;i<strlen(s);i++){
		if (s[i]==' ') n++;
	}
	if (n!=0) printf("Nhap lai xau::");
	else{
	
	printf("\nNhap 2 ki tu : ");
	scanf("%c %c",&a,&b);
	doi(s,a,b);
	printf("Xau sau khi doi la:");
	puts(s);
}
	
}
