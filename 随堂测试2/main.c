#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char *s1;
    const char *s2;

//    *s1 = 'c';
//    *s2 = 'c';

    s1 = 10086;
    s2 = 10087;

//    *s1 = 'c';
//    *s2 = 'd';

    printf("%d%d",*(unsigned char*)s1,*(unsigned char*)s2);

    return 0;
}
