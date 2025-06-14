// Cho mảng A[] gồm N phần tử chỉ bao gồm các số 0 và 1. Các số 0 được đặt trước các số 1. Hãy đếm các số 0 với thời gian log(N).

// Input Format

// Dòng 1 chứa số nguyên dương N; Dòng thứ 2 chứa N số nguyên của mảng A[]

// Constraints

// 1<=N<=10^6; 0<=A[i]<=1;

// Output Format

// In ra đáp án của bài toán, nếu số 0 không xuất hiện in ra 0

// Sample Input 0

// 6
// 0 0 1 1 1 1 
// Sample Output 0

// 2
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find(int a[], int l, int r){
    int res = -1;
    while (l <= r){
        int mid = (l+r)/2;
        if (a[mid]==1){
            res = mid;
            r = mid -1;
        }else{
            l = mid + 1;
        }
    }
    return res;
}
int main() {
    int n; cin >> n;
    int a[n+1];
    for (int i = 1;i<=n;i++) cin >> a[i];
    int res = find(a, 1, n);
    if (res == -1) cout << n;
    else if (res != 1) cout << res-1;
    else cout << 0;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
