// Cho mảng A[] gồm N số nguyên không âm và số K. Nhiệm vụ của bạn là hãy chia mảng A[] thành hai mảng con có kích cỡ K và N-K sao cho hiệu giữa tổng hai mảng con là lớn nhất. Ví dụ với mảng A[] = {8, 4, 5, 2, 10}, K=2 ta có kết quả là 17 vì mảng A[] được chia thành hai mảng {4, 2} và { 8, 5,10} có hiệu của hai mảng con là 23-6=17 là lớn nhất.

// Input Format

// Dòng duy nhất chứa 2 số nguyên N và K; Dòng thứ 2 gồm N số của mảng A[]

// Constraints

// 1<=K<=N<=10^6; 0<=A[i]<=10^9;

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 6 4
// 3 10 10 7 5 2 
// Sample Output 0

// 27
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k; cin >> n >> k;
    int mine = min(k, n-k);
    int a[n];
    for (int &i : a) cin >> i;
    sort(a, a+n);
    ll res = 0;
    for (int i = 0;i<n;i++){
        if (i < mine) res += a[i];
    }
    cout << accumulate(a, a+n, 0ll) - 2*res;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
