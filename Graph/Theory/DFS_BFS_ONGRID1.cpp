// Yêu cầu cho một ma trận lưới toàn 0 và 1
// Hãy đếm số vùng số 1
// Vung hop le la vung co chung canh 
// Ví dụ test
// Input đầu vào là n, m; chiều dài ma trận 
// 5
// 1 0 1 1 0 
// 0 1 0 0 1
// 1 0 1 0 1
// 0 0 1 1 1
// 1 0 1 0 1
// Ouput: 6
// Hãy in ra số vùng bằng DFS và BFS
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
int a[1001][1001], vt[1001][1001];
int res = 0;
void in(){
	cin >> n >> m;
	for (int i = 0; i< n;i++){
		for (int j = 0;j< m;j++) cin >> a[i][j];
	}
	for (int i = 0; i< n;i++){
		for (int j = 0;j< m;j++) vt[i][j] = 0;
	}
}
void dfs(int x, int y){
	queue<ii> q;
	q.push({x, y});
	vt[x][y] = 1;
	while (!q.empty()){
		int xb = q.front().first;
		int yb = q.front().second;
		q.pop();
		for (int i = 0; i<4; i++){
			int x1 = xb + dx[i];
			int y1 = yb + dy[i];
			if (a[x1][y1] == 1 && x1>= 0 && y1 >= 0 && vt[x1][y1] == 0){
				dfs(x1, y1);
			}
		}
	}
}
void find(){
	for (int i = 0; i< n; i++ ){
		for (int j = 0; j< m;j++){
			if(a[i][j]==1 && vt[i][j] == 0){
				res++;
				dfs(i, j);
				vt[i][j] = 1;
			}
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
	for (int i = 0; i< n;i++){
		for (int j = 0;j< m;j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	find();
	cout << res;
	return 0;
}
