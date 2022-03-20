#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct {
    char name[30];
    int diem[5];
    int dem;
}ketquathidau;

void giaodien(){
    printf("\n-----------------------------------------------------\n");
    printf("MAIN MENU\n");
    printf("1. Dang ki van dong vien\n");  
    printf("2. Thi dau\n");
    printf("3. Xep hang\n");
    printf("4. Sieu xa thu\n");
    printf("5. Thoat\n");
    printf("-----------------------------------------------------\n");
}

int input(){
    int n;
    do{
        scanf("%d", &n);
        if (n<=0 || n>10){
            printf("Nhap sai, nhap lai!\n");
        }
    }while(n<=0 || n > 10) ;
    return n;
}

void nhap_du_lieu(ketquathidau a[], int n){
    int i;
    for (i=0; i<n; i++){
        printf("Nhap thong tin van dong vien thu %d\n", i+1);
        printf("Nhap ten vdv: ");
        fflush(stdin);
        gets(a[i].name);
    }

    printf("\nDanh sach van dong vien tham gia thi dau:\n");
    for (i=0; i<n;i++){
        printf("%d. %s\n", i+1, a[i].name);
    }
}

void play(ketquathidau a[],int n){
    int i,j;
    for (i=0;i<n;i++){
        printf("\nLuot choi cua van dong vien %s\n", a[i].name);
        for (j=0;j<5;j++){
            printf("Nhap diem lan ban thu %d: ", j+1);
            a[i].diem[j] = input();
        }
    }
}

void print(ketquathidau a[], int n){
    int i,j;
    printf("%-25s %9s %9s %9s %9s %10s", "Ho Va Ten", "L1", "L2", "L3", "L4", "L5");
    for (i=0;i<n;i++){
        printf("\n%-25s", a[i].name);
        for (j=0;j<5;j++){
            printf("%10d", a[i].diem[j]);
        }
    }
}

int sum_point(int a[]){
    int i, sum=0;
    for (i=0;i<5;i++){
        sum += a[i];
    }
    return sum;
}

void sort(ketquathidau a[], int n){
    int i,j;
    ketquathidau temp;
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            if (sum_point(a[i].diem) < sum_point(a[j].diem)){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void result(ketquathidau a[], int n){
    int i;
    for (i=0;i<3;i++){
        printf("%-30s", a[i].name);
        if (i==0) printf("%-10s", "Gold");
        else if (i==1) printf("%-10s", "Silver");
        else printf("%-10s", "Bronze");
        printf("%-10d\n", sum_point(a[i].diem));
    }
}

int check_super(ketquathidau a){
    int i,dem=0;
    for (i=0;i<3;i++){
        if (a.diem[i] == 10 && a.diem[i+1] == 10 && a.diem[i+2] == 10){
            dem++;
        }
    }
    if (dem == 0) return 0;
    else return 1;
}

void super_gun(ketquathidau a[], int n){
    int i;
    for (i=0;i<n;i++){
        if (check_super(a[i]) == 1){
            printf("\n%-30s", a[i].name);
        }
    }
}

int main(){
    int choice,n;
    ketquathidau VDV[10];
    menu:
    giaodien();
    printf("Nhap lua chon: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Dang ki van dong vien\n");
            printf("Nhap so luong van dong vien: ");
            n= input();
            nhap_du_lieu(VDV,n);
            printf("\nPrint Enter to continue\n");
            getch();
            goto menu;
        case 2:
            printf("Thi dau\n");
            play(VDV,n);
            print(VDV,n);
            printf("\nPrint Enter to continue\n");
            getch();
            goto menu;
        case 3:
            printf("Xep hang\n");
            sort(VDV,n);
            result(VDV,n);
            printf("\nPrint Enter to continue\n");
            getch();
            goto menu;
        case 4:
            printf("Sieu xa thu\n");
            printf("Danh sach cac sieu xa thu :\n");
            super_gun(VDV,n);
            printf("\nPress Enter to continue\n");
            getch();
            goto menu;
        case 5:
            printf("Thoat chuong trinh\n");
            break;
        default:
            printf("Lua chon khong hop le\n");
            goto menu;
    }

}