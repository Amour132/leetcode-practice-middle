#include <stdio.h>

void QuickSort(int *arr, int start, int end)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	if (start<end)
	{
		i = start + 1;
		j = end;
		while (i<j)
		{
			if (arr[i]>arr[start])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				j--;
			}
			else
			{
				i++;
			}
		}
		if (arr[i] >= arr[start])
		{
			i--;
		}
		temp = arr[i];
		arr[i] = arr[start];
		arr[start] = temp;
		QuickSort(arr, start, i);
		QuickSort(arr, j, end);
	}
}

int findDuplicate(int* nums, int numsSize) {

	QuickSort(nums, 0, numsSize - 1); //先排序
	int i = 0;
	for (i = 0; i<numsSize - 1; i++)//如果有重复的元素则返回
	{
		if (nums[i] == nums[i + 1])
		{
			return nums[i];
		}
	}
	return 0;
}

void print(int *arr, int size)
{
	int i = 0;
	printf("数组为：\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 1, 5, 3, 6, 8, 7, 9, 6 };
	print(arr, sizeof(arr) / sizeof(arr[0]));
	int ret = findDuplicate(arr, sizeof(arr) / sizeof(arr[0]));
	printf("重复的元素是： %d", ret);
	return 0;
}