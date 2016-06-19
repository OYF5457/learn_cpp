//
// Created by 陈志宵 on 16/6/18.
// 求最大公约数的方法
//


#include <iostream>
#include <vector>
using namespace std;

//欧几里得算法非递归
int gcd1(int m, int n) {
    while(n != 0) {
        int tmp = m % n;
        m = n;
        n = tmp;
    }
    return m;
}

//欧几里得递归
int gcd2(int m, int n) {
    if(n == 0) {
        return m;
    }
    return gcd2(n, m % n);
}

//"埃拉托色尼筛法"
vector<int> sieve(int n) {
    int *arr = new int[n + 1];
    for(int i = 2; i <= n; i++) {
        arr[i] = i;
    }
    for(int i = 2; i * i <= n; ++i) {
        if(arr[i] != 0) {
            for(int j = i * i; j <= n; j += i) {
                arr[j] = 0;
            }
        }
    }
    vector<int> vec;
    for(int i = 2; i <= n; i++) {
        if(arr[i] != 0) {
            vec.push_back(arr[i]);
        }
    }
    delete []arr;
    return vec;
}

//分解质因数,朴素方法
void prime_factorization(int n) {
    int start = 2;
    while(n != 1) {
        if(n % start == 0) {
            printf("%d ", start);
            n /= start;
        } else {
            ++start;
        }
    }
}

//分解质因数
void prime_factorization1(int n) {
    vector<int> v = sieve(n);
    for(int i = 0; i < v.size();) {
        if(n % v[i] == 0) {
            printf("%d ", v[i]);
            n /= v[i];
        } else {
            ++i;
        }
    }
}

int main() {
    cout << gcd1(60, 24) << endl;
    cout << gcd2(60, 24) << endl;
    vector<int> v = sieve(25);
    for(auto m : v) {
        cout << m << " ";
    }
    cout << endl;
    prime_factorization(24);
    cout << endl;
    prime_factorization1(160000);
    cout << endl;
    return 0;
}
