#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	FILE *ptr1,*ptr2;
	char str[50],str1[50],c;
	int i=0;
	
	ptr2=fopen("C:\\lab1a.txt","w+");
	ptr1=fopen("C:\\lab1.txt","r");
	while((c=fgetc(ptr1))!=EOF){
		str[i]=c;
		i++;
	}
	fwrite(str,1,i,ptr2);
    fseek(ptr2,SEEK_SET,0);
    fread(str1,1,i+1,ptr2);
    puts(str1);
	fclose(ptr1);
    fclose(ptr2); 
	return 0;
}

