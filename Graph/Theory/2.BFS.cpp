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
// Tim kiem theo chieu rong BFS !
// Ket qua cua input:
// Input: n, m va m la so canh cua do thi, n la so dinh, 
// sau do la so testcase sau do la dinh x, dinh y
// Neu x -> y thi in ra den duoc va in ra cach di 
// Nguoc lai in ra Khong di duoc 
// Sample Input:
// 11 8
// 1 3
// 3 2
// 3 4
// 4 5
// 5 7
// 5 8
// 9 10
// 9 11
// 2
// 2 8
// 1 10
// Sample Output: 
// YES
// NO
void in(){
	cin >> n >> m;
	for (int i = 1; i<= m;i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, 0, sizeof(visited));
}
void bfs(int u){
	queue<int> q; 
	q.push(u);
	visited[u] = true;
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int x : adj[v]){
			if (!visited[x]){
				q.push(x);
				visited[x] = true;
			}
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	in();
	int t; cin >> t;
	int dau, cuoi;
	while (t--){
		cin >> dau >> cuoi;
		memset(visited, 0, sizeof(visited));
		bfs(dau);
		if (!visited[cuoi]){
			cout << "YES" << endl;
		}
		else cout << "NO\n";
	}
	return 0;
}