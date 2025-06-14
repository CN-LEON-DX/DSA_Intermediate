// Cho mê cung được mô tả bởi một ma trận kí tự gồm N hàng và N cột. Mỗi ô trên ma trận chứa kí tự '.' tương ứng với đường đi và dấu * tương ứng với bẫy. Một con chuột muốn đi từ ô (1, 1) tới ô (N, N) và chỉ được di chuyển khi một ô nào đó là đường đi và nó được di chuyển sang phải hoặc xuống dưới. Hãy đếm số cách con chuột có thể di chuyển tới đích. Vì kết quả quá lớn nên hãy lấy dư với 10^9 + 7

// Input Format

// Dòng đầu tiên là N; N dòng tiếp theo mỗi dòng là N kí tự

// Constraints

// 1<=N<=1000

// Output Format

// Số đường đi tối đa

// Sample Input 0

// 4
// ....
// .*..
// ...*
// *...
// Sample Output 0

// 3
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
int n;
int main(){
    cin >> n;
    vector<vector<char>> a(n+1, vector<char>(n+1));
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for (int i = 1;i<=n;i++){
        for (int j = 1; j<=n;j++) {
            cin >> a[i][j];
        }
    }
    if (a[1][1]=='*') {
        cout << 0;
        return 0;
    }
    dp[1][1] = 1;
    for (int i = 1; i<=n;i++){
        for (int j = 1;j<=n;j++){
            if (a[i][j] != '*'){
                dp[i][j] += (dp[i-1][j] + dp[i][j-1])%MOD;
            }
        }
    }
    debug(dp);
    cout << dp[n][n];
    return 0;
}