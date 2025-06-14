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
int dx[8] = {0,0,1,-1,1,-1,1,-1};
int dy[8] = {1,-1,0,0,1,-1,-1,1};
int cnt = 0;
int n, m;
bool check(int x, int y, vector<vector<int>> &a){
    int temp = a[x][y];
    for (int i = 0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m){
            if (a[nx][ny] >= a[x][y]) return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0;i<n;i++)
        for (int j = 0;j<m;j++) cin >> a[i][j];

    for (int i = 0;i<n;i++){
        for (int j = 0;j<m;j++){
            if (check(i, j, a)){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}