#define _CRT_SECURE_NO_WARNINGS  // 解决 scanf 不安全警告
#include <stdio.h>

// 全局计数器，记录移动步数
int step_count = 0;

// 汉诺塔递归函数
void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        printf("移动盘子 1 从 %c 到 %c\n", from, to);
        step_count++;  // 每移动一次，步数加1
    }
    else {
        hanoi(n - 1, from, to, aux);
        printf("移动盘子 %d 从 %c 到 %c\n", n, from, to);
        step_count++;
        hanoi(n - 1, aux, from, to);
    }
}

//int main() {
//    int n;
//    //while (1)
//    //{
//    //    printf("请输入盘子的数量: ");
//    //    scanf("%d", &n);
//    //    printf("\n汉诺塔移动步骤（%d 个盘子，从 A 移动到 C）：\n", n);
//    //    hanoi(n, 'A', 'B', 'C');
//    //    printf("\n总共移动了 %d 步。\n", step_count);
//    //    // 验证公式：2^n - 1 应等于 step_count
//    //    // 这里不强制输出公式，只是确认
//    //}
//    
//    return 0;
//}
//字符char也属于整形家族，char值以ASCII值存储
//default在Switch语句中可以放在任意位置


#include <stdlib.h>  // 提供 malloc, free

// 从大到小排序并输出
void print_descending(int arr[], int n) {
    // 使用选择排序（从大到小）
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            int temp = arr[i];
            arr[i] = arr[max_idx];
            arr[max_idx] = temp;
        }
    }
    printf("从大到小输出：");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
}


//用辗转相除法求最大公约数
int gcd(int a, int b) {
    // 处理负数：最大公约数通常取非负值，所以先取绝对值
    a = abs(a);
    b = abs(b);

    // 欧几里得算法：当 b 不为 0 时，反复用 b 除 a 取余
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;  // 此时 a 即为最大公约数
}
//int main() {
//    //while (1)
//    //{
//    //    int n;
//    //    printf("请输入整数个数: ");
//    //    scanf("%d", &n);
//    //    if (n <= 0) {
//    //        printf("个数必须大于0！\n");
//    //        return 1;
//    //    }
//    //    // 动态分配数组内存（VS2022 不支持变长数组，所以用 malloc）
//    //    int* arr = (int*)malloc(n * sizeof(int));
//    //    if (arr == NULL) {
//    //        printf("内存分配失败！\n");
//    //        return 1;
//    //    }
//    //    printf("请输入 %d 个整数，用空格或回车分隔:\n", n);
//    //    for (int i = 0; i < n; i++) {
//    //        scanf("%d", &arr[i]);
//    //    }
//    //    print_descending(arr, n);
//    //    // 释放动态分配的内存
//    //    free(arr);
//    //}
//    while (1) {
//        int a = 0;
//        int b = 0;
//        printf("输入两个整数：");
//        scanf("%d %d", &a, &b);
//        printf("最大公约数为：%d\n",gcd(a, b));
//    }
//    
//
//    return 0;
//}

//printf中%d占一位，%2d右对齐占两位，空格在前，%-2d左对齐
//\t是水平制表符
//函数形参是实参的一份临时拷贝，形参是调用时才实例化，才开辟内存空间
//如果函数想改变实参，在函数输入时，应该传入实参地址，使用传址调用
//栈区：局部变量，形参，返回值（都是临时的）
//堆区：动态内存分配malloc，free，calloc，realloc
//静态区：静态变量，全局变量
//函数中复合语句中定义的变量只能在复合语句中使用，不能在整个函数中使用


//数组部分
//c99之前，数组的大小必须是常量或者常量表达式
//在C99之后，数组的大小可以是变量，为了支持变长数组
//int a[10]={1,2,3}不完全初始化，剩余的元素默认为0
//char ch1[10]={'a','b','c'},不完全初始化，剩余元素为\0
//char ch2[]={'a','b','c'}数组中元素为abc
//char ch3[]="abc"数组中实际为"abc\0",因为字符串以\0结尾
//数组在内存中是连续存放的
//二维数组
//int arr[2][3]={1,2,3,4,5},此时，arr[0]={1,2,3},arr[1]={4,5,0},数据不够自己补0
//二维数组可理解为数组的元素为数组
//int arr[3][4]={{1,2},{3,4},{5,6}}此时，arr[0]={1,2,0,0},arr[1]={3,4,0,0},arr[2]={5,6,0,0}
//二维数组定义时，行可以省略，列不能省略int arr[][3]正确
//三维数组只能省略第一维，第二维第三维不可以省略


//冒泡排序升序
//数组传参时有两种写法
//1.数组
//2.指针
//数组名本质是数组首元素的地址，函数地址用指针接受，所以函数bubble_sort的arr看似是数组，实际是指针变量
//
void bubble_sort(int arr[],int size)
{
    int temp = 0;
   /* int size = sizeof(arr) / sizeof(arr[0]);*/
    for (int i = 0; i < size; i++) 
    {
        for (int j = 1; j < size-i; j++) 
        {
            if(arr[j-1]>arr[j])
            {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
/*int main()
{
    int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
    int sz = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr,sz);
    
    printf("升序后数组为：");
    for (int i = 0; i < sz; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}*/
//数组名本质是数组首元素的地址，
//int main()
//{
//    int arr[10];
//    printf("arr的地址：      %p\n", arr);
//    printf("arr+1的地址：    %p\n", arr+1);
//    printf("&arr的地址：     %p\n", &arr);
//    printf("&arr+1的地址：   %p\n", &arr+1); 
//    printf("&arr[0]的地址：  %p\n", &arr[0]);
//    printf("&arr[0]+1的地址：%p\n", &arr[0]+1);
//    int n = sizeof(arr);
//    printf("%d\n", n);
//    return 0;
//}
//这段代码，打印的arr和arr[0]的地址都是00DEF7B8，n的值是40，但是如果arr是地址，那么打印的n的值应该是4
//数组名确实能表示首元素的地址，但是有两个例外
//1.sizeof(数组名),这里的数组名表示整个数组，计算的是整个数组的大小，单位是字节
//2.&数组名,这里的数组名表示整个数组，取出的是整个数组的地址
//
/*
arr的地址：         012FFB3C   一个元素四个字节，所以加4
arr + 1的地址：     012FFB40
& arr的地址：       012FFB3C
& arr + 1的地址：   012FFB64   0x64-0x3C=40,跳过整个数组，40个字节
& arr[0]的地址：    012FFB3C
& arr[0] + 1的地址：012FFB40
*/

//二维数组的数组名理解
//int main()
//{
//    int arr[3][4];
//    int sz = sizeof(arr);
//    printf("arr数组的大小（一个元素四个字节）：%d\n", sz);
//
//    printf("二维数组的数组名arr表示的地址：%10p\n",arr);
//    printf("二维数组的数组名arr+1表示的地址：%p\n", arr+1);
//    printf("计算有多少行：%d\n", sizeof(arr) / sizeof(arr[0]));
//    //通过二维数组arr的总大小除以第一行的大小计算出有几行
//    printf("计算有多少列：%d\n", sizeof(arr[0]) / sizeof(arr[0][0]));
//    //通过二维数组第一行的大小除以第一个第一列元素的大小计算出有多少列
//    /*二维数组的数组名也表示首元素的地址，表示的是第一行的地址，二维数组的由一维数组组成，arr[3][4]
//    由三个一维数组组成，首地址为arr[0],也就是第一行的数组地址，也就是第一个一维数组的地址
//    arr[0]表示第一行，或者是第一个数组
//    */
//    /*  二维数组的数组名arr表示的地址：    012FFA34
//        二维数组的数组名arr + 1表示的地址：012FFA44
//        0x44-0x34=16,也就是16个字节，刚好是四个元素，也就一行的内存大小
//        */
//    return 0;
//}


