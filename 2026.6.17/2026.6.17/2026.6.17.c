#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


/*                               动态内存管理          */
//int main()
//{
//	int a = 10;   //向内存申请了4字节
//	int arr[10] = { 0 };   //申请了40字节，栈区内
//	//上述申请好内存后都不能改变大小
//	// malloc    
//	// void* malloc(size_t size)    申请size个字节，并返回申请内存的起始地址,开辟内存失败时，返回空指针
//	// 
//	//calloc：
//	// void* calloc(size_t num,size_t size) 
//	// num:元素个数  size：每个元素的大小,该函数会在返回之前，初始化所开辟的空间
//	// 想初始化用calloc，不想初始化用malloc
//	// 
//	//realloc
//	// void* realloc(void ptr,size_t size)
//	// ptr：要修改的空间的起始地址
//	// size：调整成新的大小，size为无符号整形
//	// 情况一：当前内存后面有足够的空间用来开辟，则直接开辟，并返回原来的ptr，返回类型为void*
//	// 情况二：当前内存后没有足够的空间用来开辟，直接开辟会占用其他被用的内存，则函数会找到一块足够大的空间，并把数据
//	//         拷贝过去，并返回新的内存的起始地址，旧的内存空间会被释放，返回类型为void*
//	// realloc(NULL,40);的功能与malloc(40)的功能是一样的
//	// 
//	//free：释放内存空间，如果参数是空指针，则什么都不干
//	// 使用free必须指向开辟空间的起始位置
//	/*
//	* 栈区：局部变量，形式参数
//	* 堆区：malloc，calloc，realloc，free
//	* 静态区：静态变量，全局变量
//	*/
//	int* p = (int*)malloc(40); //堆区内
//	if (p == NULL)//开辟内存失败，返回空指针
//	{
//		printf("%s\n", strerror(errno));
//		return 1; //main函数异常返回
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	//free(p); p指向的地址没有改变，但是p维护的内存空间还给了操作系统，可以继续使用
//	// p=NULL; 防止p再次找到原来指向的地址进行操作
//	// 
//	//这里没有free，并不意味这内存不回收，当程序退出的时候，系统会自动回收内存空间
//	return 0;
//
//}



//
//int* test()
//{
//	int a = 10;
//	return &a;
//}
////a的生命周期就是在函数内，当函数结束时，a所指向的内存空间被销毁，归还给操作系统，此时，把
////返回的地址传给p时，p也不能对内存进行维护，虽然可以打印出来，但是该内存空间可以被其他变量进行维护和修改
//
//int main()
//{
//	int* p = test();
//
//	printf("%d ", *p);
//	return 0;
//}

/*                  柔性数组                */
/*结构体中最后一个元素允许是未知大小的数组，这就叫柔性数组成员
* 
* typedef struct st_type
* {
*		int i;
*		int a[0];//柔性数组成员
* }type_a;
*/
//有些编译器报错可以改成：
//typedef struct st_type
//{
//	int i;
//	int a[];
//
//}type_a;
/*
柔性数组特点：
结构中的柔性数组成员钱必须至少有一个其他成员
sizeof返回的这种结构大小不包括柔性数组的内存
包含柔性数组成员的结构体用malloc（）函数进行动态内存分配，并且分配的内存大小应该大于结构的大小，以适应柔性数组的预期大小
*/

//struct S
//{
//	int n;
//	int arr[];
//
//};
//int main()
//{
//	int sz = sizeof(struct S);
//	printf("%d\n", sz); //结果是4
//
//	//柔性数组的使用
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 40);
//	if (ps == NULL)
//	{
//		return 1;
//	}
//	ps->n = 100;
//	for (int i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	struct S* ptr = (struct S*)malloc(sizeof(struct S) + 80); 
//	if (ptr != NULL)
//	{
//		ps = ptr;//申请一块更大的空间给ptr再传给ps，则可以实现ps更大的内存空间，体现出柔性数组的“柔”
//		ptr = NULL;
//	}
//	//释放空间
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}


//另外一种类似的方法,一个结构体内最后一个元素为指针，指向另外一片空间
//不推荐使用，使用过程中产生的内存碎片较多
//struct S
//{
//	int n;
//	int* arr;
//
//};
//int main() 
//{
//
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	if (ps == NULL)
//	{
//		return 1;
//	}
//	ps->n = 100;
//	ps->arr = (int*)malloc(40);
//	if (ps->arr == NULL)
//	{
//		return 1;
//	}
//	//使用
//	for (int i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	//释放
//	free(ps->arr);
//	free(ps);
//	ps = NULL;
//	return 0;
//}