#include "Tree.h"
#include "Queue.h"

void PrevOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }

    printf("%c ", root->data);

    PrevOrder(root->left);
    PrevOrder(root->right);

}


void InOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }

    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);

}

void PostOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ", root->data);
}

int TreeSize(BTNode* root)
{
     
    return root==NULL?0:TreeSize(root->left)+TreeSize(root->right)+1;


}
 
//求叶子个数
int TreeLeafSize(BTNode* root)
{

    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) 
    {
        return 1;  
    }


    return TreeLeafSize(root->left) + TreeLeafSize(root->right); 

}


void LevelOrder(BTNode* root)
{
  
    //思路：上一层带下一层
    Queue q;
    QueueInit(&q);

    if (root != NULL)
    {
        QueuePush(&q, root);
    }

    while (!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);
        

        if (front->left != NULL)
        {
            QueuePush(&q, front->left);
        }

        if (front->right != NULL)
        {
            QueuePush(&q, front->right);
        }

        printf("%c ", front->data);

    }

}



