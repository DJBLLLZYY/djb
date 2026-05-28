/*                                  结构体              */


//struct Peo
//{
//	char name[20];
//	char tele[12];
//	char sex[5];
//	int high;
//
//};
//struct st
//{
//	struct Peo p;
//	int num;
//	float f;
//};
///*struct Peo
//{
//	char name[20];
//	char tele[12];
//	char sex[5];
//	int high;
//
//}p1,p2; */ //p1，p2是struct Peo类型的变量，是全局变量，不建议使用
//
////结构体的成员也能包括结构体
//int main()
//{
//	struct Peo p1 = { "djb","19323708498","男",187 };
//	struct st s = { {"zyy","18355834676","女",173},100,3.14f };
//	//浮点数在内存中是不能精确保存的，所以在调试中看到3.1400001
//	printf("%s %s %s %d\n", p1.tele, p1.sex, p1.name, p1.high);
//	printf("%s %s %s %d %d %f\n", s.p.tele,s.p.sex,s.p.name,s.p.high,s.num,s.f);
//	return 0;
//}

/*                 结构体传参                  */
//结构体传参，尽量传结构体的地址，以实现更好的性能



//求两个数的二进制有几个不同的数
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**
 * 统计整数 x 的二进制表示中 1 的个数（使用 Brian Kernighan 算法）
 */
int count_ones(unsigned int x) {
    int cnt = 0;
    while (x) {
        x &= (x - 1);   // 清除最低位的 1
        cnt++;
    }
    return cnt;
}

/**
 * 计算两个整数的二进制不同位数（汉明距离）
 */
int hamming_distance(int a, int b) {
    unsigned int diff = (unsigned int)a ^ (unsigned int)b; // 异或得到不同位
    return count_ones(diff);
}

//int main() {
//    int m, n;
//    printf("请输入两个整数，用空格分隔: ");
//    scanf("%d %d", &m, &n);
//
//    int dist = hamming_distance(m, n);
//    printf("整数 %d 和 %d 的二进制表示中有 %d 个不同的位。\n", m, n, dist);
//
//    // 可选：打印二进制对比（仅演示低位8位，完整可自行扩展）
//    printf("  %d 的二进制: ", m);
//    for (int i = 31; i >= 0; i--) {
//        putchar(((unsigned int)m >> i) & 1 ? '1' : '0');
//        if (i % 8 == 0 && i != 0) putchar(' ');
//    }
//    printf("\n  %d 的二进制: ", n);
//    for (int i = 31; i >= 0; i--) {
//        putchar(((unsigned int)n >> i) & 1 ? '1' : '0');
//        if (i % 8 == 0 && i != 0) putchar(' ');
//    }
//    printf("\n");
//
//    return 0;
//}
int main()
{

    return 0;

}