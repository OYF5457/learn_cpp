//
// Created by 陈志宵 on 16/6/18.
// 求最大公约数的方法
//


#include <iostream>
using namespace std;

int gcd1(int m, int n) {
    while(n != 0) {
        int tmp = m % n;
        m = n;
        n = tmp;
    }
    return m;
}

int main() {
    cout << gcd1(60, 24) << endl;
    return 0;
}
