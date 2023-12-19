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

int n, m;
int a[101][101];
ll dp[101][101];
void slove(){
    cin >> n >> m;
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=m;j++) cin >> a[i][j];
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }
    cout << dp[n][m] << endl; // dp[n][m] is the maximum path sum from a[1][1] to a[n][m
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    slove();
}