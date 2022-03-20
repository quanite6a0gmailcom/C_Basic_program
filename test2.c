#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct{
    char TenSV[20];
    float DiemQt,DiemCK,DiemTK;
    char DiemXL;
}DiemSV;

void giaodien(){
    printf("Chuong trinh quan ly diem mon hoc\n");
    printf("1. Nhap diem\n");
    printf("2. In bang diem\n");
    printf("3. Chenh lech diem\n");
    printf("4. Sap xep\n");
    printf("5. Thoat chuong trinh\n");
}
int input(){
    int n;
    do{
        printf("Nhap vao so luong sinh vien: ");
        scanf("%d",&n);
        if(n<1||n>40){
            printf("Lua chon khong hop le!Nhap lai\n");
        }

    }while(n<1 && n>40);
    return n;
}

float nhapdiem(){
    float n;
    do{
        scanf("%f",&n);
        if(n<0||n>10){
            printf("Diem khong hop le!Nhap lai\n");
        }
    }while(n<0 && n>10);
    return n;
}

char xeploai(float diem){
    if(diem >= 8.5){
        return 'A';
    }
    else if(diem < 8.5 && diem >= 7){
        return 'B';
    }
    else if(diem < 6.5 && diem >= 5){
        return 'C';
    }
    else if(diem < 5.5 && diem >= 4){
        return 'D';
    }
    else{
        return 'F';
    }
}

void nhap_thong_tin(DiemSV sv[],int n){
    int i;
    for (i=0;i<n;i++){
        printf("Nhap thong tin sinh vien thu %d\n",i+1);
        printf("Nhap ten sinh vien: ");
        fflush(stdin);
        gets(sv[i].TenSV);
        fflush(stdin);
        printf("Nhap diem qua trinh: ");
        sv[i].DiemQt=nhapdiem();
        printf("Nhap diem cuoi ky: ");
        sv[i].DiemCK=nhapdiem();
        
        sv[i].DiemTK=sv[i].DiemQt * 0.4 + sv[i].DiemCK * 0.6;

        if (sv[i].DiemQt <= 3 || sv[i].DiemCK <= 3){
            sv[i].DiemXL='F';
        }
        else{
            sv[i].DiemXL=xeploai(sv[i].DiemTK);
        }
    }
}

void print(DiemSV sv[],int n){
    int i;
    printf("%-10s %-20s %-15s %-15s %-15s\n","TenSV","DiemQt","DiemCK","DiemTK","DiemXL");
    for (i=0 ; i<n ; i++){
        printf("%-10s %-20.2f %-15.1f %-15.1f %-15c\n",sv[i].TenSV,sv[i].DiemQt,sv[i].DiemCK,sv[i].DiemTK,sv[i].DiemXL);
    }

}

int inputL(){
    int L;
    do{
        printf("\nNhap vao chenh lech: ");
        scanf("%d",&L);
        if(L<2||L>5){
            printf("Lua chon khong hop le!Nhap lai\n");
        }
    }while(L<2 || L>5);

    return L;
}

void chenhlech(DiemSV sv[],int n,int L){
    int i;
    for (i=0;i<n;i++){
        if (fabs(sv[i].DiemQt - sv[i].DiemCK) >= L){
            printf("%-10s %-20.2f %-15.1f %-15.1f %-15c\n",sv[i].TenSV,sv[i].DiemQt,sv[i].DiemCK,sv[i].DiemTK,sv[i].DiemXL);
        }
    }
}

void sort_by_point(DiemSV sv[],int n){
    int i,j;
    DiemSV temp;
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            if (sv[i].DiemTK < sv[j].DiemTK){
                temp=sv[i];
                sv[i]=sv[j];
                sv[j]=temp;
            }
        }
    }
}

void divide_name(char a[]){
    int i;
    char *token;
    token = strtok(a, " ");
    for (i=0;i<2;i++){
        token = strtok(NULL, " ");
    }
    strcpy(a,token);
}

void sort_by_name(DiemSV sv[],int n){
    int i,j;
    char a[20],b[20];
    DiemSV temp;
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            strcpy(a,sv[i].TenSV);
            strcpy(b,sv[j].TenSV);
            divide_name(a);
            divide_name(b);
            if (strcmp(a,b) > 0){
                temp=sv[i];
                sv[i]=sv[j];
                sv[j]=temp;
            }
        }
    }
}

int main(){
    int choice,L;
    DiemSV sv[40];
    int n;
    menu:
        giaodien();
        printf("Press (1,2,3,4,5) to choose: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nNhap diem cho sinh vien:\n");
                n = input();
                nhap_thong_tin(sv,n);
                goto menu;
            case 2:
                printf("\nIn bang diem:\n");
                print(sv,n);
                goto menu;
            case 3:
                printf("\nChenh lech diem:\n");
                L =inputL();
                chenhlech(sv,n,L);
                goto menu;
            case 4:
                printf("\nSap xep:\n");
                sort_by_point(sv,n);
                sort_by_name(sv,n);
                print(sv,n);
                goto menu;
            case 5:
                printf("\nThoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le!Nhap lai\n");
                goto menu;
        }
}