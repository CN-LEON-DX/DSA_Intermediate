#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fore(i,b,a) for(int i = b; i<a; i++)
#define null NULL
#define nl '\n'
#define yes "YES\n"
#define no "NO\n"
using namespace std;

int n; 
int a[101][101];
int max_sum = -1e9;
void slove(){
    cin >> n;
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++) cin >> a[i][j];
    for (int i = 1;i<=n-2;i++){
        for (int j = 1;j<=n-2;j++){
            int I = i + 2, J = j + 2;
            int sum = 0; 
            for (int k = i;k<=I;k++){
                for (int l = j;l<=J;l++){
                    sum += a[k][l];
                }
            }
            max_sum = max(max_sum, sum);
        }
    }
    cout << max_sum;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t = 1;
    while (t--){
        slove();
    }
}

// [Mảng 2 Chiều]. Bài 28. Hình vuông lớn nhất
// Problem
// Submissions
// Discussions
// Cho mảng 2 chiều A gồm N hàng và N cột, hãy xét tất cả các hình vuông con cỡ 3x3 của mảng A, hãy tìm hình vuông có có tổng lớn nhất đó.

// Input Format

// Dòng 1 là N

// N dòng tiếp theo mỗi dòng gồm N số

// Constraints

// 3<=N<=100
// 100<=A[i][j]<=100
// Output Format

// In ra tổng lớn nhất của hình vuông cỡ 3x3

// Sample Input 0

// 6
// 4 6 4 5 8 2 
// 8 0 9 0 1 4 
// 3 5 3 6 3 4 
// 5 7 0 9 5 9 
// 4 5 5 9 6 3 
// 9 2 3 6 1 8 
// Sample Output 0

// 56