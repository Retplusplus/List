#pragma once

typedef int DataType;
//��̬˳���Ľṹ 
typedef struct SeqList
{
	DataType* _pData;
	int _capacity;
	int _size;
}SeqList,*PSeqList;

void SeqListInit(PSeqList ps, int capacity);

//��˳���β������Ԫ��data
void SeqListPushBack(PSeqList ps,DataType data);

//ɾ��β��Ԫ��data
void SeqListPopBack(PSeqList ps);

//��˳����ͷ������Ԫ��
void SeqListPushFront(PSeqList ps, DataType data);

//ɾ��˳���ͷ��Ԫ��
void SeqListPopFront(PSeqList ps);

//��˳����posλ�ò���Ԫ��data
void SeqListInsert(PSeqList pa, int pos, DataType data);

//ɾ��˳���posλ�õ�Ԫ��
void SeqListEraser(PSeqList ps, int pos);

//��˳������ҵ�dataԪ�ص�һ�γ��ֵ�λ��
int SeqListFind(PSeqList ps, DataType data);

//ɾ��˳�����ֵΪdata��Ԫ��
void SeqListRemove(PSeqList ps, DataType data);

//��ȡ˳�������ЧԪ�ظ���
int SeqListSize(PSeqList ps);

//��ȡ˳��������
int SeqListCapacity(PSeqList ps);

//��ȡ˳���ĵ�һ��Ԫ��
DataType SeqLisrFront(PSeqList ps);

//��ȡ˳������һ��Ԫ��
DataType SeqListBack(PSeqList ps);

//���˳�������ЧԪ�ظ���
void SeqListClear(PSeqList ps);

//����˳���
void SeqListDestroy(PSeqList ps);

// ��ð������ķ�ʽ��˳����е�Ԫ�ؽ������� 
void BubbleSort(PSeqList ps);


