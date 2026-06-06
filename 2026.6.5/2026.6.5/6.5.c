/*                                     字符指针              */
/*
* char* p="abcdef"   把字符串首字符a的地址赋值给p
*/
#include <stdio.h>
//int main()
//{
//	const char* p1 = "abcdef";//"abcdef"为常量字符串，存放在内存中的只读区
//	const char* p2 = "abcdef";
//
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//
//	if (p1 == p2) { printf("p1=p2\n"); }
//	else
//		printf("p1!=p2\n");
//	if (arr1 == arr2) { printf("arr1=arr2\n"); }
//	else
//		printf("arr1!=arr2\n");
//	return 0;
//}


/*                                       指针数组              */
//指针数组：用来存放指针的数组
/*
int* arr[]  存放整形指针的数组
char arr1[]  存放字符指针的数组



*/
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[3] = { arr1,arr2,arr3 };  //模拟了一个二维数组
//
//	return 0;
//}

/*                                          数组指针             */
/*
数组指针：指向数组的指针
int* p1[10]  p1是指针数组
int(*p2)[10] p2是数组指针，p2指向一个数组，该数组有十个元素，每个元素是int类型

数组名通常都表示数组首元素的地址，但有两个例外
1.sizeof（数组名）只能有单独的数组名，不能有其他东西，这里计算的是整个数组的大小
2.&数组名，这里的数组名表示的是整个数组，所以&数组名 取出的是整个数组的地址

int (*p2)[10]=&arr;
*/
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[sizeof(arr)/sizeof(arr[0])] = &arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(*p + i));       //p是指向数组的，*p其实就相当于数组名，数组名又是数组首元素的地址
//	}
//	return 0;
//}

//上述用法不常用，数组指针通常用在二维数组
void print1(int(*p)[5], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}
//int main()
//{
//
//	int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };  //二维数组的首元素是第一行
//	print1(arr, 3, 5);
//
//
//	return 0;
//}
/*                         数组传参    */
//二维数组传参时行可以省略，列不能省略
//二维数组的数组名，表示的是首元素的地址，是第一行的地址