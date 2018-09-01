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


void InitList(pList* pplist);//��ʼ������
pNode BuyNode(DataType d);//�����½��
void PushBack(pList* pplist, DataType d);//β��
void PrintList(pList plist);//��ӡ����
void DestoryList(pList* pplist);//��������
int GetListLength(pList plist);//�õ�����ĳ���
void PopBack(pList* pplist);//βɾ
void PushFront(pList* pplist, DataType d);//β��
void PopFront(pList* pplist);//ͷɾ
pNode Find(pList plist, DataType d);//����ָ��Ԫ��
void Insert(pList* pplist, pNode pos, DataType d);//ָ��λ��֮ǰ����ָ��ֵ
void Erase(pList* pplist, pNode pos);//ɾ��ָ��λ�õĽ��
void Remove(pList* pplist, DataType d);//ɾ�������г��ֵĵ�һ��ָ��Ԫ��
void RemoveAll(pList* pplist, DataType d);//ɾ�������г��ֵ�����ָ��Ԫ��

#endif//__LIST_H__