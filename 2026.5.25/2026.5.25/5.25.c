#define _CRT_SECURE_NO_WARNINGS // 避免 scanf 报错
#include <string.h>


//三子棋deepseek版本
/*
#include <stdio.h>
#include <stdlib.h>   // 用于 rand() 和 srand()
#include <time.h>     // 用于 time() 生成随机种子

#define ROW 3
#define COL 3

// 函数声明
void init_board(char board[ROW][COL]);           // 初始化棋盘为空格
void print_board(char board[ROW][COL]);          // 打印当前棋盘
void player_move(char board[ROW][COL]);          // 玩家下棋
void computer_move(char board[ROW][COL]);        // 电脑下棋（随机）
char check_winner(char board[ROW][COL]);         // 检查胜负或平局，返回 'X'（玩家赢），'O'（电脑赢），'D'（平局），'C'（继续）
int is_full(char board[ROW][COL]);               // 判断棋盘是否已满（平局）

// 主函数
int main() {
    char board[ROW][COL];
    char winner = 'C';  // C 表示游戏继续
    int move_count = 0;

    // 初始化随机数种子（用于电脑随机下棋）
    srand((unsigned int)time(NULL));

    init_board(board);

    printf("欢迎来到三子棋游戏！\n");
    printf("玩家使用 'X'，电脑使用 'O'。\n");
    printf("输入坐标（行 列），范围 1~3，用空格分隔。\n\n");

    // 游戏主循环
    while (winner == 'C') {
        // 玩家回合
        player_move(board);
        print_board(board);
        winner = check_winner(board);
        if (winner != 'C')
            break;

        // 电脑回合
        printf("电脑思考中...\n");
        computer_move(board);
        print_board(board);
        winner = check_winner(board);
    }

    // 游戏结束，显示结果
    switch (winner) {
    case 'X':
        printf("恭喜你赢了！\n");
        break;
    case 'O':
        printf("电脑赢了，再接再厉！\n");
        break;
    case 'D':
        printf("平局！\n");
        break;
    default:
        break;
    }

    return 0;
}

// 初始化棋盘，所有格子为空格
void init_board(char board[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = ' ';
        }
    }
}

// 打印棋盘（带行列号和分隔线）
void print_board(char board[ROW][COL]) {
    printf("\n");
    printf("   1   2   3\n");   // 列号提示
    for (int i = 0; i < ROW; i++) {
        printf("%d ", i + 1);   // 行号提示
        for (int j = 0; j < COL; j++) {
            printf(" %c ", board[i][j]);
            if (j < COL - 1) printf("|");
        }
        printf("\n");
        if (i < ROW - 1) {
            printf("  ---+---+---\n");
        }
    }
    printf("\n");
}

// 玩家下棋
void player_move(char board[ROW][COL]) {
    int x, y;
    while (1) {
        printf("请输入你的下棋位置（行 列）：");
        scanf("%d %d", &x, &y);
        // 将输入的1~3转换为数组下标0~2
        x--; y--;
        if (x >= 0 && x < ROW && y >= 0 && y < COL && board[x][y] == ' ') {
            board[x][y] = 'X';
            break;
        }
        else {
            printf("位置无效或已有棋子，请重新输入！\n");
        }
    }
}

// 电脑下棋：随机选择一个空位
void computer_move(char board[ROW][COL]) {
    int x, y;
    while (1) {
        x = rand() % ROW;
        y = rand() % COL;
        if (board[x][y] == ' ') {
            board[x][y] = 'O';
            printf("电脑下在了 (%d, %d)\n", x + 1, y + 1);
            break;
        }
    }
}

// 检查棋盘是否已满（用于平局判断）
int is_full(char board[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == ' ')
                return 0;   // 还有空格，未满
        }
    }
    return 1;   // 已满
}

// 检查胜负或平局
// 返回值：'X' 玩家赢，'O' 电脑赢，'D' 平局，'C' 继续
char check_winner(char board[ROW][COL]) {
    // 检查行
    for (int i = 0; i < ROW; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }
    // 检查列
    for (int j = 0; j < COL; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return board[0][j];
        }
    }
    // 检查主对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    // 检查副对角线
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
    // 平局检查
    if (is_full(board)) {
        return 'D';
    }
    return 'C';   // 继续游戏
}
*/

//数组的类型是去掉数组名，如int arr[10]的类型是int [10]



//扫雷deepseek版本
//
//#define _CRT_SECURE_NO_WARNINGS   // 禁用 scanf 安全警告
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>  */ // 用于 tolower

//// ========== 可配置参数 ==========
//#define ROW 9          // 棋盘行数（建议 9~16）
//#define COL 9          // 棋盘列数（建议 9~16）
//#define MINE_COUNT 10  // 雷的数量（一般根据难度调整，如简单 10，中级 40）
//
//// 玩家看到的界面符号
//#define COVER '*'      // 未翻开格子
//#define FLAG 'F'       // 标记旗子
//#define MINE 'X'       // 踩雷时显示的雷
//
//// ========== 函数声明 ==========
//void init_board(char mine[ROW][COL], char show[ROW][COL]);   // 初始化雷区和显示区
//void set_mines(char mine[ROW][COL]);                         // 随机布置雷
//void print_board(char board[ROW][COL]);                      // 打印棋盘
//int count_adjacent_mines(char mine[ROW][COL], int x, int y); // 计算周围雷数
//void expand_blank(char mine[ROW][COL], char show[ROW][COL], int x, int y); // 递归展开空白区域
//int reveal_cell(char mine[ROW][COL], char show[ROW][COL], int x, int y);   // 揭示一个格子，返回 1 踩雷，0 安全
//void mark_cell(char show[ROW][COL], int x, int y);           // 标记/取消标记旗子
//int check_win(char show[ROW][COL]);                          // 检查是否胜利（所有非雷格子已翻开）
//void game_loop(char mine[ROW][COL], char show[ROW][COL]);    // 游戏主循环
//
//// ========== 主函数 ==========
//int main() {
//    char mine[ROW][COL];   // 存储雷的布局（0 无雷，1 有雷）
//    char show[ROW][COL];   // 存储玩家看到的界面（* / 数字 / F）
//
//    // 初始化随机种子
//    srand((unsigned int)time(NULL));
//
//    init_board(mine, show);
//    set_mines(mine);
//
//    printf("===== 扫雷游戏 =====\n");
//    printf("地图大小：%d x %d，雷数：%d\n", ROW, COL, MINE_COUNT);
//    printf("操作说明：\n");
//    printf("  揭示：输入 1 行 列  (例如: 1 5 3)\n");
//    printf("  标记：输入 2 行 列  (例如: 2 2 4)\n");
//    printf("  标记会切换旗子状态，再次标记取消。\n");
//    printf("===================\n\n");
//
//    game_loop(mine, show);
//
//    return 0;
//}
//
//// ========== 函数实现 ==========
//
///*/**
// * 初始化两个棋盘：mine 全为 '0'，show 全为 COVER
// */
//
//void init_board(char mine[ROW][COL], char show[ROW][COL]) {
//    for (int i = 0; i < ROW; i++) {
//        for (int j = 0; j < COL; j++) {
//            mine[i][j] = '0';   // '0' 表示无雷
//            show[i][j] = COVER;
//        }
//    }
//}
//
///**
// * 随机布置 MINE_COUNT 个雷（使用 rand 确保不重复）
// */
//void set_mines(char mine[ROW][COL]) {
//    int count = 0;
//    while (count < MINE_COUNT) {
//        int x = rand() % ROW;
//        int y = rand() % COL;
//        if (mine[x][y] == '0') {
//            mine[x][y] = '1';   // '1' 表示有雷
//            count++;
//        }
//    }
//}
//
///**
// * 打印棋盘，附带行列号（便于玩家输入）
// */
//void print_board(char board[ROW][COL]) {
//    // 打印列号
//    printf("   ");
//    for (int j = 0; j < COL; j++) {
//        printf("%2d ", j + 1);
//    }
//    printf("\n");
//
//    // 打印分隔线
//    printf("   ");
//    for (int j = 0; j < COL; j++) {
//        printf("---");
//    }
//    printf("\n");
//
//    // 打印行内容
//    for (int i = 0; i < ROW; i++) {
//        printf("%2d |", i + 1);
//        for (int j = 0; j < COL; j++) {
//            printf(" %c ", board[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//}
//
///**
// * 计算格子 (x, y) 周围 8 个方向上的雷数
// * @return 雷的数量（0~8）
// */
//int count_adjacent_mines(char mine[ROW][COL], int x, int y) {
//    int count = 0;
//    for (int dx = -1; dx <= 1; dx++) {
//        for (int dy = -1; dy <= 1; dy++) {
//            if (dx == 0 && dy == 0) continue;   // 跳过自身
//            int nx = x + dx;
//            int ny = y + dy;
//            if (nx >= 0 && nx < ROW && ny >= 0 && ny < COL && mine[nx][ny] == '1') {
//                count++;
//            }
//        }
//    }
//    return count;
//}
//
///**
// * 递归展开空白区域（当周围雷数为 0 时自动翻开相邻格子）
// */
//void expand_blank(char mine[ROW][COL], char show[ROW][COL], int x, int y) {
//    // 边界检查，超出棋盘或已翻开则返回
//    if (x < 0 || x >= ROW || y < 0 || y >= COL || show[x][y] != COVER) {
//        return;
//    }
//
//    int mines = count_adjacent_mines(mine, x, y);
//    // 显示数字（或空格）
//    show[x][y] = (mines == 0) ? ' ' : (mines + '0');
//
//    // 如果周围无雷，继续递归展开周围 8 个格子
//    if (mines == 0) {
//        for (int dx = -1; dx <= 1; dx++) {
//            for (int dy = -1; dy <= 1; dy++) {
//                if (dx == 0 && dy == 0) continue;
//                expand_blank(mine, show, x + dx, y + dy);
//            }
//        }
//    }
//}
//
///**
// * 揭示一个格子
// * @return 1 表示踩雷，0 表示安全
// */
//int reveal_cell(char mine[ROW][COL], char show[ROW][COL], int x, int y) {
//    // 如果格子已被翻开或已被旗子标记，禁止揭示
//    if (show[x][y] != COVER && show[x][y] != FLAG) {
//        printf("该位置已经打开或已标记，不能重复操作！\n");
//        return 0;
//    }
//    if (show[x][y] == FLAG) {
//        printf("请先取消旗子标记再揭示！\n");
//        return 0;
//    }
//
//    if (mine[x][y] == '1') {
//        // 踩到雷
//        show[x][y] = MINE;
//        return 1;
//    }
//    else {
//        // 安全：计算周围雷数并展开
//        expand_blank(mine, show, x, y);
//        return 0;
//    }
//}
//
///**
// * 标记/取消标记旗子（在 show 棋盘上切换 FLAG 和 COVER）
// */
//void mark_cell(char show[ROW][COL], int x, int y) {
//    if (show[x][y] != COVER && show[x][y] != FLAG) {
//        printf("已打开的格子不能标记旗子！\n");
//        return;
//    }
//    if (show[x][y] == COVER) {
//        show[x][y] = FLAG;
//        printf("已标记 (%d,%d) 为旗子\n", x + 1, y + 1);
//    }
//    else if (show[x][y] == FLAG) {
//        show[x][y] = COVER;
//        printf("已取消 (%d,%d) 的旗子标记\n", x + 1, y + 1);
//    }
//}
//
///**
// * 检查胜利条件：所有非雷格子都已翻开（即 show 中没有 COVER 且不是雷的位置）
// */
//int check_win(char show[ROW][COL]) {
//    for (int i = 0; i < ROW; i++) {
//        for (int j = 0; j < COL; j++) {
//            // 如果还有未翻开的格子（且不是旗子标记，旗子也算未翻开但可能正确）
//            // 简单判定：只要还有 COVER 存在，游戏未胜利。旗子标记尚未翻开，需要先取消或揭开才能赢。
//            // 为简化，要求所有非雷位置不能有 COVER，旗子标记也不能有（玩家必须揭开所有安全格）。
//            if (show[i][j] == COVER || show[i][j] == FLAG) {
//                return 0;
//            }
//        }
//    }
//    return 1;
//}
//
///**
// * 游戏主循环，处理玩家输入
// */
//void game_loop(char mine[ROW][COL], char show[ROW][COL]) {
//    int game_over = 0;
//    int win = 0;
//
//    while (!game_over && !win) {
//        // 打印当前棋盘
//        printf("当前棋盘：\n");
//        print_board(show);
//
//        int op, x, y;
//        printf("请输入操作和坐标（操作 行 列）：");
//        scanf("%d %d %d", &op, &x, &y);
//        x--; y--;   // 转换为 0 索引
//
//        // 输入合法性检查
//        if (x < 0 || x >= ROW || y < 0 || y >= COL) {
//            printf("坐标超出范围，请重新输入！\n");
//            continue;
//        }
//
//        if (op == 1) {   // 揭示
//            int exploded = reveal_cell(mine, show, x, y);
//            if (exploded) {
//                printf("\n======== 踩到雷了！游戏结束 ========\n");
//                // 显示所有雷的位置
//                for (int i = 0; i < ROW; i++) {
//                    for (int j = 0; j < COL; j++) {
//                        if (mine[i][j] == '1') {
//                            show[i][j] = MINE;
//                        }
//                    }
//                }
//                print_board(show);
//                game_over = 1;
//            }
//        }
//        else if (op == 2) {  // 标记
//            mark_cell(show, x, y);
//        }
//        else {
//            printf("操作无效！1 揭示，2 标记。\n");
//            continue;
//        }
//
//        // 每轮操作后检查胜利
//        if (!game_over && check_win(show)) {
//            printf("\n======== 恭喜你赢了！ ========\n");
//            print_board(show);
//            win = 1;
//        }
//    }
//
//    if (win) {
//        printf("胜利！你成功找出了所有安全格子。\n");
//    }
//    else if (game_over) {
//        printf("游戏结束，再接再厉！\n");
//    }
//}


                                 //操作符


/*
 整形的除法 1/2=0
 浮点型除法 1.0/2=0.5
 "%"取余数,取模操作符两端必须是整数 
 移位操作符（只针对整数）
 << 左移操作符
 >> 右移操作符
 整数的二进制表示有三种方法：原码，反码，补码
 正整数的原码，反码，补码相同，整型占四个字节，32位
 例如7：原码：0000 0000 0000 0000 0000 0000 0000 0111，最高位是0为正
        反码：0000 0000 0000 0000 0000 0000 0000 0111，
        补码：0000 0000 0000 0000 0000 0000 0000 0111，
    -7：原码：1000 0000 0000 0000 0000 0000 0000 0111，最高位是1为负
        反码：1111 1111 1111 1111 1111 1111 1111 1000，（原码的符号位不变，其他位按位取反）
        补码：1111 1111 1111 1111 1111 1111 1111 1001，反码+1就是补码
整数在内存中存储的是补码！！！所以左移右移的操作都是在操作补码
int a=7;
int b=a<<1;
左移就是左边丢弃，右边补零
a=0111,b=1110

如果是负数
int a=-7;
int b=a<<1;
a=-7在内存中存储的补码是1111 1111 1111 1111 1111 1111 1111 1001，移动后补码是
1111 1111 1111 1111 1111 1111 1111 0010，打印的是原码，原码是补码-1再符号位不变，其他位取反
-1
=1111 1111 1111 1111 1111 1111 1111 0001
符号位不变，其他位取反得到原码1000 0000 0000 0000 0000 0000 0000 1110
所以int b=a<<1;b=-14,
综上，左移操作符的结果是×2


         右移操作符：
             1.算术移位：右边丢弃，左边补原符号位
             2.逻辑移位；右边丢弃，左边补0
 int a=7;
 int b=a>>1;
 a的补码是  0000 0000 0000 0000 0000 0000 0000 0111
 此时补码为 0000 0000 0000 0000 0000 0000 0000 0011
 b=3;
 int a=-7;
 int b=a>>1;
 a的补码是1111 1111 1111 1111 1111 1111 1111 1001
 此时，若是算术移位，则b的补码为1111 1111 1111 1111 1111 1111 1111 1100
 算出反码是补码-1再把符号位以外取反得到反码1000 0000 0000 0000 0000 0000 0000 0100
 得到b=-4；
 看出vs编译器使用的是算术位移，大部分编译器都是算术位移


 移位操作符移动的位数为正整数


                                 位操作符
 
 & - 按位与，（2进制）
 | - 按位或，（2进制）
 ^ - 按位异或（2进制）
 只适用整形，要交换a，b的值，可以使用一下用法
 a=a^b;
 b=a^b;
 a=a^b;
 异或具有交换律

*/

/* 求一个整数存储在内存中二进制中1的个数
int count_ones(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;   // 检查最低位是否为1
        n >>= 1;          // 右移一位
    }
    return count;
}

int main() {
    int num;
    printf("请输入一个整数: ");
    scanf("%d", &num);
    // 传入时转换为无符号整数，以正确处理负数的补码
    int ones = count_ones((unsigned int)num);
    printf("整数 %d 的二进制表示中有 %d 个1\n", num, ones);
    return 0;
}
*/
