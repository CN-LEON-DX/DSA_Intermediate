// Cho ma trận A các số nguyên có N hàng và M cột. Tìm đường đi từ ở [1, 1] tới ô [N, M] sao cho tổng các số trên đường đi là lớn nhất có thể, biết rằng ở mỗi bước chỉ có thể đi từ ô hiện tại xuống ô phía dưới hoặc đi sang phải.

// Input Format

// Dòng đầu tiên N và M. N dòng tiếp theo mỗi dòng gồm M phần tử.

// Constraints

// 1≤N,M≤100; 1≤A[i][j]≤10^9

// Output Format

// In ra đường đi có tổng lớn nhất.

// Sample Input 0

// 3 3
// 1 2 2
// 3 10 2
// 5 7 2
// Sample Output 0

// 23
// Explanation 0

// Giải thích : Đường đi được chọn (1, 1) -> (2, 1) -> (2, 2) -> (3, 2) -> (3, 3)

#include <bits/stdc++.h>
using namespace std;
// Run Time 
#define TIME cout << "\nTime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s"
// Debug
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
typedef pair<int,int> ii;
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
const int MOD = 1e9+7;
typedef long long ll;
int n, m;

int main(){
    cin >> n >> m;
    vector<vector<ll>> dp(n+2, vector<ll>(m+2, 0ll));
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            cin >> dp[i][j];
        }
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            dp[i][j] += max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[n][m];
    return 0;
}