#include <stdio.h>
#include <stdlib.h>

int main()
{

}

void OutputLinkedList(XorLinkedList &L,char d)//输入异或指针双链表以及选择的方向
{
    XorPointer p,temp;//p为检索指针
    XorPointer left,right;//left和right分别指向p的左侧与右侧，在随后初始化

    if(d == 'l')//选择的方向为左
    {
        p = L.Left;//检索指针指向链表的左端
        left = NULL;
        while(XorP(left,p->LRPtr)!= NULL)//p的右一个结点不为空的时候
        {
            temp = p;//由于p的移动需要依靠原来的left，而left的移动又需要原来的p（p和left存在耦合关系），因此引入中间变量temp,来去除p和left间的耦合关系
            p = XorP(left,p->LRPtr);//p向右移动一位
            left = temp;//left移动到p原来的位置
            printf("%d",p->data);//此处以整形为例，若data为其它数据类型，%d做相应的调整
        }
    }

    else//选择的方向为右侧的时候，原理大同小异
    {
        p = L.Right;
        right = NULL;
        while(XorP(p->LRPtr,right) != NULL)
        {
            temp = p;
            p = XorP(p->LRPtr,right);
            right = temp;
            printf("%d",p->data);
        }
    }
}

void InsertLinkedList(XorLinkedList &L,int i,XorPointer q)//输入开辟结点的位置（默认从左到右）和指向开辟结点的指针q
{
    if(i<1)
    {
        printf("输入位置出错！");
        exit(1);//异常退出
    }

    q = (XorPointer)malloc(XorNode);//为指向开辟结点的指针开辟内存空间

    XorPointer p,temp;//p为检索指针
    XorPointer left;//left指向p的左侧，在随后初始化

    p = L.Left;//检索指针指向链表的左端
    left = NULL;

    int j;//j作为移动计步器

    for(j=0;j<i;j++)//从头指针L.Left开始向右移动i次，移动完成后p指向第i个结点，left指向第i个结点的前一个结点
    {
        temp = p;//由于p的移动需要依靠原来的left，而left的移动又需要原来的p（p和left存在耦合关系），因此引入中间变量temp,来去除p和left间的耦合关系
        p = XorP(left,p->LRPtr);//p向右移动一位
        left = temp;//left移动到p原来的位置
    }

    q->LRPtr = XorP(left,p);//q的LRPtr域为left和p的异或，使得q成为left和p之间的结点，从而实现了q的插入

    printf("插入成功！");
}
