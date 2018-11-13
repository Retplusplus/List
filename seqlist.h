#pragma once

typedef int DataType;
//动态顺序表的结构 
typedef struct SeqList
{
	DataType* _pData;
	int _capacity;
	int _size;
}SeqList,*PSeqList;

void SeqListInit(PSeqList ps, int capacity);

//在顺序表尾部插入元素data
void SeqListPushBack(PSeqList ps,DataType data);

//删除尾部元素data
void SeqListPopBack(PSeqList ps);

//在顺序表的头部插入元素
void SeqListPushFront(PSeqList ps, DataType data);

//删除顺序表头部元素
void SeqListPopFront(PSeqList ps);

//在顺序表的pos位置插入元素data
void SeqListInsert(PSeqList pa, int pos, DataType data);

//删除顺序表pos位置的元素
void SeqListEraser(PSeqList ps, int pos);

//在顺序表中找到data元素第一次出现的位置
int SeqListFind(PSeqList ps, DataType data);

//删除顺序表中值为data的元素
void SeqListRemove(PSeqList ps, DataType data);

//获取顺序表中有效元素个数
int SeqListSize(PSeqList ps);

//获取顺序表的容量
int SeqListCapacity(PSeqList ps);

//获取顺序表的第一个元素
DataType SeqLisrFront(PSeqList ps);

//获取顺序表最后一个元素
DataType SeqListBack(PSeqList ps);

//清空顺序表中有效元素个数
void SeqListClear(PSeqList ps);

//销毁顺序表
void SeqListDestroy(PSeqList ps);

// 用冒泡排序的方式对顺序表中的元素进行排序 
void BubbleSort(PSeqList ps);


