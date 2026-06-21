/*
						程序环境和预处理
	在ANSIC的任何一种实现中，存在两种不同的环境
	第1是翻译环境，在这个环境中源代码被转换为可执行的机器指令
	第2是执行环境，它用于实际执行代码

	翻译环境

	源文件->编译器->目标文件
						   |
						  \/
				链接库->  链接器
						   |
						  \ /
						  可执行程序(.exe)
*/		
/*					
						预处理详解
	预定义符号
	__FILE__  //进行编译的源文件
	__FILE__  //文件当前的行号
	__DATE__  //文件被编译的日期
	__TIME__  //文件被编译的时间
	__STDC__  //如果编译器遵循ANSI C，其值为1，否则未定义

	
*/
#include<stdio.h>
//int main()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		printf("file:%s line=%d data:%s time:%s  i=%d\n", __FILE__,__LINE__ ,__DATE__,__TIME__,i);
//		
//	}
//	return 0;
//}

/*
	#define定义宏：
		#define 机制包括了一个规定，允许把参数替换到文本中，这种实现通常称为宏或者定义宏
	#define name(parament-list) stuff
	其中的parament-list是一个由逗号隔开的符号表，他们可能出现在stuff中
	注意：参数列表的左括号必须与name紧邻
	如果两者之间有任何空白存在，参数列表就会被解释称stuff的一部分
*/
//#define SQUARE(X) X*X
#define SQUARE(X) ((X)*(X))
#define PRINT(N) printf("the value of "#N " is %d\n",N)
#define PRINT_A(N,FORMAT) printf("the value of "#N" is "FORMAT"\n",N)//自己规定打印的类型
//#N不取N的值，而是返回表示N的字符串
// ##可以把位于它两边的符号合成一个符号
//  
int main()
{
	int r = SQUARE(5);
	int j = SQUARE(5 + 1);
	printf("r=%d\n", r); //25
	printf("j=%d\n", j); //11
	//定义宏在使用的时候，只会把括号内的直接替换上去，此时X=5+1，X*X=5+1*5+1=11,想实现功能，应该改为
	// #define SQUARE(X) (X)*(X)
	int a1 = 1;
	int a2 = 2;
	float a3 = 1.11;
	PRINT(a1);
	PRINT(a2);
	PRINT_A(a3, "%lf" );
	return 0;
}

//命名约定：宏名全大写
//			函数名不全大写
/*
	#undef  取消宏定义

	
*/

/*		
*			条件编译
1.
	#if  常量表达式
		//...
	#endif
 2.多个分支的条件编译
	#if 常量表达式
		//...
	#elif 常量表达式
		//...
	#else
		//...
	#endif
 3. 判断是否被定义
	#if defined(symbol)
	#ifdef symbol
	#if !defined(symbol)
	#ifndef symbol


 4.	防止头文件被多次重复包含
	#ifndef __TEST_H__
	#define __TEST__H__

	函数声明

	#endif

	5.#include<> :直接去库目录下查找
	  #include"" :先去代码所在路径下查找，如果找不到再去库目录下查找
*/