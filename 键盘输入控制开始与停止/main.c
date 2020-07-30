#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[100];
    int i,length;
    char key;

    i = 0;
    length = 0;
    key = getchar();
    printf("%c",key);

    while(key != '\n')
    {
        scanf("%d",&nums[i]);
        length++;
        i++;
        key = getchar();
    }

    for(i=0;i<length;i++)
    {
        printf("%d\t",nums[i]);
    }

    return 0;
}
