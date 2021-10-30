#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//前置声明
struct BinaryTreeNode;

typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
    struct QueueNode* next;
    QDataType data;

}QNode;

typedef struct Queue
{
    QNode* head;
    QNode* tail;

}Queue;


void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

//队尾入
void QueuePush(Queue* pq,QDataType x);

//对头出
void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);
QDataType QueueBank(Queue* pq);

int  QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);



