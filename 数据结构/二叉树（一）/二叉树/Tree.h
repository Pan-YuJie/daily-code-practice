#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
 

typedef char BTDataType;

struct BinaryTreeNode;

typedef struct BinaryTreeNode
{
    BTDataType data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;


}BTNode;


//前中后序遍历 <---> 深度优先遍历
void PrevOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
int TreeSize(BTNode* root);
int TreeLeafSize(BTNode* root);

//层序遍历 <--> 广度优先遍历
void LevelOrder(BTNode* root);
