// Cho hai mảng đã được sắp xếp A[], B[] gồm N, M phần tử theo thứ tự và số K. Nhiệm vụ của bạn là tìm phần tử ở vị trí số K sau khi trộn hai mảng để nhận được một mảng được sắp xếp.

// Input Format

// Dòng đầu tiên chứa 3 số N, M, K; Dòng thứ 2 chứa N số nguyên của mảng A[]; Dòng thứ 3 chứa M số nguyên của mảng B[];

// Constraints

// 1<=N,M<=10^4; 1<=K<=N+M; 1<=A[i],B[i]<=10^6

// Output Format

// In ra đáp án của bài toán

// Sample Input 0
// 7 9 14
// 4 6 7 9 10 10 10 
// 1 1 2 5 7 8 8 9 10 
// Sample Output 0
// 10
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int INT = 10001;
const int INT2 = 20001;
int n, m, k;
int a[INT], b[INT], c[INT2];

int main() {
    cin >> n >> m >> k;
    for (int i = 1;i<=n;i++) cin >> a[i];
    for (int i = 1;i<=m;i++) cin >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);

    int i1 = 1;
    int i2 = 1;
    int cnt = 1;
    while (i1 <= n && i2 <=m){
        if (a[i1] < b[i2]){
            c[cnt++] = a[i1];
            i1++;
        }else {
            c[cnt++] = b[i2];
            i2++;
        }
    }
    while (i1 <= n){
        c[cnt++] = a[i1];
        i1++;
    }
    while (i2 <= m){
        c[cnt++] = a[i2];
        i2++;
    }
    cout << c[k];
    /* Entfer your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
