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
bool visited[1001];
int parent[1001];
void in(){
	cin >> n >> m; 
	for (int i = 1; i<= m;i++){
		int x, y; cin >> x >> y; 
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));
}
bool dfs(int u){
	visited[u] = 1; 
	for (int v : a[u]){
		if (visited[v] && v != parent[u]){
			return true;
		}
		else if (!visited[v]){
			parent[v] = u;
			if (dfs(v)) return true;
		}
	}
	return false;
}
bool bfs(int u){
	queue<int> q; 
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		visited[v] = true;
		for (int x : a[v]){
			if (visited[x] && x != parent[v]){
				return true;
			}
			else if (!visited[x]){
				parent[x] = v;
				q.push(x);
			}
		}
	}
	return false;
}
int main(){
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("in.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
	#endif
	in();
	// Kiểm tra tất cả các đỉnh xem có liên thông hay không ? 
	for (int i =1 ; i<= n;i++){1
		if (!visited[i]){
			if (dfs(i)){
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}
// Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy xác định xem đồ thị có tồn tại chu trình hay không? Bài này các bạn cài đặt bằng 3 phương pháp : DFS, BFS và DSU.

// Input Format

// Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

// Constraints

// 1<=n<=1000; 1<=m<=n*(n-1)/2;

// Output Format

// In ra 1 nếu đồ thị tồn tại chu trình, ngược lại in ra 0.

// Sample Input 0

// 10 11
// 10 5
// 10 4
// 10 1
// 10 3
// 5 2
// 5 4
// 10 8
// 5 3
// 5 1
// 10 6
// 10 9
// Sample Output 0

// 1