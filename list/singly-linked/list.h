#ifndef _LIST_H_
#define _LIST_H_



#include <stdlib.h>   /* malloc() */

typedef	int	Status;
#define true	1
#define false	0

typedef struct elemType /*数据结构体*/
{
	unsigned int IP;	
}ElemType;

typedef struct lNode /*结点结构体*/
{
	ElemType data;
	struct lNode *next;
}LNode;

LNode* InitList();
Status DestoryList(LNode *head);
Status ClearList(LNode *head);
Status ListEmpty(LNode *head);
Status GetElem(LNode *head, int i, ElemType *e);
Status PriorElem(LNode *head,ElemType cur_e, ElemType *pre_e);
Status NextElem(LNode *head, ElemType cur_e, ElemType *next_e);
Status ListInsert(LNode *head, int i, ElemType e);
Status ListDelete(LNode *head, int i, ElemType *e);
Status ListTraverse(LNode *head,void(*vi)(ElemType));
unsigned int LocateElem(LNode *head, ElemType e, Status(*compare)(ElemType,ElemType));
unsigned int ListLength(LNode *head);
unsigned int ListAdd(LNode *head,ElemType e);

void vi(ElemType e);
Status CompareElem(ElemType e1,ElemType e2);
#endif
