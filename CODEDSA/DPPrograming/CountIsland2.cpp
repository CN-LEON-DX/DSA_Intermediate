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
int dx[8] = {-1, 0, 1 , 0, -1, -1, 1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
bool mark[51][51];
int cnt = 0;
void loang(int x, int y, int a[][51]){
    a[x][y] = -1;
    for (int i = 0;i<8;i++){
        if (x+dx[i]<n && x+dx[i]>=0 && y+dy[i] <m && y+dy[i]>=0 && a[x+dx[i]][y+dy[i]] == 1 && !mark[x+dx[i]][y+dy[i]]){
            mark[x+dx[i]][y+dy[i]] = true;
            loang(x+dx[i], y+dy[i], a);
        }
    }
}
void lg(int a[51][51]){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]==1 && !mark[i][j]){
                mark[i][j] = true;
                loang(i, j, a);
                cnt++;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int a[51][51];
    ll t = 1;
    while (t--){
        cin >> n >> m;
        for (int i = 0;i<n;i++)
        for (int j = 0;j<m;j++) cin >> a[i][j];
        lg(a);
    }
    cout << cnt << endl;
}