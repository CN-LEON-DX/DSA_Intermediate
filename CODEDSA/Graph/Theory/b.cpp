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
int main(){
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("in.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> prefix(n), suffix(n);
    prefix[0] = a[0];
    for (ll i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + a[i];
    }

    suffix[n-1] = a[n-1];
    for (ll i = n-2; i >= 0; i--) {
        suffix[i] = suffix[i+1] + a[i];
    }

    ll min_time = LLONG_MAX;
    for (ll i = 0; i < n; i++) {
        ll time = i*a[i] - prefix[i] + suffix[i] - (n-i)*a[i];
        min_time = min(min_time, time);
    }
    cout << min_time << endl;
	return 0;
}
