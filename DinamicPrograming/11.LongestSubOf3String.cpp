// Cho ba xâu ký tự X, Y, Z. Nhiệm vụ của bạn là tìm độ dài dãy con chung dài nhất có mặt trong cả ba xâu.

// Input Format

// 3 dòng lần lượt chứa X, Y, Z;

// Constraints

// 1<=len(X), len(Y), len(Z) <= 100;

// Output Format

// In ra độ dài của xâu con chung dài nhất của 3 xâu

// Sample Input 0
// AGLEHHGE
// GLGHLALB
// DDLBLEHGD
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
int n;
int main(){
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("in.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
	#endif
	string x, y, z; cin >> x >> y >> z;
	int n1 = x.size(), n2 = y.size(), n3 = z.size();
	vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3+1, 0)));
	for (int i = 1; i <= n1; i++) {
	    for (int j = 1; j <= n2; j++) {
	        for (int k = 1; k <= n3; k++) {
	            if (i==j && j == k){
	            	dp[i][j][k] = 1;
	            }
	        }
	    }
	}
	debug(dp);
	for (int i = 1; i <= n1; i++) {
	    for (int j = 1; j <= n2; j++) {
	        for (int k = 1; k <= n3; k++) {
	            if (x[i - 1] == y[j - 1] && y[j - 1] == z[k - 1]) {
	                dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
	            } else {
	                dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
	            }
	        }
	    }
	}
	cout << dp[n1][n2][n3];
	return 0;
}