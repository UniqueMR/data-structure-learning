#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

//定义链表结点类型，包含数据域和指针域
typedef struct _LNode
{
    Elemtype data;
    struct _LNode *next;
}LNode;

//定义链表类型，包含链表头指针（不存储结点）和链表长度
typedef struct
{
    LNode *head;
    int length;
}LinkedList;

//对链表进行插入排序，输入链表L，返回链表L
LinkedList InsertSort(LinkedList L)
{
    //p指针指向下一次需要插入的元素
    //pre指针指向已经排序好序列的末尾，也就是p的前一个结点
    //index指针用来搜索链表
    LNode *p,*index,*pre;

    int i;

    int j;

    //当长度为L.length的序列已经排序完成，标志排序过程结束
    for(i = 1;i <= L.length;i++)
    {
        //初始化所有指针为表头结点
        p = pre = index = L.head;


        //将前置指针pre移动到已经排序好序列的末尾
        for(j = 1;j <= i;j++)
        {
            pre = pre->next;
        }

        //p指针在pre的后面一个位置
        p = pre->next;

        //搜索已经排序好的前置序列
        for(j = 1;j <= i;j++)
        {
            //如果插入目标的关键值小于检索指针指向的结点，就把目标插入到检索指针前一个位置
            if(p->data < index->data)
            {
                //首先将目标结点从原来的位置上删除
                pre->next = p->next;
                //然后将目标结点插入到检索指针指向结点的前一个位置
                p->next = index->next;
                index->next = p;
            }

            //否则检索指针就继续向后移动
            else
            {
                index = index->next;
            }
        }
    }

    return L;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
