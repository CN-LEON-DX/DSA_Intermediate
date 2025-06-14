// Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự. Hãy tìm xâu con đối xứng dài nhất của S.

// Input Format

// Dòng duy nhất chứa xâu S

// Constraints

// 1<=len(S)<=1000;

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// edhcgeehahbbeggfcgcchffbffcgfghgc
// Sample Output 0

// 5

#include <bits/stdc++.h>
using namespace std;
// Run Time 
#define TIME cout << "\nTime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s"
// Debug
void __print(int x) {cerr <<	 x;}
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

int main(){
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("in.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
	#endif
	string s; cin >> s;
	int n = s.size();
	s = "z" + s;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	// Khoi tao ma tran cho dp truoc i = j => dp = 1;
	// F[i][j] = F[i][j] && F[i +1 ][j - 1];
	for (int i = 0;i<=n;i++){
		dp[i][i] = 1;
	}
	int res = 1;
	for (int len = 2; len <= n; len++){
		for (int i = 1; i <= n - len + 1; i++){
			int j = i + len - 1;
			if (len == 2){
				if (s[i]==s[j]) dp[i][j] = 1;
			}else{
				dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
			}
			if (dp[i][j]){
				res = max(res, len);
			}
		}
	}
	debug(dp);
	cout << res;
    return 0;
}