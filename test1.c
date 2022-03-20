#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
    char mssv[5];
    float hd,pb,hd1,hd2,hd3;
    float gk,ck;
} sinhvien;

void giaodien(){
    printf("---------MAIN MENU-----------------------\n");
    printf("1. Bo sung sinh vien\n");
    printf("2. Danh sach sinh vien bao ve thanh cong\n");
    printf("3. Sap xep theo ten sinh vien\n");
    printf("4. Thoat chuong trinh\n");
    printf("------------------------------------------\n");
}

int first_input(int n){
    do
    {
        printf("Nhap so luong sinh vien: ");
        scanf("%d",&n);
        if(n < 0 && n > 20)
            printf("So luong sinh vien phai lon hon 0\n");
    } while (n<0 && n>20);
    return n;
    
}

void nhap_du_lieu(sinhvien SV[], int n){
    int i;
    for (i=0;i<n;i++){
        printf("Nhap thong tin sinh vien thu %d\n",i+1);
        int dem=0;
        fflush(stdin);
        printf("Nhap ten sinh vien: ");
        gets(SV[i].name);
        fflush(stdin);
        printf("Nhap MSSV: ");
        scanf("%s",SV[i].mssv);
        printf("Nhap diem huong dan: ");
        scanf("%f",&SV[i].hd);
        if (SV[i].hd < 5.5)
            dem++;
        printf("Nhap diem phan bien: ");
        scanf("%f",&SV[i].pb);
        if (SV[i].pb < 5.5)
            dem++;
        printf("Nhap diem hoi dong 1: ");
        scanf("%f",&SV[i].hd1);
        if (SV[i].hd1 < 5.5)
            dem++;
        printf("Nhap diem hoi dong 2: ");
        scanf("%f",&SV[i].hd2);
        if (SV[i].hd2 < 5.5)
            dem++;
        printf("Nhap diem hoi dong 3: ");
        scanf("%f",&SV[i].hd3);
        if (SV[i].hd3 < 5.5)
            dem++;
        if (dem > 0) {
            SV[i].gk = 0;
            SV[i].ck = 0;
        }
        else{
            SV[i].gk = (SV[i].hd + SV[i].pb)/2;
            SV[i].ck = (SV[i].hd1 + SV[i].hd2 + SV[i].hd3)/3;
        }
            
    }
}

float nhapdiem(float point){
    do
    {
        printf("Nhap diem: ");
        scanf("%f",&point);
        if(point < 0 && point > 10)
            printf("Diem phai nam trong khoang 0-10\n");
    } while (point<0 && point>10);
    return point;
}

void nhap_du_lieu1(sinhvien SV[], int n,int n1){
    int i,sum;
    sum = n + n1;
    if (sum > 20)
        sum = 20;
    for (i=n;i<sum;i++){
        printf("Nhap thong tin sinh vien thu %d\n",i+1);
        int dem=0;
        fflush(stdin);
        printf("Nhap ten sinh vien: ");
        gets(SV[i].name);
        fflush(stdin);
        printf("Nhap MSSV: ");
        scanf("%s",SV[i].mssv);
        printf("Nhap diem huong dan: ");
        SV[i].hd = nhapdiem(SV[i].hd);
        if (SV[i].hd < 5.5)
            dem++;
        printf("Nhap diem phan bien: ");
        SV[i].pb = nhapdiem(SV[i].pb);
        if (SV[i].pb < 5.5)
            dem++;
        printf("Nhap diem hoi dong 1: ");
        SV[i].hd1 = nhapdiem(SV[i].hd1);
        if (SV[i].hd1 < 5.5)
            dem++;
        printf("Nhap diem hoi dong 2: ");
        SV[i].hd2 = nhapdiem(SV[i].hd2);
        if (SV[i].hd2 < 5.5)
            dem++;
        printf("Nhap diem hoi dong 3: ");
        SV[i].hd3 = nhapdiem(SV[i].hd3);
        if (SV[i].hd3 < 5.5)
            dem++;
        if (dem > 0) {
            SV[i].gk = 0;
            SV[i].ck = 0;
        }
        else{
            SV[i].gk = (SV[i].hd + SV[i].pb)/2;
            SV[i].ck = (SV[i].hd1 + SV[i].hd2 + SV[i].hd3)/3;
        }
            
    }

}

void print(sinhvien SV[],int n){
    int i;
    printf("%s %10s %20s %10s %10s %10s %10s %10s %10s\n","MSSV","Ho Va Ten","HD","PB","HD1","HD2","HD3","GK","CK");
    for (i=0;i<n;i++){
        printf("%s %10s %20.2f %10.2f %10.2f %10.2f %10.2f %10.1f %10.1f\n",SV[i].mssv,SV[i].name,SV[i].hd,SV[i].pb,SV[i].hd1,SV[i].hd2,SV[i].hd3,SV[i].gk,SV[i].ck);
    }
}

void list_complete(sinhvien SV[], int n){
    int i;
    printf("%s %10s %20s %10s %10s %10s %10s %10s %10s\n","MSSV","Ho Va Ten","HD","PB","HD1","HD2","HD3","GK","CK");
    for (i=0;i<n;i++){
        if (SV[i].gk != 0 && SV[i].ck != 0)
            printf("%s %10s %20.2f %10.2f %10.2f %10.2f %10.2f %10.1f %10.1f\n",SV[i].mssv,SV[i].name,SV[i].hd,SV[i].pb,SV[i].hd1,SV[i].hd2,SV[i].hd3,SV[i].gk,SV[i].ck);
    }
}

void cut_last_name(char name[]){
    char *token;
    token = strtok(name," ");
    while (token != NULL){
        strcpy(name,token);
        token = strtok(NULL," ");
    }
    printf("%s\n",name);

}

void sort_last_name(sinhvien SV[], int n){
    int i,j;
    


}


int main(){
    sinhvien SV[20];
    int choice,temp = 0;
    int n,n1;
    menu:
    giaodien();
    printf("Nhap chuc nang lua chon: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Chuc nang bo sung sinh vien\n");
            if (temp == 0){
                n = first_input(n);
                nhap_du_lieu(SV,n);
                temp++;
            }
            else{
                n1 = first_input(n1);
                nhap_du_lieu1(SV,n,n1);
                n = n + n1;
            }
            print(SV,n);
            goto menu;

        case 2:
            printf("Chuc nang in danh sach sinh vien bao ve thanh cong\n");
            list_complete(SV,n);
            goto menu;
        case 3:
            printf("Chuc nang sap xep sinh vien theo ten\n");
            sort_name(SV,n);
            print(SV,n);
            goto menu;
        case 4:
            printf("QUIT menu\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
            goto menu;
    }
    return 0;
}