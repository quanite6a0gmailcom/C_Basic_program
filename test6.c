#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
    int color;
    int score;
} Player;

void giaodien(){
    printf("\n--------------------------------------------------\n");
    printf("MAIN MENU\n");
    printf("1. Tao ma tran o mau\n");
    printf("2. Thay doi ma tran\n");
    printf("3. Thuc hien choi\n");
    printf("4. Hien thi ket quat\n");
    printf("5. Thoat\n");
    printf("--------------------------------------------------\n");
}

void nhap(int a[][100]){
    int i,j;
    for( i = 0; i < 5; i++){
        for( j = 0; j < 3; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuat(int a[][100]){
    int i,j;
    for( i = 0; i < 5; i++){
        for( j = 0; j < 3; j++){
            if(a[i][j] == 0){
                printf("%-10s ", "Xanh");
            }
            else if (a[i][j] == 1)
            {
                printf("%-10s ", "Vang");
            }
            else {
                printf("%-10s ", "Do");
            }
                       
        }
        printf("\n");
    }
}

int toa_do_hang(){
    int i;
    do{
    printf("Nhap toa do hang: ");
    scanf("%d", &i);
    if (i < 0 || i > 4)
    {
        printf("Toa do khong hop le!Nhap lai\n");
    }
    }while(i < 0 || i > 4);
    return i;
}

int toa_do_cot(){
    int j;
    do{
    printf("Nhap toa do cot: ");
    scanf("%d", &j);
    if (j < 0 || j > 2)
    {
        printf("Toa do khong hop le!Nhap lai\n");
    }
    }while(j < 0 || j > 2);
    return j;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void change_matrix(int a[][100],int x,int y){
    int i,j;
    int temp;
    for( i = 0; i < 5; i++){
        for( j = 0; j < 3; j++){
            if(i == x && j == y){
                do{
                    printf("Nhap gia tri moi: ");
                    scanf("%d", &temp);
                    if (temp == a[i][j])
                    {
                        printf("Gia tri khong thay doi!Nhap lai\n");
                    }
                }while(temp == a[i][j]);

            }
            if (a[i][j] == temp)
                swap(&a[i][j], &a[x][y]);
        }
    }

}

int score(int a[][100],int temp){
    int i,j;
    int count = 0;
    int x,y;
    for( i = 0; i < 5; i++){
        printf("\nNhap toa do la %d\n", i+1);
        x = toa_do_hang();
        y = toa_do_cot();
        if(a[x][y] == temp){
            count++;
        }
        else{
            printf("Gia tri khong dung!\n");
            break;
        } 
    }
    return count;
}

void playing(int a[][100],Player person[]){
    int i,j,k;
    int x,y;
    int temp;
    for (k=0;k<4;k++){
        printf("\nLuot choi cua nguoi choi thu %d\n",k+1);
        printf("Nhap ten nguoi choi: ");
        fflush(stdin);
        gets(person[k].name);
        printf("\nNhap mau muon lua chon: ");
        scanf("%d", &temp);
        person[k].color = temp;
        person[k].score = score(a,temp);

    }

}

void print(Player person[]){
    int i;
    printf("%-20s %-20s %-20s %-20s\n","Luot choi","Nguoi choi","Mau lua chon","Diem");
    for(i=0;i<4;i++){
        printf("%-20d %-20s ",i+1,person[i].name);
        if(person[i].color == 0){
            printf("%-20s ", "Xanh");
        }
        else if (person[i].color == 1)
        {
            printf("%-20s ", "Vang");
        }
        else {
            printf("%-20s ", "Do");
        }
        printf("%-20d\n",person[i].score);
    }
}

void sort(Player person[]){
    int i,j;
    Player temp;
    for(i=0;i<4;i++){
        for(j=i+1;j<4;j++){
            if(person[i].score < person[j].score){
                temp = person[i];
                person[i] = person[j];
                person[j] = temp;
            }
        }
    }
}

int main(){
    int choice;
    int color[100][100];
    int x,y;
    Player person[4];

    menu:
        giaodien();
        printf("\nNhap lua chon: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nTao ma tran o mau\n");
                nhap(color);
                printf("\nMa tran sau khi nhap:\n");
                xuat(color);
                goto menu;
            case 2:
                printf("\nThay doi ma tran\n");
                printf("Nhap toa do can doi:\n");
                x = toa_do_hang();
                y = toa_do_cot();
                change_matrix(color,x,y);
                xuat(color);
                goto menu;
            case 3:
                printf("\nThuc hien choi\n");
                playing(color,person);
                goto menu;
            case 4:
                printf("\nHien Thi Ket Qua\n");
                print(person);
                sort(person);
                printf("\nNguoi choi co diem so cao nhat la :");
                printf("%20s",person[0].name);
                printf("\nNguoi choi co diem so thap nhat la :");
                printf("%20s\n",person[3].name);
                goto menu;
            case 5:
                printf("\nThoat chuong trinh\n");
                break;
            default:
                printf("\nLua chon khong hop le\n");
                goto menu;
        }
}