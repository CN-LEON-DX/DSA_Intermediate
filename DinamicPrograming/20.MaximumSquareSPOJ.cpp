// Bạn được cung cấp một ma trận nhị phân có N dòng và M cột chỉ bao gồm các số 0 và 1, hãy tìm hình vuông lớn nhất trong ma trận mà chỉ chứa toàn số 1.

// Input Format

// Dòng đầu tiên gồm 2 số N và M; N dòng tiếp theo mỗi dòng M số nguyên;

// Constraints

// 1<=N,M<=500; 0<=A[i][j]<=1;

// Output Format

// In ra kết quả đáp án của bài toán

// Sample Input 0

// 4 4
// 1 1 0 0
// 1 1 1 1
// 1 1 0 1
// 1 0 1 0
// Sample Output 0

// 2
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
    vector<vector<int>> a(n+1, vector<int>(m+1));
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i =1;i<=n;i++){
        for (int j = 1;j<=m;j++) cin >> a[i][j];
    }
    debug(a);
    for (int i = 1; i<=n;i++){
        for (int j = 1; j<=m;j++){
            if ((i==1 || j == 1) && a[i][j]==1) dp[i][j] = 1;
            else {
                if (a[i][j]==1) dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
        }
    }
    debug(dp);
    int res = 0;
    for (int i = 1; i<=n;i++){
        for (int j = 1; j<=m;j++){
            res = max(dp[i][j], res);
        }
    }
    cout << res;
    return 0;
}