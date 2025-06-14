// Cho mảng 2 chiều A gồm N hàng và N cột, hàng được đánh số từ 1 đến N từ trên xuống dưới, cột được đánh số từ 1 tới N từ trái sang phải, hãy tìm 1 đường đi từ một ô ở cột 1 tới 1 ổ ở cột N sao cho các phần tử trên đường đi đó là lớn nhất có thể. Biết rằng ở mỗi bước đi từ ô hiện tại (i, j) chỉ có thể đi sang phải (i, j + 1) hoặc đi xuống ô dưới bên phải (i + 1, j + 1), ô bên trên bên phải(i - 1, j + 1). Hãy tìm 1 đường đi có tổng các số trên đường đi là lớn nhất.

// image

// Input Format

// Dòng 1 là N

// N dòng tiếp theo mỗi dòng gồm N số

// Constraints

// 1<=N<=100
// -100<=A[i][j]<=100
// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 5
// 2 -8 2 9 0 
// -5 6 6 -1 6 
// 3 5 0 2 9 
// 9 -8 9 7 0 
// -4 6 1 -2 0 
// Sample Output 0
// 40
// Explanation 0
// Đường đi có tổng lớn nhất : 9 + 6 + 9 + 7 + 9 = 40
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
	cin >> n;
	vector<vector<ll>> dp(n+2, vector<ll>(n+2, 0));
	for (int i = 1; i<=n;i++){
		for (int j = 1; j<=n;j++) cin >> dp[i][j];
	}
	debug(dp);
	for (int j = 2; j<=n;j++){
		for (int i = 1; i<=n;i++){
			dp[i][j] += max({dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1]});
		}
	}
	debug(dp);
	ll res = -1e9;
	for (int i = 1;i<=n;i++){
		res = max(res, dp[i][n]);
	}
	cout << res;
	return 0;
}