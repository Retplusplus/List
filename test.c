#include<stdio.h>
#include"seqlist.h"
#include<assert.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

void SeqListInit(PSeqList ps, int capacity)
{
	assert(ps);
	ps->_pData = (DataType*)malloc(sizeof(DataType)*capacity);
	if (NULL == ps->_pData)
	{
		exit(1);
	}
	ps->_capacity = capacity;
	ps->_size = 0;
}

void SeqListPushBack(PSeqList ps, DataType data)//尾部插入元素
{
	ps->_pData[ps->_size++] = data;
}

void SeqListPopBack(PSeqList ps)//尾部删除元素
{
	assert(ps);
	if (ps->_size)
	{
		ps->_size--;
	}
}

void SeqListPushFront(PSeqList ps,DataType data)//首部插入元素
{
	assert(ps);
	for (int i = ps->_size; i > 0; i--)
	{
		ps->_pData[i] = ps->_pData[i - 1];
	}
	ps->_size++;
	ps->_pData[0] = data;

}

void SeqListPopFront(PSeqList ps)//删除头部元素
{
	assert(ps);
	if (0 == ps->_size)
	{
		return;
	}
	for (int i = 0; i < ps->_size - 1; i++)
	{
		ps->_pData[i] = ps->_pData[i + 1];
	}
	ps->_size--;
}

void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	assert(ps);
	if (pos<0 || pos>ps->_size)
	{
		return;
	}
	for (int i = ps->_size - 1; i >= pos; i--)
	{
		ps->_pData[i + 1] = ps->_pData[i];
	}
	ps->_pData[pos] = data;
	ps->_size++;
}

void SeqListEraser(PSeqList ps, int pos)
{
	assert(ps);
	if (pos < 0 || pos >= ps->_size)
	{
		printf("删除位置有问题 \n");
		return;
	}
	for (int i = pos + 1; i < ps->_size; ++i)
	{
		ps->_pData[i - 1] = ps->_pData[i];
	}
	ps->_size--;
}

int SeqListFind(PSeqList ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_pData[i] == data)
			return i;
	}
	return -1;
}

void SeqListRemove(PSeqList ps, DataType data)
{
	int pos = SeqListFind(ps, data);
	SeqListEraser(ps, pos);
}

int SeqListSize(PSeqList ps)
{
	assert(ps);
	return ps->_size;
}

int SeqListCapacity(PSeqList ps)
{
	assert(ps);
	return ps->_capacity;
}

//获取顺序表的第一个元素
DataType SeqLisrFront(PSeqList ps)
{
	assert(ps);
	return ps->_pData[0];
}


//获取顺序表最后一个元素
DataType SeqListBack(PSeqList ps)
{
	assert(ps);
	return ps->_pData[ps->_size-1];
}

void SeqListClear(PSeqList ps)//清空所有有效数字
{
	assert(ps);
	ps->_size = 0;
}

void SeqListDestroy(PSeqList ps)//销毁顺序表
{
	assert(ps);
	if (ps->_pData)
	{
		free(ps->_pData);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}


// 用冒泡排序的方式对顺序表中的元素进行排序 
void BubbleSort(PSeqList ps)
{
	assert(ps);
	int tmp = 0;
	for (int i = 0; i < ps->_size-1; i++)
	{
		for (int j = 0; j <ps->_size-1-i; j++)
		{
			if (ps->_pData[j] > ps->_pData[j + 1])
			{
				tmp = ps->_pData[i];
				ps->_pData[i] = ps->_pData[i + 1];
				ps->_pData[i + 1] = tmp;
			}
		}
	}

}


void printsreqlist(PSeqList ps)//打印
{
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_pData[i]);
	}
	printf("\n");
}

int main()
{
	return 0;
}