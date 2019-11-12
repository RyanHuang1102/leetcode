#include <stdio.h>

static int findComplement(int num)
{
    int i = 1 ;
    for (; i < num; i*=2)
    {
        num ^= i;
        /*
          100 ^ 001 = 101
          101 ^ 010 = 111
          111 ^ 100 = 011

        */
    }

    return num;
}


int main()
{
    int num = 4;
    int ret;

    ret = findComplement(num);

    printf("ret:%d\n", ret);
}
