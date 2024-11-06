// // find the max sum in array left to right in array a
// 6 2
// 5 2 5 3 5 1
// 2 5
// 2 4
// // => sum 2->5 max sum is: 5 + 5 + 5 + 3 => 18
// // => sum 2->4 max sum is: 5 + 5 + 5 => 15
// => final result is: 33


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
vector<ll> BIT(max_int, 0);
vector<int> a(max_int, 0);

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> n;
    int tc; cin >> tc;
    int a[n+1]; for (int i=1; i<=n;i++) cin >> a[i];
    int pre[n+1] = {0};
    while (tc--){
    	int l, r; cin >> l >> r; 
    	pre[l] += 1;
    	pre[r + 1] -= 1;
    }
    int f[n+1] = {0};
    f[1] = pre[1];
    for (int i = 2;i<=n;i++){
    	f[i] = f[i-1] + pre[i];
    }
    sort(a + 1, a + n + 1);
    sort(f + 1, f + n + 1);
    int res = 0;
    for (int i = 1;i<=n;i++){
    	res += a[i] * f[i];
    }
    stable_sort()
    cout << res;
    return 0;
} 