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
int disc[1001], low[1001];
// Mảng disc lưu thời gian duyệt đến cho phần tử đó
// Mảng low là thời gian thăm sớm nhất của một đỉnh có thể đi tới được từ 
// một cây con có gốc là u
int visited[1001];
int in_stack[1001];
stack<int> st;
int timer = 0, scc = 0;
void in(){
	cin >> n >> m; 
	for (int i = 1; i<=m;i++){
		int x, y; cin >> x >> y; 
		a[x].push_back(y);
	}
	memset(visited, 0, sizeof(visited));
}
void dfs(int u){
	visited[u] = 1; in_stack[u] = 1;
	disc[u] = low[u] = ++timer;
	st.push(u);
	// Ban đầu gán cho các đỉnh có low và disc giống nhau là thời gian duyệt đến chúng
	for (int v : a[u]){
		if (!visited[v]){
			dfs(v);
			low[u] = min(low[u], low[v]);
			// Nếu chưa duyệt tới thì nó cần cho low = low của các phần tử kề 
		}else{
			low[u] = min(low[u], disc[v]);
			// Nếu gặp lại thì cần cho đỉnh u = min low của u và v 
		}
	}
	if (low[u] == disc[u]){
		++scc;
		while (st.top() != u){
			cout << st.top() << " ";
			in_stack[st.top()] = 0;
			st.pop();
		}
		cout << st.top() << endl;
		in_stack[st.top()] = false;
		st.pop();
	}
}
int main(){
	#ifndef OK
	// for getting input from input.txt
	freopen("in.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
	#endif
	in();
	for( int i = 1; i<= n;i++){
		if (!visited[i]){
			dfs(i);
		}
	}
	cout << "So luong thanh phan lien thong la : " << scc << endl;
	return 0;
}