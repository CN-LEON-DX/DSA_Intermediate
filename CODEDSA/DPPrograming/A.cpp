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
    int n, s; cin >> n >> s;
    int a[n+1];
    fore(i, 1, n+1) cin >> a[i];
    int l = 1, r = 1;
    ll sum = 0;
    int maxdis = 0;
    while (l<=n){
        sum += a[r];
        if (sum <= s){
            maxdis = max(maxdis, r-l+1);
            r++;
        }else{
            l++;
            sum-=a[l];
        }
    }
    cout << maxdis << nl;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t=1;
    while (t--){
        slove();
    }
}