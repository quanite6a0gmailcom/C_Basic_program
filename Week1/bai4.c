#include <stdio.h>
#include <string.h>
void replace_char(char *str,char c1,char c2){
	if (str==NULL) return;
	while(*str!='\0'){
		if (*str==c1)
		*str=c2;
		++str;
	}
}
int main(){
	char str[50];
	char c1,c2;
	printf("Nhap chuoi ki tu:");
	fflush(stdin);
	gets(str);
	printf("\nNhap lan luot 2 ki tu dau vao:");
	scanf("%c %c",&c1,&c2);
	replace_char(str,c1,c2);
	printf("\nChuoi ki tu sau khi thay the la:");
	puts(str);
}
