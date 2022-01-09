#include <stdio.h>
#include <stdlib.h>

typedef int Keytype;
struct Node{
    Keytype Key;
    struct Node* Left;
    struct Node* Right;

};
typedef struct Node *BST;
void makenullBST(BST *T){
    (*T)=NULL;
}

int emptyBST(BST T){
    return T==NULL;
}
BST Search(Keytype X,BST root){
    if (root==NULL) return NULL;
    else if (root->Key==X)
    return root;
    else if (root->Key<X)
    return Search(X,root->Right);
    else return Search(X,root->Left);
}
void insertNode(Keytype X,BST *T){
    if ((*T)==NULL){
        *T=(struct Node*)malloc(sizeof(struct Node));
        (*T)->Key=X;
        (*T)->Left=NULL;
        (*T)->Right=NULL;
    }
    else if ((*T)->Key==X)
    printf("Da ton tai nut co khao x");
    else if((*T)->Key>X)
    insertNode(X,&(*T)->Left);
    else insertNode(X,&(*T)->Right);
}
Keytype deleteMin(BST *T){
    Keytype k;
    if ((*T)->Left==NULL)
    {
        k=(*T)->Key;
        (*T)=(*T)->Right;
        return k;
    }
    return deleteMin(&(*T)->Left);
}

void DeleteNode(Keytype X,BST *T){
    if ((*T)!=NULL)
    if(X<(*T)->Key)
    DeleteNode(X,&(*T)->Left);
    else if(X>(*T)->Key)
    DeleteNode(X,&(*T)->Right);
    else if(((*T)->Left==NULL)&&((*T)->Right==NULL))
    (*T)=NULL;
    else if((*T)->Left==NULL)
    (*T)=(*T)->Right;
    else if((*T)->Right==NULL)
    (*T)=(*T)->Left;
    else 
    (*T)->Key=deleteMin(&(*T)->Right);
    
}
void preOrder(BST T){
    if (T!=NULL){
        printf("%d ",T->Key);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}
int n,a[20];
void readBST(BST *T){
    int i;
    FILE *f;
   makenullBST(T);
    Keytype X;
    f=fopen("BST.txt","r");
    if (f!=NULL){
        fscanf(f,"%d",&n);
        for (i=1;i<=n;i++){
            fscanf(f,"%d",&X);
            insertNode(X,T);
            a[i-1]=X;
        }
    }else printf("Loi mo file\n");
}
void freetree(BST T){
    if (T!=NULL){
        freetree(T->Left);
        freetree(T->Right);
        free(T);
    }
}
int main(){
    BST T;
    BST K;
    Keytype X;
    int i;
    readBST(&T);
    printf("Danh sach duyet tien tu la :\n");
    preOrder(T);
    printf("\n");
    printf("\nNhap so can tim kiem:");
    scanf("%d",&X);
    K=Search(X,T);
    if (K!=NULL) printf("Key %d found in the tree",X);
    else insertNode(X,&T);
    printf("\nDuyet---\n");
    preOrder(T);
    freetree(T);
    return 0;

}