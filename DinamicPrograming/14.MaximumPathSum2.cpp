// Cho mảng 2 chiều A gồm N hàng và N cột, hãy tìm 1 đường đi từ dòng 1 tới dòng N sao cho các phần tử trên đường đi đó là lớn nhất có thể. Biết rằng ở mỗi bước đi từ ô hiện tại chỉ có thể đi xuống ô dưới bên trái, ô dưới bên phải hoặc ô dưới của ô hiện tại. Hãy tìm 1 đường đi có tổng các số trên đường đi là lớn nhất.

// Input Format

// Dòng 1 là N

// N dòng tiếp theo mỗi dòng gồm N số

// Constraints

// 1<=N<=100
// 1<=A[i][j]<=100
// Output Format

// In ra kết quả của bài toán

// Sample Input 0

// 5
// 5 1 8 6 7 
// 6 0 0 3 7 
// 3 4 1 5 3 
// 9 8 9 2 2 
// 5 3 4 5 3 
// Sample Output 0

// 33
// Explanation 0
// Đường đi có tổng lớn nhất : 7 + 7 + 5 + 9 + 5 = 33
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
	vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
	for(int i = 1; i<=n;i++){
		for (int j = 1;j<=n;j++){
			cin >> dp[i][j];
		}
	}
	for(int i = 1; i<=n;i++){
		for (int j = 1;j<=n;j++){
			dp[i][j] += max({dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]});
		}
	}
	cout << *max_element(dp[n].begin(), dp[n].end());
	return 0;
}