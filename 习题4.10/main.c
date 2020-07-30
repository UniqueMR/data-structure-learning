#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

//对串求逆函数
StringType Reverse(String s)
{
    StringType t;

    int len;

    //求s的长度
    len = StrLength(s);

    //如果长度为1，即串中只有一个元素，则逆串和串相同
    if(len == 1)
    {
        return s;
    }

    //如果长度不为1，则将串中的最后一个元素取出来，和前面已经取逆的串互换位置
    else
    {
        //取出串中的最后一个元素到t中
        t = SubString(s,len,1);
        //将t和已经取逆的串连接起来，已经取逆的串通过调用自身得到
        return Concat(t,Reverse(SubString(s,1,len-1)));
    }
}
