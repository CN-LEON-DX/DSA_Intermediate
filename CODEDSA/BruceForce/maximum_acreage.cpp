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
int a[501][501];
int mark[501][501];
int max_cnt = 1;
int dx[] = {0, 0 , 1, -1};
int dy[] = {1, -1, 0, 0};
int loang(int x, int y, int cnt){
    queue<pair<int,int>> q;
    q.push({x, y});
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        cnt++;
        for (int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx>=1 && nx <= n && ny <= m && ny >=1 && a[nx][ny] == 1 && mark[nx][ny]==0){
                mark[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return cnt;
}
void slove(){
    int cnt;
    cin >> n >> m;
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            if (a[i][j]==1 && mark[i][j]==0){
                mark[i][j] = 1;
                cnt = 0;
                max_cnt = max(max_cnt, loang(i, j, cnt));
            }
        }
    }
    cout << max_cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    slove();
}