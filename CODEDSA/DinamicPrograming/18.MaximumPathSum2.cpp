// Cho bảng A[] kích thước N x M (N hàng, M cột). Bạn được phép đi xuống dưới, đi sang phải và đi xuống ô chéo dưới về bên phải. Khi đi qua ô (i, j), điểm nhận được bằng A[i][j]. Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao cho tổng điểm là lớn nhất.

// Input Format

// Dòng 1 gồm số nguyên dương N và M; N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j];

// Constraints

// 1<=N,M<=500; 1<=A[i][j]<=1000;

// Output Format

// In ra kết quả của bài toán

// Sample Input 0

// 5 5
// 1 0 31 5 25 
// 28 26 32 46 7 
// 26 40 36 13 16 
// 7 26 14 6 11 
// 42 45 11 10 21 
// Sample Output 0

// 208
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
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("in.txt", "r", stdin);
    // for writing output to output.txt
    freopen("out.txt", "w", stdout);
    #endif
    cin >> n >> m;
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0ll));
    for (int i = 1;i<=n;i++){
        for (int j = 1; j<=m;j++) cin >> dp[i][j];
    }
    debug(dp);
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            dp[i][j] += max({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
        }
    }
    cout << dp[n][m];
    return 0;
}