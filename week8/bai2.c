#include <stdio.h>
#include <stdlib.h>

struct Tnode{
    char inf;
    struct Tnode *Left_child;
    struct Tnode *Right_child;
};
typedef struct Tnode BST;
BST *createnewnode(char a){
    BST *newnode=(BST*)malloc(sizeof(BST));
    if (newnode==NULL){
        printf("out of memory!!!\n");
        exit(1);
    }
     else{
         newnode->Left_child=NULL;
         newnode->Right_child=NULL;
         newnode->inf=a;
     }
 return newnode;
}
void PreOrder(BST *r){
    if (r!=NULL){
        printf("%c ",r->inf);
        PreOrder(r->Left_child);
        PreOrder(r->Right_child);
    }
}
void Inorder(BST *r){
    if (r!=NULL){
        Inorder(r->Left_child);
        if(r->inf=='b') printf("(");
        printf("%c",r->inf);
        if(r->inf=='c') printf(")");
        Inorder(r->Right_child);
    }
}
int main(){
    BST *root=NULL;
    BST *nutB,*nutC,*nutD,*nutE,*nutF,*nutG,*nutH;
     root=createnewnode('+');
	nutB=createnewnode('!');
	nutC=createnewnode('/');
	nutD=createnewnode('a');
	nutE=createnewnode('-');
	nutF=createnewnode('d');
	nutG=createnewnode('b');
	nutH=createnewnode('c');
    root->Left_child=nutB;
    root->Right_child=nutC;
    nutB->Left_child=nutD;
    nutC->Left_child=nutE;
    nutC->Right_child=nutF;
    nutE->Left_child=nutG;
    nutE->Right_child=nutH;
    printf("\n------BIEU THUC----------\n");
    Inorder(root);
}