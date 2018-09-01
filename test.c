#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

void test()
{
	Node* plist = NULL;//pList plist = NULL;
	InitList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PrintList(plist);
	printf("链表的长度是：%d\n", GetListLength(plist));
	DestoryList(&plist);
	printf("链表的长度是：%d\n", GetListLength(plist));
	PrintList(plist);
}

void TestPopBack()
{
	Node* plist = NULL;//pList plist = NULL;
	//InitList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PrintList(plist);
	PopBack(&plist);
	PrintList(plist);//1 2 3
	DestoryList(&plist);
}

void TestPushFront()
{
	Node* plist = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);//4 3 2 1
	PopFront(&plist);
	PrintList(plist);//3 2 1
	PopFront(&plist);
	PrintList(plist);//2 1
	DestoryList(&plist);
}

void TestFind()
{
	Node* plist = NULL;
	pNode pos = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);//4 3 2 1
	pos = Find(plist, 3);
	if (pos)
	{
		printf("%d\n", pos->data);
	}
	DestoryList(&plist);
}

void TestInsert()
{
	Node* plist = NULL;
	pNode pos = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);//4 3 2 1
	pos = Find(plist, 1);
	if (pos)
	{
		Insert(&plist, pos, 5);
	}
	PrintList(plist);
	DestoryList(&plist);
}

void TestErase()
{
	Node* plist = NULL;
	pNode pos = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintList(plist);//4 3 2 1
	pos = Find(plist, 1);
	if (pos)
	{
		Erase(&plist, pos);
	}
	PrintList(plist);
	DestoryList(&plist);
}

void TestRemove()
{
	Node* plist = NULL;
	pNode pos = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 2);
	PushFront(&plist, 4);
	PrintList(plist);
	Remove(&plist, 2);
	PrintList(plist);
}

void TestRemoveAll()
{
	Node* plist = NULL;
	pNode pos = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 2);
	PushFront(&plist, 4);
	PrintList(plist);
	RemoveAll(&plist, 2);
	PrintList(plist);
}

int main(void)
{
	//test();
	//TestPopBack();
	//TestPushFront();
	//TestFind();
	//TestInsert();
	//TestErase();
	//TestRemove();
	TestRemoveAll();
	system("pause");
	return 0;
}