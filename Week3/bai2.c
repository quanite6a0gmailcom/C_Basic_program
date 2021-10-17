#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char name[20];
	char tel[11];
	char email[20];
}phone;
struct LinkedList{
     phone data;
    struct LinkedList *next;
 };
 typedef struct LinkedList *node;
 node CreateNode(phone value){
    node temp; 
    temp = (node)malloc(sizeof(struct LinkedList)); 
    temp->next = NULL;
    temp->data = value; 
    return temp;
}
node AddTail(node head, phone value){
    node temp,p;
    temp = CreateNode(value);
    if(head == NULL){
        head = temp;     
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}
node InitHead(){
    node head;
    head = NULL;
    return head;
}
node Input(){
    node head = InitHead();
    int n;
    phone value;
    int i;
    do{
        printf("\nNhap so luong phan tu n = ");
        scanf("%d", &n);
    }while(n <= 0);
 
    for( i = 0; i < n; ++i){
        printf("\nNhap gia tri can them: ");
        printf("\nNhap ten:");
        fflush(stdin);
        gets(value.name);
        printf("\nNhap so dien thoai:");
        fflush(stdin);
        gets(value.tel);
        printf("\nNhap so email:");
        fflush(stdin);
        gets(value.email);
        head = AddTail(head, value);
    }
    return head;
}


void Traverser(node head){
    printf("\n");
    node p;
    for( p = head; p != NULL; p = p->next){
        printf("\nten:%s", p->data.name);
    }
}
node DelHead(node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
node DelTail(node head){
    if (head == NULL || head->next == NULL){
         return DelHead(head);
    }
    node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; // Cho next b?ng NULL
    // Ho?c vi?t p->next = NULL cung du?c
    return head;
}
node AddHead(node head, phone value){
    node temp = CreateNode(value); // Kh?i t?o node temp v?i data = value
    if(head == NULL){
        head = temp; // //N?u linked list dang tr?ng th� Node temp l� head lu�n
    }else{
        temp->next = head; // Tr? next c?a temp = head hi?n t?i
        head = temp; // �?i head hi?n t?i = temp(V� temp b�y gi? l� head m?i m�)
    }
    return head;
}
 
node AddAt(node head, phone value, int position){
    if(position == 0 || head == NULL){
        head = AddHead(head, value); // N?u v? tr� ch�n l� 0, t?c l� th�m v�o d?u
    }else{
        // B?t d?u t�m v? tr� c?n ch�n. Ta s? d�ng k d? d?m cho v? tr�
        int k = 1;
        node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // N?u duy?t h?t danh s�ch lk r?i m� v?n chua d?n v? tr� c?n ch�n, ta s? m?c d?nh ch�n cu?i
            // N?u b?n kh�ng mu?n ch�n, h�y th�ng b�o v? tr� ch�n kh�ng h?p l?
            head = AddTail(head, value);
            // printf("Vi tri chen vuot qua vi tri cuoi cung!\n");
        }else{
            node temp = CreateNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}
 int main(){
 	phone add;
 	printf("\n==Tao 1 danh sach lien ket==");
    node head = Input();
    Traverser(head);
    printf("Nhap du lieu can them:\n");
     printf("\nNhap ten:");
        fflush(stdin);
        gets(add.name);
        printf("\nNhap so dien thoai:");
        fflush(stdin);
        gets(add.tel);
        printf("\nNhap so email:");
        fflush(stdin);
        gets(add.email);
     printf("\n==Thu them 1 phan tu vao linked list==");
    head = AddAt(head, add,1);
    Traverser(head);
      printf("\n==Thu xoa 1 phan tu khoi linked list==");
    head = DelTail(head);
    Traverser(head);
    
 }
