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
	pNode cur = *pplist;//curָ���һ�����
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
	//����Ԫ��
	if (*pplist == NULL)
	{
		pNode newNode = BuyNode(d);
		*pplist = newNode;
	}
	//��Ԫ����β��nextָ��գ�
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
	//�������plist,��plistΪ��ʱ����������һ��������Ҳ�ǺϷ���
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
	//������
	if (*pplist == NULL)
	{
		return;
	}
	//һ���ڵ�
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	//����ڵ�
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
	//û�нڵ�
	if (*pplist == NULL)
	{
		printf("����Ϊ�ղ���ͷɾ\n");
	}
	//�нڵ�
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
	//posָ���һ��������ͷ��
	if (pos == *pplist)
	{
		newNode = BuyNode(d);
		newNode->next = *pplist;
		*pplist = newNode;
	}
	//pos���ǵ�һ���ڵ㣺pos�Ϸ���pos���Ϸ�
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
	//�п�
	if (*pplist == NULL)//
	{
		return;
	}
	//pos��ָ���һ����㣬ͷɾ
	if (*pplist == pos)
	{
		//ͷɾ
		pNode del = pos;
		*pplist = (*pplist)->next;
		free(del);
		del = NULL;
	}
	//pos���ǵ�һ����㣺pos�Ϸ���pos���Ϸ�
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
			//�ǵ�һ�����
			if (*pplist == cur)
			{
				PopFront(pplist);
			}
			//���ǵ�һ�����
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
			//�ǵ�һ�����
			if (*pplist == cur)
			{
				PopFront(pplist);
				cur = *pplist;
			}
			//���ǵ�һ�����
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