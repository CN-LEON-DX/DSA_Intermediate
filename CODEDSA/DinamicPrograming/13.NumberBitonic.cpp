// Một dãy số được gọi là Bi-tonic nếu nó được chia thành hai dãy đầu tăng dần và dãy tiếp theo giảm dần. Nhiệm vụ của bạn là tìm tổng lớn nhất dãy con Bi-tonic của dãy số A[]. Ví dụ với dãy A[] = {1, 15, 51, 45, 33, 100, 12, 18, 9} ta có kết quả là 194 tương ứng với dãy Bi-tonic {1, 15, 51, 100, 18, 9}.

// Input Format

// Dòng đầu tiên đưa vào N là số phần tử của dãy A[]; Dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống

// Constraints

// 1<=N<=100; 1<=A[i]<=100;

// Output Format

// In ra kết quả của bài toán

// Sample Input 0

// 8
// 7 8 8 19 3 6 2 15 
// Sample Output 0

// 49
// Sample Input 1
// 9
// 1 15 51 45 33 100 12 18 9
// Sample Output 1
// 194

// Cách làm:
// Bạn cần tạo hai mảng, một để lưu tổng lớn nhất của dãy con tăng và một để lưu tổng lớn nhất của dãy con giảm. Sau đó, bạn tìm tổng lớn nhất của hai dãy con tại mỗi vị trí và trả về tổng lớn nhất.

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
	vector<int> a(n+1);
	for (int i = 1; i<=n;i++) cin >> a[i];
	vector<int> dp(n+1, 0);
	vector<int> dp1(n+1, 0);
	for (int i = 1;i<=n;i++){
		dp[i] = a[i];
		for (int j = 1;j<i;j++){
			if (a[i] > a[j]){
				dp[i] = max(dp[i], dp[j] + a[i]);
			}
		}
	}
	for (int i = n;i>=1;i--){
		dp1[i] = a[i];
		for (int j = n;j>i;j--){
			if (a[i] > a[j]){
				dp1[i] = max(dp1[i], dp1[j] + a[i]);
			}
		}
	}
	debug(dp);
	debug(dp1);
	int res = 0;
	for (int i = 1;i<=n;i++){
		res = max(res, dp[i]+dp1[i]-a[i]);
	}	
	cout << res;
	return 0;
}