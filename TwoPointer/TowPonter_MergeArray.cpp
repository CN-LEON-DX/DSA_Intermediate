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
    cin >> n >> m;
    int a[n+1];
    for (int i = 1;i<=n;i++) cin >> a[i];
    int b[m+1];
    for (int i = 1;i<=m;i++) cin >> b[i];
    int i = 1, j = 1;
    while (i<=n && j<=m){
        if (a[i]<b[j]){
            cout << a[i] << " ";
            i++;
        }else{
            cout << b[j] << " ";
            j++;
        }
    }
    while (i<=n){
        cout << a[i] << " ";
        i++;
    }
    while (j<=m){
        cout << b[j] << " ";
        j++;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    slove();
}