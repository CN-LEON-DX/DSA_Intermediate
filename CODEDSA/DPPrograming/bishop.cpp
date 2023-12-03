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
int a[21][21];
int s, t;
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, 1, -1};
void slove(){
    cin >> n;
    cin >> s >> t;
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++) cin >> a[i][j];
    queue<pair<int, int>> q;
    q.push({s, t});
    int cnt = 0;
    a[s][t] = 1;
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        cnt++;
        for (int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && a[nx][ny] == 0){
                a[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    cout << cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t = 1;
    while (t--){
        slove();
    }
}