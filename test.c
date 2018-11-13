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

void SeqListPushBack(PSeqList ps, DataType data)//β������Ԫ��
{
	ps->_pData[ps->_size++] = data;
}

void SeqListPopBack(PSeqList ps)//β��ɾ��Ԫ��
{
	assert(ps);
	if (ps->_size)
	{
		ps->_size--;
	}
}

void SeqListPushFront(PSeqList ps,DataType data)//�ײ�����Ԫ��
{
	assert(ps);
	for (int i = ps->_size; i > 0; i--)
	{
		ps->_pData[i] = ps->_pData[i - 1];
	}
	ps->_size++;
	ps->_pData[0] = data;

}

void SeqListPopFront(PSeqList ps)//ɾ��ͷ��Ԫ��
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
		printf("ɾ��λ�������� \n");
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

//��ȡ˳���ĵ�һ��Ԫ��
DataType SeqLisrFront(PSeqList ps)
{
	assert(ps);
	return ps->_pData[0];
}


//��ȡ˳������һ��Ԫ��
DataType SeqListBack(PSeqList ps)
{
	assert(ps);
	return ps->_pData[ps->_size-1];
}

void SeqListClear(PSeqList ps)//���������Ч����
{
	assert(ps);
	ps->_size = 0;
}

void SeqListDestroy(PSeqList ps)//����˳���
{
	assert(ps);
	if (ps->_pData)
	{
		free(ps->_pData);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}


// ��ð������ķ�ʽ��˳����е�Ԫ�ؽ������� 
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


void printsreqlist(PSeqList ps)//��ӡ
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