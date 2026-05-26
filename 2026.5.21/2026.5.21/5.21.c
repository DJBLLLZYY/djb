#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//二分查找
//输入为arr：数组
//data:要查找的数据
//数组内元素个数
int binary_search(int arr[], int data, int num)
{
	int right = num - 1;
	int left = 0;
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] < data)
		{
			left = mid + 1;
		}
		else if (arr[mid] > data)
		{
			right = mid - 1;
		}
		else
			return mid;
	}
	return -1;
	
}
/*
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int data = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	while (1)
	{
		printf("输入：");
		scanf("%d", &data);
		int result = binary_search(arr, data, sz);
		if (result == -1)
		{
			printf("没找到\n");
		}
		else
		{
			printf("下标:%d\n", result);
		}
			
	}
	
	return 0;
}
*/

int main()
{

	return 0;
}