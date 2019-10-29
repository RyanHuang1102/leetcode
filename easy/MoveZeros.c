#include <stdio.h>

void moveZeros(int* nums, int numsSize)
{
    int zero = 0 ;
    int nonzero = 0;
    for (int i = 0 ; i < numsSize ; i++)
    {
        if (nums[i] == 0)
            zero++;
        else
            nums[nonzero++] = nums[i];

    }

    if (zero)
    {
        for (int i = nonzero; i < numsSize; i++ )
        {
            nums[i] = 0;
        }
    }
    return;
}

void main()
{
    int A[5]={1,0,0,3,12};
    int size = sizeof(A)/sizeof(int);
    printf("size:%d\n", size);
    printf("A:%p\n", A);
    printf("&A[0]:%p\n", &A[0]);

    moveZeros(A, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
