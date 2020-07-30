#include <stdio.h>
#include <stdlib.h>

void DeletSame(char *s,char *t);

int main()
{
    printf("Hello world!\n");
    return 0;
}

//删除s中所有和t相同的字串
void DeletSame(char *s,char *t)
{
    int i,j,k;
    int key;
    int count;

    i = 1;
    j = 1;

    //key = 1表示搜索阶段，k = 0表示验证阶段
    key = 1;
    //count是在进入验证阶段之后，统计对应元素相同的次数
    count = 0;

    //根据串类型定义，s[0]存储串s的长度
    while(i <= s[0] - t[0] + 1)
    {
        //key = 1说明处于搜索阶段
        //如果s[i]和t的第一个元素不相同（j=1)，则继续搜索
        if(s[i] != t[j]&&key == 1)
        {
            i++;
        }

        //如果s[i]和t的第一个元素相同（j=1)，则进入验证阶段
        else
        {
            //key = 0，说明处于验证阶段
            key = 0;
            //根据串类型定义，t[0]存储串t的长度
            //j = t的长度 + 1的时候，说明t长度内所有的元素满足一一对应的关系，验证成功，可以执行删除操作
            if(j == t[0] + 1)
            {
                //此时count = t的长度t[0]
                //从i开始的所有元素前移count个位置
                for(k = i;k <= s[0];k++)
                {
                    s[k - count] = s[k];
                }
                //重置i
                i -= count;
                //重置j
                j = 1;
                //重置s的长度s[0]
                s[0] -= count;
                //重置key为1，进入搜索阶段
                key = 1;
            }
            //j != t的长度 + 1的时候，说明仍然处于验证过程中
            else
            {
                //如果对应元素相等，就继续验证
                if(s[i] == t[j])
                {
                    count++;
                    i++;
                    j++;
                }
                //如果对应元素不等，说明验证失败，重新开始搜索
                else
                {
                    //i相对于原来的位置前移一格
                    i = i - count + 1;
                    //j重置为t的起始位置
                    j = 1;
                    //key恢复为1，进入搜索阶段
                    key = 1;
                }
            }
        }

    }
}
