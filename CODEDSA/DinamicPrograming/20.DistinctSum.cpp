// Cho mảng A[] gồm N phần tử là số nguyên dương, xét tất cả các tập con của A[] và tính tổng các phần tử trong tập này (bao gồm cả tập rỗng), sau đó liệt kê các tổng khác nhau có thể tạo thành theo thứ tự tăng dần.

// Input Format

// Dòng đầu tiên là N : số lượng phần tử trong mảng; Dòng thứ 2 gồm N phần tử của mảng A[]

// Constraints

// 1<=N<=100; 1<=A[i]<=100;

// Output Format

// In ra các tổng có thể tạo thành từ các tập con của A[]

// Sample Input 0

// 3
// 4 1 2 
// Sample Output 0

// 0 1 2 3 4 5 6 7 
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
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i<=n;i++) cin >> a[i];
	sort(a.begin(), a.end());
	int s = accumulate(a.begin()+1, a.end(), 0);
	vector<bool> dp(s + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++){
	    for (int j = s; j >= a[i]; j--){
	        dp[j] = dp[j] || dp[j - a[i]];
	    }
	}
	for (int i = 0; i <= s; i++){
	    if (dp[i]) cout << i << " ";
	}

	return 0;
}