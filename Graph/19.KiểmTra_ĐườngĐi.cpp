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
int n, m, tc;
vector<int> a[1001];
int parent[1001];
bool visited[1001];
vector<int> loc(1001, 0);
int t = 1;
void in(){
	cin >> n >> m;
	for (int i = 1;i<= m;i++){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
	memset(loc, 0, sizeof(loc));
}
void dfs(int u){
	visited[u] = 1; 
	loc[u] = t;
	for (int v : a[u]){
		if (!visited[v]){
			loc[v] = t;
			dfs(v);
		}
	}
}
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
			dfs(i);
			t++;
		}
	}
	int tc; cin >> tc;
	while (tc--){
		int x, y; cin >> x >> y;
		if (loc[x] == loc[y]) cout << 1 << endl;
		else cout << -1 << endl;
	}
	return 0;
}
// Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh s và t có tồn tại đường đi tới nhau hay không ?

// Input Format

// Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị. Dòng tiếp theo là Q, Q dòng tiếp theo mỗi dòng chứa 2 đỉnh s, t cần truy vấn.

// Constraints

// 1<=s,t<=n<=1000; 1<=m<=n*(n-1)/2; 1<=Q<=10000;

// Output Format

// Đối với mỗi truy vấn in ra 1 nếu có đường đi giữa s và t, ngược lại in ra -1.

// Sample Input 0
// 5 3
// 5 4
// 4 1
// 4 3
// 3
// 4 5
// 4 2
// 3 4
// Sample Output 0
// 1
// -1
// 1