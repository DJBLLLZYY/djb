/*                                        字符函数                */
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
char* my_strcpy(char* destion,char* source)
{
	char* res = destion;
	assert(destion);
	assert(source); //断言，判断有没有空指针，有的话报错
	//while (*source != '\0')
	//{
	//	*destion = *source;
	//	destion++;
	//	source++;
	//}
	//*destion = *source;
	while (*destion++ = *source++)
	{
		
	}
	return res;
}

//int main()
//{
//	char arr[] = "abcdef"; //放入了abcdef\0
//	int len = strlen(arr); //如果没有\0，len是一个随机值，strlen会一直读取，直到碰到\0
//	char destion[20] = { 0 };
//	my_strcpy(destion, arr);
//	printf("%s\n",destion);
//	printf("%d", len);
//	return 0;
//}

//比较两个字符串是否相等
//相等返回0，str1大于str2返回正数，str1小于str2返回负数
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 =='\0')
			return 0; //相等
	}
	return *str1 - *str2; 
}


int main()
{

	//errno c语言设置的全局变量错误码,在errno.h头文件中
	return 0;
}