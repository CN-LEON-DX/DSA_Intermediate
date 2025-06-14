// Cho mảng A[] gồm N phần tử, nhiệm vụ của bạn là sắp đặt lại vị trí các phần tử trong mảng và tính toán giá trị lớn nhất của biểu thức :image

// https://s3.amazonaws.com/hr-assets/0/1652568525-7306fd7235-max.png
// Input Format

// Dòng 1 chứa số nguyên dương N; Dòng 2 chứa N số nguyên của mảng A[] viết cách nhau một dấu cách

// Constraints

// 1<=N<=10^6; 1<=A[i]<=10^9;

// Output Format

// In ra kết quả của bài toán chia dư với 10^9 + 7

// Sample Input 0

// 6
// 8 1 7 9 8 1 
// Sample Output 0

// 116
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
#define INT 1000000007
int main() {
    int n; cin >> n; 
    ll a[n];
    ll res = 0;
    for (ll &i : a) cin >> i;
    sort(a, a+n);
    for (int i = 0;i<n;i++){
        res = 1ll*a[i]*i% INT + res%INT;
    }
    cout << res%INT;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
