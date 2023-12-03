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
void slove(){
    cin >> n;
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++) cin >> a[i][j];
    }
    for (int i = 1;i<=n;i++){
        for (int j =1;j<=n;j++){
            if (j==1){
                a[i][j] = max(a[i-1][j], a[i-1][j+1]) + a[i][j];
            }else if (j==n){
                a[i][j] = max(a[i-1][j-1], a[i-1][j]) + a[i][j];
            }
            else {
                a[i][j] = max({a[i-1][j-1], a[i-1][j], a[i-1][j+1]}) + a[i][j];
            }
        }
    }
    cout << *max_element(a[n], a[n] + n + 1);
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    slove();
}
// [DP]. Bài 36. Maximum path sum
// Problem
// Submissions
// Discussions
// Cho mảng 2 chiều A gồm N hàng và N cột, hãy tìm 1 đường đi từ dòng 1 tới dòng N sao cho các phần tử trên đường đi đó là lớn nhất có thể. Biết rằng ở mỗi bước đi từ ô hiện tại chỉ có thể đi xuống ô dưới bên trái, ô dưới bên phải hoặc ô dưới của ô hiện tại. Hãy tìm 1 đường đi có tổng các số trên đường đi là lớn nhất.

// Input Format

// Dòng 1 là N

// N dòng tiếp theo mỗi dòng gồm N số

// Constraints

// 1<=N<=100
// 1<=A[i][j]<=100
// Output Format

// In ra kết quả của bài toán

// Sample Input 0

// 5
// 5 1 8 6 7 
// 6 0 0 3 7 
// 3 4 1 5 3 
// 9 8 9 2 2 
// 5 3 4 5 3 
// Sample Output 0

// 33
// Explanation 0

// Đường đi có tổng lớn nhất : 7 + 7 + 5 + 9 + 5 = 33