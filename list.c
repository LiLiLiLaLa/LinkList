#define _CRT_SECURE_NO_WARNINGS

#include "list.h"

void InitList(pList* pplist)
{
	assert(pplist != NULL);
	*pplist = NULL;
}

pNode BuyNode(DataType d)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}

void DestoryList(pList* pplist)
{
	assert(pplist);
	pNode cur = *pplist;//cur指向第一个结点
	while (cur)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;//
}

void PushBack(pList* pplist, DataType d)
{
	pNode newNode = BuyNode(d);
	//assert
	assert(pplist);
	//有无元素
	if (*pplist == NULL)
	{
		pNode newNode = BuyNode(d);
		*pplist = newNode;
	}
	//有元素找尾（next指向空）
	else
	{
		pNode cur = *pplist;
		pNode newNode = BuyNode(d);
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void PrintList(pList plist)
{
	//无需断言plist,当plist为空时，表明这是一个空链表，也是合法的
	pNode cur = plist;
	while (cur != NULL)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("Over\n");
}

int GetListLength(pList plist)
{
	pNode cur = plist;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

void PopBack(pList* pplist)
{
	assert(pplist);
	//空链表
	if (*pplist == NULL)
	{
		return;
	}
	//一个节点
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	//多个节点
	else
	{
		pNode cur = *pplist;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void PushFront(pList* pplist, DataType d)
{
	assert(pplist);
	pNode newNode = BuyNode(d);
	newNode->next = *pplist;
	*pplist = newNode;
}

void PopFront(pList* pplist)
{
	//assert
	assert(pplist);
	//没有节点
	if (*pplist == NULL)
	{
		printf("链表为空不能头删\n");
	}
	//有节点
	else
	{
		pNode cur = *pplist;
		*pplist = cur->next;
		free(cur);
		cur = NULL;
	}
}

pNode Find(pList plist, DataType d)
{
	pNode cur = plist;
	while (cur)
	{
		if (cur->data == d)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void Insert(pList*pplist, pNode pos, DataType d)
{
	pNode newNode = NULL;
	//assert
	assert(pplist);
	assert(*pplist);
	assert(pos);
	//pos指向第一个结点采用头插
	if (pos == *pplist)
	{
		newNode = BuyNode(d);
		newNode->next = *pplist;
		*pplist = newNode;
	}
	//pos不是第一个节点：pos合法，pos不合法
	else
	{
		pNode cur = *pplist;
		while (cur&&cur->next != pos)
		{
			cur = cur->next;
		}
		if (cur)
		{
			newNode = BuyNode(d);
			cur->next = newNode;
			newNode->next = pos;
		}
		
	}
}

void Erase(pList* pplist, pNode pos)
{
	assert(pplist);
	assert(pos);
	//判空
	if (*pplist == NULL)//
	{
		return;
	}
	//pos是指向第一个结点，头删
	if (*pplist == pos)
	{
		//头删
		pNode del = pos;
		*pplist = (*pplist)->next;
		free(del);
		del = NULL;
	}
	//pos不是第一个结点：pos合法，pos不合法
	else
	{
		pNode cur = *pplist;
		while (cur&&cur->next != pos)
		{
			cur = cur->next;
		}
		if (cur)
		{
			cur->next = pos->next;
			free(pos);
			pos = NULL;
		}
	}
}

void Remove(pList* pplist, DataType d)
{
	pNode cur = NULL;
	pNode prev = NULL;
	assert(pplist);
	assert(*pplist);
	cur = *pplist;
	while (cur)
	{
		if (cur->data == d)
		{
			//是第一个结点
			if (*pplist == cur)
			{
				PopFront(pplist);
			}
			//不是第一个结点
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = NULL;
			}
			return;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

void RemoveAll(pList* pplist, DataType d)
{
	pNode cur = NULL;
	pNode prev = NULL;
	assert(pplist);
	assert(*pplist);
	cur = *pplist;
	while (cur)
	{
		if (cur->data == d)
		{
			//是第一个结点
			if (*pplist == cur)
			{
				PopFront(pplist);
				cur = *pplist;
			}
			//不是第一个结点
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}