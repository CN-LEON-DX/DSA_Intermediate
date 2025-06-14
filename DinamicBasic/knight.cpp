#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <queue>
using namespace std;

const int N = 101;
int n;
int a[N][N];
const int knx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int kny[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

void slove(){
    cin >> n;
    int s, t, u, v; cin >> s >> t >> u >> v;
    for (int i = 1;i<=n;++i){
        for (int j = 1;j<=n;++j){
            cin >> a[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({s, t});
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        if (x==u && y==v){
            cout << "YES\n";
            return;
        }
        a[x][y] = 0;
        for (int i = 0;i<8;i++){
            int nx = x + knx[i];
            int ny = y + kny[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && a[nx][ny] == 1){
                q.push({nx, ny});
            }
        }
    }
    cout << "NO\n";
}

int main() {
    slove();
    return 0;
}