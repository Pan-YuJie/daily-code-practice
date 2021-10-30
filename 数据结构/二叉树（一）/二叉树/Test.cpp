#include "Tree.h"
#include "Queue.h"

void Test()
{
    BTNode* A = (BTNode*)malloc(sizeof(BTNode));
    A->data = 'A';
    A->left = NULL;
    A->right = NULL;

    BTNode* B = (BTNode*)malloc(sizeof(BTNode));
    B->data = 'B';
    B->left = NULL;
    B->right = NULL;

    BTNode* C = (BTNode*)malloc(sizeof(BTNode));
    C->data = 'C';
    C->left = NULL;
    C->right = NULL;


    BTNode* D = (BTNode*)malloc(sizeof(BTNode));
    D->data = 'D';
    D->left = NULL;
    D->right = NULL;


    BTNode* E = (BTNode*)malloc(sizeof(BTNode));
    E->data = 'E';
    E->left = NULL;
    E->right = NULL;

    A->left = B;
    B->left = D;
    B->right = E;
    A->right = C;


    PrevOrder( A);
    printf("\n");

    InOrder(A);
    printf("\n");

    PostOrder(A);
    printf("\n");
    
    printf("%d\n", TreeSize(A));
    printf("%d\n", TreeSize(B));
    printf("%d\n", TreeLeafSize(A));
    printf("%d\n", TreeLeafSize(B));
   
    LevelOrder(A);

}

int main()
{

    Test();

    return 0;

}  