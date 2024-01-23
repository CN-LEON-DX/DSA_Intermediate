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
int n, m;
vector<int> a[1001];
int visited[1001], AP[1005];
int disc[1001], low[1001];
stack<int> st;
int timer = 0;
void in(){
	cin >> n >> m;
	for (int i = 1;i<=m;i++){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		//a[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
	memset(AP, false, sizeof(AP));
}
// Xây các mảng disc và low để tìm các đỉnh trụ
void dfs(int u, int par){
	visited[u] = 1;
	disc[u] = low[u] = ++timer;
	int child = 0;
	for (int v : a[u]){
		if (v==par) continue;
		if (!visited[v]){
			dfs(v, u);
			++child;
			low[u] = min(low[u], low[v]);
			if (par != -1 && disc[u] <= low[v]){
				AP[u] = true;
			}
		}
		else{
			low[u] = min(low[u], disc[v]);
		}
	}
	if (par == -1 && child > 1) AP[u] = true;
}
// Tìm đỉnh trụ có 2 phần 
// 1 là đỉnh trụ có thể là đỉnh xuất phát có số lg cạnh kề >= 2
// Hai là đỉnh mà khi duyệt các cạnh kề mà cạnh kề lại có low nhỏ hơn low của disc
// Từ đó ta có cách làm sau
int main(){
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("in.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
	#endif
	in();
	for (int i = 1; i<= n;i++){
		if (!visited[i]){
			dfs(i, -1);
		}
	}
	for (int i = 1; i<=n;i++){
		if (AP[i]) cout << i << " ";
	}
	return 0;
}
// Dùng thuật toán tarjan để kiểm tra đỉnh trụ:
	// Có 2 trường hợp là: 
	//   + Ta duyệt đỉnh trụ gốc xuất phát 
	// 	 + Ta đuyệt đỉnh khác gốc 
	// Nếu mà lả đỉnh xuất phát nếu nó có nhiều hơn 2 cạnh kề thì kết luận nó là đỉnh trụ
	// Nếu mà chỉ có 1 đường xuất phát tới các đỉnh khác 
	// Trường hợp còn lại nếu các đỉnh này khác đỉnh gốc mà khi ta dfs mà đỉnh v có phần 
	// low[v] >= low[u] => Ta ghi nhận một đỉnh trụ 
	// Yêu cầu tìm các đỉnh trụ với yêu cầu độ phức tạp nhỏ: 
	// Ví dụ: 
	// INPUT:
	// 7 8
	// 1 2
	// 2 3
	// 3 1
	// 3 4
	// 4 5
	// 5 6
	// 6 7
	// 7 5
	// OUTPUT: 3 4 5
