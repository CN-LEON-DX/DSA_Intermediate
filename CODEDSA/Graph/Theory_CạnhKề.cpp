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
vector<pair<int, int>> ke;
void in(){
	cin >> n >> m;
	for (int i = 1; i<= m; i++){
		int x, y; cin >> x >> y; 
		a[x].push_back(y);
		a[y].push_back(x);
		ke.push_back({x, y});
	}
	memset(visited, false, sizeof(visited));
}
void dfs1(int u, int s, int t){
	visited[u] = true;
	for (int v : a[u]){
        if ((u == s && v == t) || (u == t && v == s)) continue;
        if (!visited[v]){
             dfs1(v, s, t);
        }
    }
}
void dfs(int u){
	visited[u] = true;
	for (int v : a[u]){
		if (!visited[v]){
			dfs(v);
		}
	}
}
int tplt(){
	int res = 0;
	for(int i = 1; i<= n;i++){
		if (!visited[i]){
			res++;
			dfs(i);
		}
	}
	return res;
}
int main(){
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("in.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
	#endif
	in();
	int temp = tplt();
	int res = 0;
	for (auto x : ke){
		memset(visited, false, sizeof(visited));
		int a = x.first, b = x.second;
		int cnt = 0;
		for (int i = 1; i<= n;i++){
			if (!visited[i]){
				cnt++;
				dfs1(i, a, b);
			}
		}
		if (cnt > temp){
			res++;
		}
	}
	cout << res;
	
	return 0;
}