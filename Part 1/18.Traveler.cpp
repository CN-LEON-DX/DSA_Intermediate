
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
int n;

int  a[100][100], x[100], sum = 0;
int ans = INT_MAX;
int vst[100];
int e_min = INT_MAX;
void Try(int i, int sum){
	for (int j = 1;j<=n;j++){
		if (vst[j] == 0){
			x[i] = j;
			sum += a[x[i-1]][x[i]];
			vst[j] = 1;
			if (i==n){
				ans = min(ans, sum + a[x[n]][1]);
			}else if (e_min * (n - i) < ans){
				Try(i + 1, sum);
			}
			sum -= a[x[i - 1]][x[i]];
			vst[j] = 0;
		}
	}
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> n;
    for (int i = 1;i<=n;i++){
        	for(int j =1;j<=n;j++){
        		cin >> a[i][j];
        		if (a[i][j]) e_min = min(a[i][j], e_min);
        	}
        }
    x[1] = 1;
    vst[1] = 1;
    Try(2, 0);
    cout << ans;;
    return 0;
}