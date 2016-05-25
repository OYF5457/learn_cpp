//
// Created by 陈志宵 on 16/5/25.
// 汉诺塔问题
//
#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c) { // 把a上的n个盘子从a柱子借助b柱子移动到c柱子
    if(n == 1) {
        cout << a << "->" << c << endl;
    } else {
        hanoi(n - 1, a, c, b);// 把a上的n - 1个盘子从a柱子借助c柱子移动到b柱子
        cout << a << "->" << c << endl; //把a上的最下面盘子移到c上
        hanoi(n - 1, b, a, c);// 把柱子b上的n-1个盘子通过柱子a移动到柱子c
    }
}

int main() {
    int m;
    cout << "输入盘子的数量: " << endl;
    while(cin >> m) {
        hanoi(m, 'A', 'B', 'C');
    }
    return 0;
}

