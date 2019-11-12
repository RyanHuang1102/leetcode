#include <stdio.h>
static int hammingDistance(int x, int y)
{
    int count=0;
    int Input=x^y;
    
    while(Input)
    {
        if(Input & 1)
        {
            ++count;
        }
        Input>>=1;

    }

    return count;

}


int main()
{
    int x=2, y=4;
    int ret;

    ret = hammingDistance(x,y);
    printf("%d\n", ret);
}
