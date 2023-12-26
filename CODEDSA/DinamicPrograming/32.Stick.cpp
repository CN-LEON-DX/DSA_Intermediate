//  Cho một bảng hình chữ nhật cỡ nxm hình vuông đơn vị, nhiệm vụ của bạn là đếm số cách lấp đầy hình chữ nhật này bằng cách viên gạch có cỡ 1x2 và 2x1.

// Input Format

// Dòng duy nhất chứa 2 số n và m.

// Constraints

// 1≤n≤10; 1≤m≤1000;

// Output Format

// In ra đáp án của bài toán chia dư với 1e9 + 7

// Sample Input 0
// 4 7
// Sample Output 0
// 781
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
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	cin >> n >> m;
	vector<vector<ll>> dp(n + 1, vector<ll>(m+1, 0));
	for (int i = 1;i<=n;i++){
		for (int j = 1; j<=m;j++){
			if (i > j) dp[i][j] = dp[i-1][j];
			else if (i < j) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
			else dp[i][j]= (dp[i][j-1] + 1)%MOD;
		}
	}
	cout << dp[n][m];
	return 0;
}
