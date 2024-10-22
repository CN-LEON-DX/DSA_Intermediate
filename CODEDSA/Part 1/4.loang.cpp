// // count island 1
// // input consider is point in island if it has same area, the cell is the same area if it has same edge


// 4 7
// 0 1 1 0 1 1 0
// 1 1 1 0 1 1 1
// 0 0 0 0 0 1 1 
// 1 1 0 1 0 0 0

// // // Output
// // 4

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
const int knx[8] = {-2, -2, -1, 1, -1, 1, 2, 2};
const int kny[8] = {-1, 1, -2, -2, 2, 2, -1, 1};
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
const int MOD = 1e9+7;
const int max_int = 10;
typedef long long ll;
int n, m;
vector<ll> BIT(max_int, 0);
// vector<int> a(, 0);
int a[1001][1001] = {0};



void countIsland(int i, int j){
	a[i][j] = 0;
	for (int k = 0;k<4;k++){
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 0 && i1 <n && j1 >= 0 && j1 < m && a[i1][j1] == 1){
			countIsland(i1, j1);
		}
	}
}
void knight(int i, int j){
	a[i][j] = 0;
	for (int k = 0;k<8;k++){
		int i1 = i + knx[k], j1 = j + kny[k];
		if (i1 >= 0 && i1 <n && j1 >= 0 && j1 < m && a[i1][j1] == 1){
			knight(i1, j1);
		}
	}
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> n >> m;
	int q, w, e, r; cin >> q >> w >> e >> r;
	debug(q, w, e, r);

    int res = 0;
    for (int i = 0;i<n;i++){
    	for (int j = 0;j<m;j++) cin >> a[i][j];
    }

	// for (int i = 0;i<n;i++){
    // 	for (int j = 0;j<m;j++){
    // 		if (a[i][j] == 1){
    // 			res++;
    // 			countIsland(i, j);
    // 		}
    // 	}
    // }
	knight(q, w);
	if (a[e][r] == 0) cout << "YES";
	else cout << "NO";


    return 0;

}