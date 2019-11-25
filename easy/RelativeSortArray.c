#include <stdio.h>
#include <stdlib.h>

int* relativeSortArray(int* arr1, int sizearr1, int* order, int sizeorder, int *retSize)
{
	int *ret = calloc(sizearr1, sizeof(int));
	int *mem = calloc(1024, sizeof(int));
	int i = 0;


	while(i < sizearr1)
	{
		mem[arr1[i]]++;
		i++;
	}
	i = 0;
	int j;

	while (i < sizeorder)
	{
		//printf("i:%d\n", i);
		int tmp;
		tmp = mem[order[i]];

		for (j = 0;j < tmp; j++)
		{
			//printf("retSize:%d\n", *retSize);
			ret[*retSize] = order[i];
			++*retSize;
		}
		i++;
	}

	free(mem);
	return ret;
}

void main()
{
	int arr[]={2,3,1,3,2,4,6,7,9,2,19};
	int sizearr1 = sizeof(arr)/sizeof(int);
//	printf("sizearr1:%d\n", sizearr1);
	int order[]={2,1,4,3,9,6,5};
	int sizeorder = sizeof(order)/sizeof(int);
//	printf("sizeorder:%d\n", sizeorder);
	int *ret;
	int retSize = 0;

	ret = relativeSortArray(arr, sizearr1, order, sizeorder, &retSize);

	for (int j = 0; j < retSize; j++)
	{
		printf("%d ", ret[j]);
	}
	printf("\n");
	printf("retSize:%d",retSize);
	
	free(ret);
}
