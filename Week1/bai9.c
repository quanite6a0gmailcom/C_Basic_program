#include <string.h>
#include <stdio.h>
#define MAX_LEN 50
enum {SUCCESS, FAIL};

void LineReadWrite(FILE *fin, FILE *fout) {
  char buff[MAX_LEN];
  int len;
while (fgets(buff, MAX_LEN, fin) != NULL) {
len = strlen(buff);
fprintf(fout, "%d %s", len, buff); printf("%s", buff);
} }
main(void) {
FILE *fptr1, *fptr2;
char filename1[]= "lab1a.txt"; char filename2[]= "lab1.txt"; int reval = SUCCESS;
if ((fptr1 = fopen(filename1, "w")) == NULL){ printf("Cannot open %s.\n", filename1); reval = FAIL;
} else if ((fptr2 = fopen(filename2, "r")) == NULL){ printf("Cannot open %s.\n", filename2);
reval = FAIL;
} else {
LineReadWrite(fptr2, fptr1); fclose(fptr1); fclose(fptr2);
}
return reval;
}
