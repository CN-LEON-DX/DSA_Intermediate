#include <bits/stdc++.h>
using namespace std;
// Run Time 
#define TIME cout << "\nTime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s"
// Debug
void __print(int x) {cerr << x;} void __print(long x) {cerr << x;} void __print(long long x) {cerr << x;} void __print(unsigned x) {cerr << x;} void __print(unsigned long x) {cerr << x;} void __print(unsigned long long x) {cerr << x;} void __print(float x) {cerr << x;} void __print(double x) {cerr << x;} void __print(long double x) {cerr << x;} void __print(char x) {cerr << '\'' << x << '\'';} void __print(const char *x) {cerr << '\"' << x << '\"';} void __print(const string &x) {cerr << '\"' << x << '\"';} void __print(bool x) {cerr << (x ? "true" : "false");} template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";} void _print() {cerr << "]\n";}
template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
typedef pair<int,int> ii;
const int dx[4] = {-1, +0, +1, +0}; const int dy[4] = {+0, +1, +0, -1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1}; const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
const int MOD = 1e9+7; typedef long long ll;
// Yêu cầu thêm vào các đỉnh và chỉ ra rằng đồ thị có bao nhiêu đồ thị có bao tplt ?
// Đồ thị input là đồ thị vô hướng 
// Input: 
// 7 7
// 1 2
// 2 3 
// 3 1 
// 4 5 
// 5 6 
// 6 7
// 7 5
// Output: 2 
int n, m;
int t = 0;
int parent[1001], sz[1001];
void init(){
	cin >> n >> m;
	for (int i = 1; i<= n;i++){
		parent[i] = i;
		sz[i] = 1;
	}
}
int Find(int u){
	if (u == parent[u]) return u;
	else return Find(parent[u]);
}
bool Union(int u, int v){
	u = Find(u);
	v = Find(v);
	if (u==v) return false;
	if (sz[u] < sz[v]){
		swap(u, v);
	}
	sz[u] += sz[v];
	parent[v] = u;
	t++;
	return true;
}
int main(){
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("in.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
	#endif
	init();
	for (int i = 1; i<=m;i++){
		int x, y; cin >> x >> y;
		Union(x, y);
	}
	// Tim so luong tplt:
	cout << n - t;
	return 0;
}
