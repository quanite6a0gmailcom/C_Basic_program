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
int Height_BST(BST *r){
    if (r==NULL) return 0;
    int ld=Height_BST(r->Left_child);
    int rd=Height_BST(r->Right_child);
    if (ld>rd) return 1+ld;
    else return 1+rd;
}
int count_Node(BST *r){
    if (r==NULL) return 0;
    else{
    int ld=count_Node(r->Left_child);
    int rd=count_Node(r->Right_child);
    return 1+ld+rd;
    }
}
int main(){
    BST *root=NULL;
    BST *nutB, *nutC, *nutD, *nutE, *nutF, *nutG, *nutH, *nutI, *nutJ, *nutK;
    root=createnewnode('A');
	nutB=createnewnode('B');
	nutC=createnewnode('C');
	nutD=createnewnode('D');
	nutE=createnewnode('E');
	nutF=createnewnode('F');
	nutG=createnewnode('G');
	nutH=createnewnode('H');
	nutI=createnewnode('I');
	nutJ=createnewnode('J');
	nutK=createnewnode('K');

    root->Left_child=nutB;
    nutB->Left_child=nutE;
    nutB->Right_child=nutC;
    nutE->Right_child=nutF;
    nutC->Left_child=nutG;
    nutC->Right_child=nutD;
    nutG->Left_child=nutH;
    nutH->Right_child=nutI;
    nutI->Right_child=nutJ;
    nutJ->Right_child=nutK;

    printf("----------------Duyet Truoc-------------------\n");
    PreOrder(root);
    printf("\nCHieu cao cua cay la:%d",Height_BST(root));
    printf("\nSo nut la cua cay nhi phan la :%d",count_Node(root));
    

}