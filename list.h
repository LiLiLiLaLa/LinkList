#ifndef __LIST_H__
#define __LIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode, *pList;


void InitList(pList* pplist);//初始化链表
pNode BuyNode(DataType d);//申请新结点
void PushBack(pList* pplist, DataType d);//尾插
void PrintList(pList plist);//打印链表
void DestoryList(pList* pplist);//销毁链表
int GetListLength(pList plist);//得到链表的长度
void PopBack(pList* pplist);//尾删
void PushFront(pList* pplist, DataType d);//尾插
void PopFront(pList* pplist);//头删
pNode Find(pList plist, DataType d);//查找指定元素
void Insert(pList* pplist, pNode pos, DataType d);//指定位置之前插入指定值
void Erase(pList* pplist, pNode pos);//删除指定位置的结点
void Remove(pList* pplist, DataType d);//删除链表中出现的第一个指定元素
void RemoveAll(pList* pplist, DataType d);//删除链表中出现的所有指定元素

#endif//__LIST_H__