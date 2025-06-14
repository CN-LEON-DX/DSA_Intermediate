// input:
// 2 dimension matrix m x n
// Ex:
// 8 8
// 1 1 0 0 0 1 1 1
// 1 0 0 0 1 1 1 1
// 0 1 1 1 0 0 1 0
// 1 1 1 1 0 1 1 0
// 1 1 1 1 1 0 1 1
// 1 0 0 1 0 1 0 1
// 0 0 0 0 1 0 1 0
// 1 1 0 0 0 1 0 1
// 3
// 2 3 1 7
// 2 2 2 7
// 1 2 1 8

// Ouput:
// 8
// 3
// 10


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
const int moveX[8] = {+0, +0, +1, -1, -1, -1, +1, +1};
const int moveY[8] = {+1, -1, +0, +0, -1, +1, +1, -1};
const int MOD = 1e9+7;
const int max_int = 10;
typedef long long ll;
vector<ll> BIT(max_int, 0);
vector<int> a(max_int, 0);

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    int a[n+1][m+1];
    for (int i = 1; i<=n;i++){
    	for (int j = 1;j<=m;j++){
    		cin >> a[i][j];
    	}
    }
    int prefix[n+1][m+1];
    for (int i = 1;i<=n;i++){
    	for (int j = 1;j<=m;j++){
    		prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j];
    	}
    }
    int tc; cin >> tc;
    while (tc--){
    	int r1, r2, c1, c2;
    	cin >> r1 >> r2 >> c1 >> c2;
   		cout << prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1] << endl;
    }
    return 0;
}