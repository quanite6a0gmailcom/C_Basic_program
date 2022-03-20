#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    char Name[25];
    int Old;
    float Suggest[6];
}Result;

void giaodien(){
    printf("---------------------------------\n");
    printf("MAIN MENU\n");
    printf("1.Khoi dong tro choi\n");
    printf("2.Choi doan so\n");
    printf("3.Tong hop ket qua\n");
    printf("4.Thoat\n");
    printf("---------------------------------\n");
}

float input_secret_number(){
    float n;
    do{
        printf("Nhap so can giai ma: ");
        scanf("%f",&n);
        if (n<0 || n>100) printf("So nhap vao khong hop le!Moi nhap lai:\n");
    }while(n<0 || n>100);
    return n;
}

int input_sum_of_player(){
    int n;
    do{
        printf("Nhap tong so cua nguoi choi: ");
        scanf("%d",&n);
        if (n<0 || n>5) printf("So nhap vao khong hop le!Moi nhap lai:\n");
    }while(n<0 || n>5);
    return n;
}

int check(char a[]){
    int i;
    int dem = 0;
    for (i=0;i<strlen(a);i++){
        if (a[i]== ' ') dem++;
    }
    if (dem == 0) return 0;
    else return 1;
}

void nhap_ten(char a[]){
    do{
        printf("Nhap ten nguoi choi: ");
        fflush(stdin);
        gets(a);
        if (check(a)==0) printf("Ten nguoi choi khong hop le!Moi nhap lai:\n");
    }while(check(a)==0);
}

void nhap_du_lieu(Result a[],int n){
    int i;
    for (i=0;i<n;i++){
        printf("Nhap thong tin nguoi choi thu %d:\n",i+1);
        nhap_ten(a[i].Name);
    }
    
    printf("DANH SACH NGUOI CHOI LA:\n");
    for (i=0;i<n;i++){
      printf("%s\n",a[i].Name);
    }
}

void play_game(Result a[],int n,int m){
    int i,j;
    for (i=0;i<m;i++){
        printf("\nLuot choi cua nguoi choi %s:\n",a[i].Name);
        for (j=0;j<6;j++){
            printf("\nNHap du doan lan %d: ",j+1);
            scanf("%f",&a[i].Suggest[j]);
            if (a[i].Suggest[j] == n){
                printf("\nBan da giai ma du doan dung!\n");
                break;
            }
            else if (a[i].Suggest[j] < n){
                printf("\nBan da giai ma sai!So nhap vao nho hon so can giai ma!\n");
            }
            else if (a[i].Suggest[j] > n){
                printf("\nBan da giai ma sai!So nhap vao lon hon so can giai ma!\n");
            }
        }
    }
}

void print(Result a[], int m){
    int i,j;
    printf("%-17s %-10s %-10s %-10s %-10s %-10s %-10s\n","Ho va ten","L1","L2","L3","L4","L5","L6");
    for (i=0;i<m;i++){
        printf("%10s",a[i].Name);
        
         for (j=0;j<6;j++){
             if (a[i].Suggest[j] != 0) 
              printf("%10.1f",a[i].Suggest[j]);
         }
         printf("\n");
    }
}

float chech_lech(Result a,float n){
    int i;
    float lech;
    for (i=0;i<6;i++){
        if (a.Suggest[i] == n) {
            lech = 0;
            break;
        }
        if (i == 5) 
        lech =fabs(a.Suggest[i]/n-1);
    }
    return lech;
    
   
}

void sort(Result a[],int m,int n){
    int i,j;
    Result temp;
    for (i=0;i<m;i++){
        for (j=i+1;j<m;j++){
            if (chech_lech(a[i],n)>chech_lech(a[j],n)){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void print_result(Result a[],int m,int n){
    int i;
    printf("\nDANH SACH NGUOI CHOI SAU KHI GIAI MA LA:\n");
    printf("%-10s %-10s %-10s \n","STT","Ho va ten","Do Sai Lech");
    for (i=0;i<m;i++){
        printf("%10d",i+1);
        printf("%10s",a[i].Name);
        printf("%10.1f\n",chech_lech(a[i],n));
    }
}

int main(){
    Result person[5];
    int choice;
    int N,n,M;

    menu:
    giaodien();
    printf("Nhap lua chon: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("START GAME\n");
            N = input_secret_number();
            M = input_sum_of_player();
            nhap_du_lieu(person,M);
            goto menu;
        case 2:
            printf("PLAY GAME\n");
            play_game(person,N,M);
            print(person,M);
            goto menu;
        case 3:
            printf("PRINT RESULT\n");
            sort(person,M,N);
            print_result(person,M,N);
            goto menu;
        case 4:
            printf("EXIT GAME\n");    
            break;
        default:
            printf("Khong co chuc nang nay!!!\n");
            goto menu;
    }


}