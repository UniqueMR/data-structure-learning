#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

//�Դ����溯��
StringType Reverse(String s)
{
    StringType t;

    int len;

    //��s�ĳ���
    len = StrLength(s);

    //�������Ϊ1��������ֻ��һ��Ԫ�أ����洮�ʹ���ͬ
    if(len == 1)
    {
        return s;
    }

    //������Ȳ�Ϊ1���򽫴��е����һ��Ԫ��ȡ��������ǰ���Ѿ�ȡ��Ĵ�����λ��
    else
    {
        //ȡ�����е����һ��Ԫ�ص�t��
        t = SubString(s,len,1);
        //��t���Ѿ�ȡ��Ĵ������������Ѿ�ȡ��Ĵ�ͨ����������õ�
        return Concat(t,Reverse(SubString(s,1,len-1)));
    }
}
