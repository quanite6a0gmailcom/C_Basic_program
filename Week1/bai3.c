#include <stdio.h>
void split(float num,int *int_part,float *frac_part){
	*int_part=(int)num;
	*frac_part=num-*int_part;
}
int main(){
	float num;
	int int_part;
	float frac_part;
	printf("Nhap mot so thuc:");
	scanf("%f",&num);
	split(num,&int_part,&frac_part);
	printf("Phan nguyen cua so thuc nhap vao la :%d\n",int_part);
	printf("Phan thap phan cua so thuc nhap vao la :%f\n",frac_part);
	return 0;
	}

