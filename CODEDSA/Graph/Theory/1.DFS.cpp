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
vector<int> adj[1001];
bool visited[1001];
int vt = 0;
int luuvt[1001];
int parent[1001];
int t = 0;

void in(){
	cin >> n >> m;
	for (int i = 1; i<= m;i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}
void dfs(int u){
	visited[u] = true;
	luuvt[u] = t;
	for (int v : adj[u]){
		if (!visited[v]){
			luuvt[v] = t;
			parent[v] = u; // Lưu vị trí parent của phần tử trước nó
			visited[v] = true;
			dfs(v);
		}
	}
}
void dfs1(int u){
	visited[u] = true;
	for (int v : adj[u]){
		if (!visited[v]){
			parent[v] = u; // Lưu vị trí parent của phần tử trước nó
			dfs1(v);
		}
	}
}
// Yêu cầu 1: hiện kết quả tìm kiếm từ phần tử i -> đến phần tử j
// Yêu cầu 2: Hiện số luồng liên thông của đồ thị 
// Yêu cầu 3: Kiểm tra xem đồ thị có phải là đồ thị Ơ-le hay không ?
// Testcase
// Input: n và m ở dòng đầu là số đỉnh và số cạnh của đồ thị
// // Sau đó là các cạnh của đồ thị
// 11 8
// 1 3
// 3 2
// 3 4
// 4 5
// 5 7
// 5 8
// 9 10
// 9 11

// Test1: 1 8 => YES, 1 10 => NO
// Test 2: 2
// Test 3: NO
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	in();
	// YC1:
	// Ta có thể dùng dfs từ một đỉnh để xem có đường đi hay không 
	// Nhưng nếu đề bài cho nhiều testcase thì điều đó có thể bị timelimit
	// Do vậy ta cần dùng đến một mảng đánh dấu các phần tử của một luồng thành phần có cùng nhau hay không

	int tc; cin >> tc;
	int dau, cuoi;
	// Duyet tat cả các luồng thành phần có thể có của đồ thị trên !
	parent[1] = 0;
	memset(parent, 0, sizeof(parent));
	for (int i = 1; i<= n;i++){
		if (!visited[i]){
			t++;
			dfs(i);
		}
	}
	for (int i = 1; i<= n;i++){
		cout << luuvt[i] << " ";
	}
	cout << endl;
	while (tc--){
		memset(parent, 0, sizeof(parent));
		memset(visited, 0, sizeof(visited));
		cin >> dau >> cuoi;
		debug(dau, cuoi);
		if (luuvt[cuoi] == luuvt[dau]){
			dfs1(dau);
			// Ta dung mang parent để đánh dấu các vị trí của phần tử đang loang 
			// Ta sẽ truy vết mà nếu tìm thấy như sau: 
			vector<int> res;
			debug(res);
			cout << "Duong di tu " << dau << " den " << cuoi << " la: ";
			while (cuoi != dau){
				res.push_back(cuoi);
				cuoi = parent[cuoi];
			}
			res.push_back(dau);
			reverse(res.begin(), res.end());
			debug(res);
			for (int x : res) cout << x << " ";
			cout << endl;
		}else{
			cout << "Khong co duong di!" << endl;
		}
	}
	return 0;
}