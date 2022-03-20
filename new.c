#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char a[20];
    printf("Nhap a:");
    fflush(stdin);
    gets(a);
    strlwr(a);
    printf("%s",a);

}