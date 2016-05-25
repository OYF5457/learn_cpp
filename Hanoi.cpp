//
// Created by 陈志宵 on 16/5/25.
//
#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c) { // 把n个盘子从a柱子借助b柱子移动到c柱子
    if(n == 1) {
        cout << a << "->" << c << endl;
    } else {
        hanoi(n - 1, a, c, b);
        cout << a << "->" << c << endl;
        hanoi(n - 1, b, a, c);
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

