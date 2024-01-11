#include <bits/stdc++.h>
using namespace std;
// Time
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
int main(){
    #ifndef CNLEON
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<vector<int>> dp(n+2, vector<int>(n+1, 0));
    for (int i = 1;i<=n;i++){
        for (int j = 1; j<=n;j++){
            cin >> dp[i][j];
        }
    }
    debug(dp);
    for (int j = 1; j<=n;j++){
        for (int i = 1; i<= n;i++){
            dp[i][j] += max({dp[i+1][j-1], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    debug(dp);
    int res = -1e9;
    for (int i = 1; i<= n;i++){
        res = max(res, dp[i][n]);
    }
    cout << res;
    return 0;
}