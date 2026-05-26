#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define true 1
#include <Windows.h>
#include<string.h>
//计算BMI，weight：体重kg
//high：升高cm
float BMI(float weight, float high)
{
	double Bmi = 0.0;
	Bmi = weight / (high / 100) / (high / 100);
	return Bmi;
}
//int main()
//{
//	//计算BMI主程序
//	/*float weight = 0;
//	float high = 0;
//	while (1)
//	{
//		scanf("%f %f", &weight,&high);
//		printf("%.2f\n", BMI(weight, high));
//	}*/
//
//}
//计算n的阶乘
/*int jiecheng(int n)
{
	int result = 1;
	
	for (int i = 1; i <= n; i++)
	{
		result = result * i;
	}
	return result;
}
int main()
{
	while (true)
	{
		int n = 0;
		printf("输入：");
		scanf("%d", &n);
		printf("result=");
		printf("%d\n", jiecheng(n));
		
	}
	return 0;
}*/
//阶乘运算不需要传递参数
//void jiecheng()
//{
//	int n = 0;
//	int result = 1;
//	printf("输入：");
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++)
//	{
//		result = result * i;
//	}
//	printf("result=%d\n",result);
//
//}


void guanji()
{
	char input[20] = { 0 };
	printf("输入我是猪，不然就关机\n");
	system("shutdown -s -t 60");
again:
	printf("请注意，电脑将在60s内关机\n输入：");
	scanf("%s", input);
	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown -a");
		printf("已取消关机");
	}
	else
	{
		printf("请正确输入，快没时间咯");
		goto again;
	}
}

//阶乘运算的和1！+2！+...+n!
void jiecheng_sum()
{
	int n = 0;
	int result = 1;
	int sum = 0;
	printf("输入：");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for ( int j = 1;j<=i;j++)
		{
			result = result * j;
		}
		sum = sum + result;
		result = 1;
	}
	printf("输出：%d\n", sum);
}




void menu()
{
	printf("***********************************\n");
	printf("***********  1.play   *************\n");
	printf("***********  0.exit   *************\n");
	printf("***********************************\n");
}
#include <stdlib.h>
//rand():生成0-32767随机数0~0x07FFF
#include<time.h>
void game()
{
	//1.生成随机数
	//srand设置rand的起点，通过时间戳随机起点来实现rand的随机
	int input = 0;
	int num = rand()%100+1;
	
	//2.猜数字
	
	for (int i = 1; i <=5; i++)
	{
		printf("第%d次输入数字：",i);
		scanf("%d", &input);
		if (input < num)
		{
			printf("猜小啦\n");
			if (i == 5) { printf("随机数：%d\n", num); }
			
		}
		else if (input > num)
		{
			printf("猜大啦\n");
			if (i == 5) { printf("随机数：%d\n", num); }
		}
		else
		{
			printf("猜对啦\n");
			printf("随机数：%d\n", num);
			break;
		}
			
	}
	
}
void guess_num_game()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("猜数字,您一共有5次机会\n");
			game();//进入game游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("无效输入，重新输入\n");
			break;
		}
	} while (input);
}


//当实参传递给形参时，形参是实参的一份拷贝
//对形参的修改不会影响实参
int main()
{
	srand((unsigned int)time(NULL));
	/*guanji();*/
	while (true)
	{
		/*jiecheng();*/
		/*jiecheng_sum();*/
		/*guess_num_game();*/
		
	}
	return 0;
}