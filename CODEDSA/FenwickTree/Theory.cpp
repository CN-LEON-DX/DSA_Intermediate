// Cài cây fenwick tree BIT để thực hiện đối phó với mấy bài cần tối ưu thời gian là LogN
// Ví dụ cho bài sau:
// Cho mảng n phần tử a. Hãy tính tổng các phần tử từ chỉ số l -> r và hiện ra
// Constraints: 1<=n<=10^6, 1<=a[i]<=10^9
// Input:
// 6
// 1 9 2 4 2 7
// 2 5
// Output: 17
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
const int max_int = 10;
typedef long long ll;
int n;
vector<ll> BIT(max_int, 0);
vector<int> a(max_int, 0);
void update(int pos, int value){
	for (; pos <= n; pos += pos & (-pos)){
		BIT[pos] += value;
	}
}
ll query(int pos){
	ll sum = 0;
	for (; pos>0;pos -= pos & (-pos)){
		sum += BIT[pos];
	}
	return sum;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("D:/MYGIT/DSA_Intermediate/CODEDSA/FenwickTree/in.txt", "r", stdin);
	freopen("D:/MYGIT/DSA_Intermediate/CODEDSA/FenwickTree/out.txt", "w", stdout);
	#endif
	cin >> n;
	for (int i = 1; i<=n;i++){
		cin >> a[i];
		update(i, a[i]);
	}
	int l, r;
	cin >> l >> r;
	cout << query(r) - query(l-1);
	return 0;
}