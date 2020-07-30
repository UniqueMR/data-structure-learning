#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int main()
{
    char *text[MAXSIZE];

    int i = 0;

    int size;

    while(getchar() != '\n')
    {
        text[i] = (char*)malloc(MAXSIZE*sizeof(char));
        scanf("%s",text[i]);
        i++;
    }

    size = i;

    for(i = 0;i < size;i++)
    {
        if(*text[i] == '@')
        {
            printf("yes!");
        }
    }

    return 0;
}
