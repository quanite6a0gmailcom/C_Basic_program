#include <stdio.h>
#include <string.h>

typedef struct{
	int MSSV;
	char Ho_Va_ten[30];
	float HD,PB,HD1,HD2,HD3;
}DoAn;
void giaodien(){
	printf("***********************************************************\n");
	printf("**        Chuong Trinh Tinh Diem Tot Nghiep              **\n");
	printf("**         1.Bo Xung Sinh Vien                           **\n");
	printf("**         2.Danh Sach Sinh Vien Bao Ve Thanh Cong       **\n");
	printf("**         3.Sap Xep theo ten                            **\n");
	printf("**         4.Thoat chuong trinh                          **\n");
	printf("***********************************************************\n");
}
void nhapthongtin(DoAn SV[],int n){
       
}
void nhapSV
int main(){
	DoAn SV[20];
	int n;
	int key;
	int S=0;
	menu:
		giaodien();
		switch(key){
			case 1:
				printf("Ban da chon nhap sinh vien\n");
				do{
				printf("Nhap so sinh vien:");
				scanf("%d",&n);
		}while(n)
		}
}
