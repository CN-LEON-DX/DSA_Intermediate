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

void sang(ll l , ll r){
    ll a[r - l + 1];
    for (int i = 0;i<r-l+1;i++) a[i] = 1;
    for (ll i = 2;i<=sqrt(r);i++){
        for (ll j = max(i*i, (l+i-1)/i*i);j<=r;j+=i){
            a[j-l] = 0;
        }
    }
    for (ll i = l;i<=r;i++){
        if (a[i-l]) cout << i << " ";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t = 1;
    while (t--){
        sang(10, 47);
    }
}