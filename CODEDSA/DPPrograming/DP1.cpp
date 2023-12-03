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
void slove(){
    cin >> n; cin >> m;
    int a[n+1];
    ll f[n+1];
    fore(i, 1, n){
        cin >> a[i];
    }
    f[1] = a[1];
    for (int i = 2;i<=n;i++) f[i] = f[i-1] + a[i];

    while (m--){
        int x, y; cin >> x >> y;
        cout << f[y] - f[x-1] << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t = 1;
    while (t--){
        slove();
    }
}