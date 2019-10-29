#include <stdio.h>
#include <stdlib.h>

int maxIncreaseKeepingSkyline(int (*grid)[4], int gridRowSize, int gridColSize)
{
    int i, j;
    int *top_bottom;
    int *left_right;
    top_bottom = calloc(gridRowSize, sizeof(int));
    left_right = calloc(gridColSize, sizeof(int));
    int ret = 0;

    for (i = 0; i < gridRowSize; i++)
    {
        for (j = 0; j < gridColSize; j++)
        {
            if (left_right[i] < grid[i][j])
                left_right[i] = grid[i][j];
        }
        //printf("%d ",left_right[i]);
    }
    //printf("\n");

    for (i = 0; i < gridColSize; i++)
    {
        for (j = 0; j < gridRowSize; j++)
        {
            if (top_bottom[i] < grid[j][i])
                top_bottom[i] = grid[j][i];
        }
        //printf("%d ", top_bottom[i]);
    }
    
    for (i = 0; i < gridRowSize; i++)
    {
        for (j = 0; j < gridColSize; j++)
        {
            ret+=(left_right[i] < top_bottom[j]?left_right[i]:top_bottom[j])-grid[i][j];
        }
    }

    free(top_bottom);
    free(left_right);
    return ret;
}



void main(void)
{
    int a[][4]= {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    int colum = sizeof(a)/sizeof(a[0]);
    int row = sizeof(a[0])/sizeof(int);

    int ret = 0;

    ret = maxIncreaseKeepingSkyline(a, row, colum);

    printf("ret:%d\n", ret);

    //printf("colum:%d\nrow:%d\n", colum, row);

}
