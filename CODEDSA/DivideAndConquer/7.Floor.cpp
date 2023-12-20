// Cho mảng đã được sắp xếp A[] gồm N phần tử không có hai phần tử giống nhau và số X. Nhiệm vụ của bạn là tìm floor(X). Trong đó, K=floor(X) là phần tử lớn nhất trong mảng A[] nhỏ hơn hoặc bằng X.

// Input Format

// Dòng 1 chứa 2 số N và X; Dòng 2 chứa N số của mảng A[]

// Constraints

// 1<=N<=10^5; 1<=X,A[i]<=10^6;

// Output Format

// In ra đáp án của bài toán nếu tìm thấy số lớn hơn X, trường hợp không tìm thấy in -1

// Sample Input 0

// 9 8
// 1 2 3 4 5 6 7 8 9 
// Sample Output 0

// 8
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int bnr(int a[], int l, int r, int k){
    int res = -1;
    while (l <= r){
        int mid = (l + r)/2;
        if (a[mid] <= k){
            res = a[mid];
            l = mid + 1;
        }else r = mid - 1;
    }
    return res;
}
int main() {
    int n, k; cin >> n >> k;
    int a[n+1];
    for (int i = 1;i<=n;i++) cin >> a[i];
    sort(a+1, a+n+1);
    cout << bnr(a, 1, n, k);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
