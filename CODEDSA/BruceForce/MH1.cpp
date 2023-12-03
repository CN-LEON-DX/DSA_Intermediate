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

void slove(){
    int n; cin >> n;
    int a[n+1];
    for (int i = 1;i<=n;i++) cin >> a[i];
    int f[n+1];
    f[1] = a[1];
    for (int i = 2;i<=n;i++){
        f[i] = a[i] - a[i-1];
    }
    for (int i = 1;i<=n;i++) cout << f[i] << " ";
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t = 1;
    while (t--){
        slove();
    }
}