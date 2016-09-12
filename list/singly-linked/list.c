

#include "list.h"

/*
*分别比较ElemType的每一个数据项
*操作结果:如果两个ElemType相等，返回true,否则返回false。
*/
Status CompareElem(ElemType e1,ElemType e2)
{
	if(e1.IP==e2.IP)
	{
		/*依次比较每一项
		if()
		{
			if()
			{
				if()
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		*/
		return true;
	}
	else
	{
		return false;
	}
}

/*
*对链表中的每个结点中的数据元素进行vi()操作。
*
*下面示例打印每个数据。
*/
void vi(ElemType e)
{
	printf("e.IP:%d\n",e.IP);
}


/*
*构建一个空的线性表,返回头结点的位置。
*/
LNode *InitList()
{
	LNode *head;
	head = ( LNode * )malloc( sizeof( LNode ) );/*产生头结点，并使L指向此头结点*/
	if( !head )/*存储分配失败*/
	{
		return false;
	}
	else
	{
		printf("头结点位置：%lu\n",head);
		head->next = NULL;/*指针为空，此时线性表中只有头结点一个*/
		return head;
	}
}

/*
*初始条件：线性表已经存在。
*操作结果：销毁线性表。
*参数：线性链表的头结点
*/
Status DestroyList(LNode *head)
{
	LNode *q;
	while(head)
	{
		q = head->next;
		free(head);
		head = q;
	}
	return true;
}
/*
*初始条件：线性表已经存在。
*操作结果：清空表，表头还在。
*参数：线性链表的头结点。
*/
Status ClearList(LNode *head)
{
	LNode *p;
	LNode *q;
	p = head->next;/*指向第一个结点*/
	while(p)/*没有到尾结点*/
	{
		q = p->next;
		free(p);
		p = q ;
	}
	head->next = NULL;/*头结点指针指向空*/
	return true;
}
/*
*初始条件：线性表L已经存在。
*操作结果：若L为空表，返回true，否则返回false。
*参数：线性链表的头结点。
*/
Status ListEmpty(LNode *head)
{
	if(head->next)/*非空*/
	{
		return false;
	}
	else
	{
		return true;
	}
}
/*
*初始条件：线性表L已经存在
*操作结果：返回表中元素个数
*参数：head线性链表的头结点
*/
unsigned int ListLength(LNode *head)
{
	int i=0;
	LNode *p;
	p = head->next;/*P指向第一个结点*/
	while(p)/*没有到表尾*/
	{
		i++;
		p = p->next;
	}
	return i;
}
/*
*L为带头结点的但练表的头指针，当第i个元素存在时，
*将其赋值给(*e),并返回true,否则返回false.
*参数：head线性链表的头结点，i结点位置（不算头结点），e返回结果。
*/
Status GetElem(LNode *head, int i, ElemType *e)
{
	int j=1;
	LNode *p;
	p = head->next;/*p指向第一个结点*/
	while(p && j<i)/*顺着指针向下查找，直到P指向第i个元素或p为空*/
	{
		p = p->next;
		j++;
	}
	if(!(p) || j>i)/*第i个元素不存在*/
	{
		return false;
	}
	else
	{
		*e = p->data;/*取第i个元素*/
		return true;
	}
}

/*
*初始条件：线性表L存在，compare()是数据元素判定函数，(满足为1，否则为0)。
*操作结果：返回L中第一个与e满足compare()的数据元素的位序。
*若这样的元素不存在，则返回0.
*/
unsigned int LocateElem(LNode *head, ElemType e, Status(*CompareElem)(ElemType,ElemType) )
{
	int i = 0;
	LNode *p;
	p = head->next;
	while( p )
	{
		i++;
		if( CompareElem( (p->data), e ) )/*找到这样的数据*/
		{
			return i;
		}
		else 
		{
			p = p->next;
		}
	}
	return 0;
}
/*
*初始条件：线性表存在
*操作结果：若cur_e是线性表中的元素，且不是第一个，则用(*pre_e)返回它的前驱，返回true;否则操作失败，(*pre_e)无定义，返回false。
*/
Status PriorElem(LNode *head,ElemType cur_e, ElemType *pre_e)
{
	LNode *q;
	LNode *p;
	p = head->next;/*p指向第一个结点*/
	while(p->next)/*p所指结点有后继*/
	{
		q=p->next;/* q为p的后继 */
		if(CompareElem(q->data,cur_e))
		{
			*pre_e = p->data;
			return true;
		}
		else
		{
			*p = *q;/*p向后移*/
		}
	}
	return false;
}

/*
*初始条件：线性表L已经存在
*操作结果：若cur_e是L的数据元素，且不是最后一个，则用(*next_e)返回它的后继，返回true；否则操作失败，(*next_e)无定义，返回false。
*/
Status NextElem(LNode *head, ElemType cur_e, ElemType *next_e)
{
	LNode *p;
	p = head->next;/*指向第一个结点*/
	while(p->next)/*p所指结点有后继*/
	{
		if(CompareElem(p->data,cur_e))
		{
			*next_e = p->next->data;
			return true;
		}
		else
		{
			p = p->next;
		}
	}
	return false;
}

/*
*初始条件：线性表L存在
*操作结果：在带头结点的线性表L中的第i个位置之后插入元素e。
*/
Status ListInsert(LNode *head, int i, ElemType e)
{
	int j = 0;
	LNode *p;
	LNode *s;
	p = head->next;/*移动到第一个结点*/
	while(p && j<i-1)/*寻找第i-1个结点*/
	{
		p = p->next;
		j++;
	}
	if(!p || j>i-1)/*大于表长 或者 i小于1*/
	{
		return false;
	}
	else
	{
		s = (LNode *)malloc( sizeof(LNode) );/*生成新结点*/
		s->data = e;/*插入到线性表L中*/
		s->next = p->next;
		p->next = s;
		return true;
	}
}


/*
*初始条件：线性链表L存在
*操作结果：从表L中删除第i个元素，并由e返回其值
*/
Status ListDelete(LNode *head, int i, ElemType *e)
{
	int j = 0;
	LNode *p;
	LNode *q;
	p = head;
	while(p->next && j<i-1)
	{
		p = p->next;
		j++;
	}
	if( !(p->next) || j>i-1 )/*删除位置不合理*/
	{
		return false;
	}
	else
	{
		q = p->next;/*删除并释放结点*/
		p->next = q->next;
		*e = q->data;
		free(q);
		return true;
	}
}

/*
*函数vi()的形参类型为ElemType
*初始条件：线性链表L已经存在
*操作结果：依次对表L中的每个元素调用函数vi()。一旦vi()失败，则操作失败
*/
Status ListTraverse(LNode *head, void(*vi)(ElemType))
{
	LNode *p;
	p = head->next;
	while(p)
	{
		vi(p->data);
		p = p->next;
	}
	return true;
}

/*
*初始条件：线性链表head存在
*操作结果：将e插入到链表末尾，并且返回插入后的表长，操作失败，返回0
*/
unsigned int ListAdd(LNode *head, ElemType e)
{
	LNode *p;
	LNode *m;
	LNode *q;
	int i = 0;
	p = head->next;
	while(p)
	{
		i++;
		m = p;
		p = p->next;
	}
	q = (LNode *)malloc( sizeof(LNode) );
	if(!q)
	{
		return 0;
	}
	else
	{
		q->data = e;
		if(i==0)/*说明原来是一张空的链表，只有表头*/
		{
			head->next = q;
		}
		else
		{
			m->next = q;
		}
		return i+1;
	}
}













































