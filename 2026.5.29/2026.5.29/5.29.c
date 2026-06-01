
#include<stdio.h>
#include<assert.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe");
//	}
//	return 0;
//}
//程序死循环，一直打印“hehe”，arr[12]的地址与i刚好相同
//栈区内存的使用习惯是先使用高地址处的空间再使用低地址处的空间
//如果i和arr之间有适当的空间（不同的编译器不同的环境可能会有所差异），利用数组的越界操作就可能会访问到i，
//可以把i的初始化放在arr初始化后面，最好是数组别越界 

//const修饰指针变量
/*
* 
1.	const放在* 左边 const int* p与int const* p是一样的，const修饰* p, p指向的对象不能通过*p来改变，
	但是此时可以改变地址p来改变指向的值
2.	const放在*右边，int * const p,
	p指向的对象可以通过*p来改变，但是不能修改p的值（也就是p指向的地址）
3.	如果在*的左右两边都加上const，则既不能通过*p修改值，也不能通过改变p指向的地址来修改值
 */


//自己写一个求字符串长度的代码
int  my_strlen(const char* str) //只数字符串长度，不改变字符串内容，加上const
{
	int count = 0;
	assert(str);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

//int main()
//{
//	char arr[] = "hello bit";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//数据在内存中存放的时候，有一个顺序问题，大小端字节序