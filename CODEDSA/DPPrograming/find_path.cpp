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
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void slove(){
    cin >> n >> m;
    int s, t, u, v; cin >> s >> t >> u >> v;
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=m;j++) cin >> a[i][j];
    queue<pair<int, int>> q;
    q.push({s, t});
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        if (x == u && y == v){
            cout << "YES" << endl;
            return;
        }
        else {
            for (int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == 1){
                    a[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << "NO" << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    slove();
}