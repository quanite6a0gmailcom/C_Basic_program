#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char name[30];
    int old;
    int score[5];
}Game;


void giaodien(){
    printf("\n-----------------------------------------------------\n");
    printf("MAIN MENU\n");
    printf("1. Khoi dong tro choi\n");  
    printf("2. Choi doan ky tu\n");
    printf("3. Tong hop ket qua\n");
    printf("4. Thoat\n");
    printf("-----------------------------------------------------\n");
}

void nhap_xau_s(char s[]){
    do{
        printf("Nhap xau: ");
        fflush(stdin);
        gets(s);
        if (strlen(s)<20 || strlen(s)>40){
            printf("Nhap sai, nhap lai!\n");
        }
    }while(strlen(s)<20 || strlen(s)>40);
    strlwr(s);
}

int total_person(){
    int n;
    do{
        printf("Nhap so luong nguoi choi: ");
        scanf("%d", &n);
        if (n<=0 || n>4){
            printf("Nhap sai, nhap lai!\n");
        }
    }while(n<=0 || n > 4);
    return n;
}

void nhap_du_lieu(Game a[],int n){
    int i;
    for (i=0; i<n; i++){
        printf("Nhap thong tin nguoi choi thu %d\n", i+1);
        printf("Nhap ten nguoi choi: ");
        fflush(stdin);
        gets(a[i].name);
        printf("Nhap tuoi nguoi choi: ");
        scanf("%d", &a[i].old);
    }

    printf("%-20s %-10s ","Ho Va Ten","Tuoi");
    for (i=0; i<n;i++){
        printf("\n%-20s %-10d", a[i].name, a[i].old);
    }
}

void hienthi(char s[]){
    int i;
    printf("O chu bi mat la: ");
    for (i=0;i<strlen(s);i++){
        printf("*");
    }
    printf("\n");
}

void make_xau(char t[],char s[]){
    int i;
    for (i=0;i<strlen(s);i++){
        t[i] = '*';
    }
}

int guest(char s[],char t[] ,char a){
    int i,dem=0;
    for (i=0;i<strlen(s);i++){
        if (s[i] == a && t[i] == '*'){
            t[i] = a;
            dem++;
        }
    }
    puts(t);
    return dem;
}

int sum(int a[]){
    int i,sum=0;
    for (i=0;i<4;i++){
        sum += a[i];
    }
    return sum;
}

void playing(Game a[],int n,char s[]){
    int i,j;
    char x,t[40];
    for (i=0;i<n;i++){
        make_xau(t,s);
        printf("\nLuot choi cua nguoi choi %s\n", a[i].name);
        for (j=0;j<5;j++){
            if (j!=4){ 
            printf("\nNhap du doan luot %d: ", j+1);
            fflush(stdin);
            scanf("%c", &x);
            x = tolower(x);
            a[i].score[j] = guest(s,t,x);
            }
            else{
                char h[40];
                printf("\nO chu bi mat la: ");
                fflush(stdin);
                gets(h);
                if (strcmp(h,s)==0){
                    printf("\nO chu chinh xac!\n");
                    a[i].score[4] = sum(a[i].score)+20;
                }
                else{
                    printf("\nO chu ko chinh xac!\n");
                    a[i].score[4] = sum(a[i].score);
                }
            }
        }
    }
}

void print(Game a[],int n){
    int i,j;
    printf("%-20s %-10s %-10s %-10s %-10s %-10s\n","Ho Va Ten","L1","L2","L3","L4","Ket qua");
    for (i=0;i<n;i++){
        printf("%-20s ", a[i].name);
        for (j=0;j<5;j++){
            printf("%-10d ", a[i].score[j]);
        }
        printf("\n");
    }
}

void sort(Game a[],int n){
    int i,j;
    Game temp;
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            if (a[i].score[4]<a[j].score[4]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void rank(Game a[],int n){
    int i,j;
    printf("%-20s %-10s %-10s %-10s %-10s %-10s\n","Ho Va Ten","L1","L2","L3","L4","Ket qua");
    for (i=0;i<n;i++){
        printf("%-20s ", a[i].name);
        for (j=0;j<5;j++){
            printf("%-10d ", a[i].score[j]);
        }
        printf("\n");
    }
}

int main(){
    int choice,n;
    char S[40];
    Game Person[4];

    menu:
        giaodien();
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Khoi dong tro choi\n");
                nhap_xau_s(S);
                n = total_person();
                nhap_du_lieu(Person, n);
                goto menu;
            case 2:
                printf("Choi doan ky tu\n");
                hienthi(S);
                playing(Person, n,S);
                print(Person, n);
                goto menu;
            case 3:
                printf("Tong hop ket qua\n");
                printf("\nBANG XEP HANG\n");
                sort(Person, n);
                rank(Person, n);
                goto menu;
            case 4:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                goto menu;
        }

}