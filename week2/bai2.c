#include <stdio.h>
#include <conio.h>

typedef struct {
	float x;
	float y;
}point_t;

typedef struct{
	point_t center;
	float radius;
}circle_t;
int kiemtra(point_t a,circle_t C){
	float x_disk,y_disk,S;
	x_disk=a.x-C.center.x;
	y_disk=a.y-C.center.y;
	S=x_disk*x_disk+y_disk*y_disk;
	if (S<=C.radius*C.radius) return 1;
	else return 0;
}
int main(){
	point_t a;
	circle_t C;
	printf("Nhap toa do diem can kiem tra :");
	scanf("%f %f",&a.x,&a.y);
	printf("\n Nhap thong so cua hinh tron :\n");
	printf("Nhap toa do tam :");
	scanf("%f %f",&C.center.x,&C.center.y);
	printf("\nNhap gia tri ban kinh:");
	scanf("%f",&C.radius);
	if (kiemtra(a,C)==1) printf("\nDiem duoc xet thuoc duong tron"); 
	else printf("\nDiem duoc xet ko thuoc hinh tron");
	
	return 0; 
}
