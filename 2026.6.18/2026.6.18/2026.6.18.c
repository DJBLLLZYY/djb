/*              文件操作              */
/*
	一个文件要有一个唯一的文件标识，包含三部分：文件路径+文件名主干+文件后缀
		每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息
	(如文件的名字，文件状态及文件当前的位置等）。
	这些信息是保存在一个结构体变量中的，该结构体类型是有系统声明的，取名FILE
	每当打开一个文件时，系统会根据文件的情况自动创建一个FILE的结构变量，并填充其中的信息，使用者不必关心细节
	一般都是通过一个FILE的指针来维护这个FILE结构的变量，这样使用起来方便
	FILE* pf;
	定义pf是一个指向FILE类型数据的指针变量，可以使pf指向某个文件的文件信息区（是一个结构体变量）。
	通过该文件信息区中的信息就能访问该文件，也就是说，通过文件指针变量能够找到与它关联的文件
		
*/
			//文件的打开和关闭
/*
	文件在读写之前应该先打开文件，在使用结束之后应该关闭文件
	在编写程序的时候，再打开文件的同时，都会返回一个FILE*的指针变量指向该文件，也相当于建立了指针和文件的关系
	ANSIC规定使用fopen函数打开文件，fclose来关闭文件
	//打开文件
	FILE* fopen(const char * filename,const char * mode);
	filename:文件名     
	mode：文件的打开模式（读：“r”  写：“w”  追加："a" )
	如果打开文件失败，则返回空指针
	//关闭文件
	int fclose (FILE * stream);
*/
/*
	文件的使用方式  |              含义                                 |   如果指定文件不存在
		"r"(只读)   |   为了输入数据，打开一个已经存在的文本文件		|   出错
		"w"(只写)   |   为了输入数据，打开一个文本文件					|   建立一个新文件
		"a"(追加)   |   想文本文件尾添加数据							|   建立一个新文件
		"rb"(只读)  |   为了输入数据，打开一个二进制文件				|   出错
		"wb"(只写)  |   为了输入数据，打开一个二进制文件				|   建立一个新文件
		"ab"(追加)  |   向一个二进制文件尾添加数据						|   出错
		"r+"(读写)  |   为了读和写，打开一个文本文件					|   出错
		"w+"(读写)  |   为了读和写，新建一个新的文件					|   建立一个新文件
		"a+"(读写)  |   打开一个文件，在文件尾进行读写					|   建立一个新文件
		"rb+"(读写) |   为了读和写打开一个二进制文件					|   出错
		"wb+"(读写) |   为了读和写，新建一个新的二进制文件				|   建立一个新文件
		"rb+"(读写) |   为了读和写打开一个二进制文件					|   建立一个新文件
		"wb+"(读写) |   为了读和写打开一个二进制文件					|   出错
		"ab+"(读写) |   为了读和写，新建一个新的二进制文件				|   建立一个新文件
		"r"(只读)   |   打开一个二进制文件，在文件尾进行读和写			|   建立一个新文件
*/
/*		功能		|	函数名			|	适用于
* 字符输入函数		|fgetc				|所有输入流
* 字符输出函数		|fputc				|所有输出流
* 文本行输入函数	|fgets				|所有输入流
* 文本行输出函数	|fputs				|所有输出流
* 格式化输入函数	|fscanf				|所有输入流
* 格式化输出函数	|fprintf			|所有输出流
* 二进制输入		|fread				|文件
* 二进制输出		|fwrite				|文件
* 
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	//写文件时，当源文件有内容时，会先销毁原来的全部内容再写，如果不想销毁，应该追加
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//写文件
//	fputc('a', pf);
//	//关闭文件
//	fclose(pf);
//	return 0;
//}
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//读文件
//	char arr[20];
//
//	fgets(arr,20,pf);
//	printf("%s\n", arr);
//	//关闭文件
//	fclose(pf);
//	return 0;
//}

typedef struct 
{
	char arr[10];
	int age;
	float score;
}stu;
//格式化输出
//int main()
//{
//	stu s = { "zhangsan",25,90.1f };
//	FILE* pf = fopen("text.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//
//	}
//	fprintf(pf,"%s %d %f",s.arr,s.age,s.score);
//	fclose(pf);
//	pf == NULL;
//
//	return 0;
//}

//格式化输入
//int main()
//{
//	stu s = { 0 };
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//
//	}
//	fscanf(pf, "%s %d %f", &(s.arr), &(s.age), &(s.score));
//	printf("%s %d %f\n", s.arr, s.age, s.score);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main()
//{
//	stu s1 = { "zhangsan",25,50.5f };
//	stu s2 = {0};
//	//以二进制的形式写到文件中
//	FILE* pf1 = fopen("text.txt", "wb");
//	if (pf1 == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//二进制的方式写
//	fwrite(&s1, sizeof(stu), 1, pf1);
//	fclose(pf1);
//	pf1 = NULL;
//
//	//以二进制的形式读
//	FILE* pf2 = fopen("text.txt", "rb");
//	if (pf2 == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fread(&s2, sizeof(stu), 1, pf2);
//	printf("%s %d %.2f", s2.arr, s2.age, s2.score);
//	fclose(pf2);
//	pf2 = NULL;
//	return 0;
//}

int main()
{
	stu s = { "zhangsan",20,55.5f };
	stu tmp = { 0 };
	char buf[100] = { 0 };
	//把结构体内的成员转换成字符串
	//sprintf是把格式化的数据转换成字符串
	//sscanf 从一个字符串中转化出一个格式化的数据
	sprintf(buf, "%s %d %f", s.arr, s.age, s.score);
	printf("%s\n", buf);
	//从字符串buf中获取一个格式化的数据到tmp中
	sscanf(buf, "%s %d %f", tmp.arr, &(tmp.age), &(tmp.score));
	printf("%s %d %f", tmp.arr,tmp.age,tmp.score);
	return 0;
}

//文件随机读写
//int fseek(FILE* stream,long int offset,int origin);
//根据文件指针的位置和偏移量来定位文件指针
//void remind(FILE*stream);
//让文件指针的位置回到文件的起始位置

/*                
					文件读取结束的判定
	在文件读取的过程中不能用feof函数的返回值直接用来判断文件是否结束
	而是应用于当文件读取结束的时候，判断是读取失败还是遇到文件尾结束
	1.文本文件读取是否结束，判断返回值是否为EOF（fgetc）或者NULL（fgets）
	例如：
		fgetc判断是否为EOF
		fgets判断返回值是否为NULL
	2.二进制文件的读取结束判断，判断返回值是否小于实际要读的个数
	例如：
		fread判断返回值是否小于实际要读的个数
*/