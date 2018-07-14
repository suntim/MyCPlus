#include<stdio.h>


void QuikSort(int *arr,int len)
{
	int index;
	for (int i = 0; i < len - 1; i++)
	{
		
		index = i;
		for (int j = i+1; j < len; j++)
		{
			if (arr[index] > arr[j])
			{
				printf("[%d]", i);
				index = j;
			}
		}
		//int tmp = arr[i];
		//arr[i] = arr[index];
		//arr[index] = tmp;

		if (i != index)
		{
			arr[index] ^= arr[i];
			arr[i] ^= arr[index];
			arr[index] ^= arr[i];
		}
		

		for (int k = 0; k < len; k++)
		{
			printf(" %d  ", arr[k]);
			
		}
		printf("\n");

	}
}

int main()
{
	int arr[10] = { 1, 2, 31, -4, 12, 56, 3, 72, 8, 86 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("sizeof = %d\n", len);
	int max_value = arr[0];
	int second_max = max_value;
	int min_value = arr[0];
	int second_min = min_value;
	for (int i = 0; i < len; i++)
	{
		if (max_value < arr[i])
		{

			second_max = max_value;
			max_value = arr[i];
		}

		if (min_value > arr[i])
		{
			second_min = min_value;
			min_value = arr[i];
		}


	}
	printf("max = %d, sencond_max = %d,min = %d, second_min = %d\n", max_value, second_max, min_value, second_min);

	QuikSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	getchar();
	return 0;
}
