#include <stdio.h>
#include <stdlib.h>

int main()
{

}

void OutputLinkedList(XorLinkedList &L,char d)//�������ָ��˫�����Լ�ѡ��ķ���
{
    XorPointer p,temp;//pΪ����ָ��
    XorPointer left,right;//left��right�ֱ�ָ��p��������Ҳ࣬������ʼ��

    if(d == 'l')//ѡ��ķ���Ϊ��
    {
        p = L.Left;//����ָ��ָ����������
        left = NULL;
        while(XorP(left,p->LRPtr)!= NULL)//p����һ����㲻Ϊ�յ�ʱ��
        {
            temp = p;//����p���ƶ���Ҫ����ԭ����left����left���ƶ�����Ҫԭ����p��p��left������Ϲ�ϵ������������м����temp,��ȥ��p��left�����Ϲ�ϵ
            p = XorP(left,p->LRPtr);//p�����ƶ�һλ
            left = temp;//left�ƶ���pԭ����λ��
            printf("%d",p->data);//�˴�������Ϊ������dataΪ�����������ͣ�%d����Ӧ�ĵ���
        }
    }

    else//ѡ��ķ���Ϊ�Ҳ��ʱ��ԭ���ͬС��
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

void InsertLinkedList(XorLinkedList &L,int i,XorPointer q)//���뿪�ٽ���λ�ã�Ĭ�ϴ����ң���ָ�򿪱ٽ���ָ��q
{
    if(i<1)
    {
        printf("����λ�ó���");
        exit(1);//�쳣�˳�
    }

    q = (XorPointer)malloc(XorNode);//Ϊָ�򿪱ٽ���ָ�뿪���ڴ�ռ�

    XorPointer p,temp;//pΪ����ָ��
    XorPointer left;//leftָ��p����࣬������ʼ��

    p = L.Left;//����ָ��ָ����������
    left = NULL;

    int j;//j��Ϊ�ƶ��Ʋ���

    for(j=0;j<i;j++)//��ͷָ��L.Left��ʼ�����ƶ�i�Σ��ƶ���ɺ�pָ���i����㣬leftָ���i������ǰһ�����
    {
        temp = p;//����p���ƶ���Ҫ����ԭ����left����left���ƶ�����Ҫԭ����p��p��left������Ϲ�ϵ������������м����temp,��ȥ��p��left�����Ϲ�ϵ
        p = XorP(left,p->LRPtr);//p�����ƶ�һλ
        left = temp;//left�ƶ���pԭ����λ��
    }

    q->LRPtr = XorP(left,p);//q��LRPtr��Ϊleft��p�����ʹ��q��Ϊleft��p֮��Ľ�㣬�Ӷ�ʵ����q�Ĳ���

    printf("����ɹ���");
}
