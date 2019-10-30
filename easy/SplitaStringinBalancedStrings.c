#include <stdio.h>

int balancedStringSplit(char * s)
{
    int count=0;
    int i=0;

    while(s[i])
    {
        if (s[i] == 'L')
            count++;
        else
            count--;
        i++;
    }

    printf("i:%d\n", i);

    if (!count)
        printf("TRUE\n");
    else
        printf("FALSE\n");
    
    return count;
}

void main(void)
{
    char A[]="RLLLLRRRRL";
    int ret;
    
    ret = balancedStringSplit(A);

    printf("ret:%d\n", ret);
}
