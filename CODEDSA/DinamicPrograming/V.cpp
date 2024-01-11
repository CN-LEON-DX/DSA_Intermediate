#include <bits/stdc++.h>
using namespace std;
// Time
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
int main(){
	cin.tie(0) -> sync_with_stdio(0);
	#ifndef CNLEON
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int n; cin >> n;
	vector<int> asc(n+1, 0);	
	vector<int> des(n+1, 0);
	int a[n+1];
	for (int i =1;i<=n;i++) cin >> a[i];
	for (int i =1 ;i<=n;i++){
		asc[i] = a[i];
		for (int j = 1;j<i;j++){
			if (a[i] > a[j]){
				asc[i] = max(asc[i], asc[j]  + a[i]);
			}
		}
	}
	for (int i = n;i>=1;i--){
		des[i] = a[i];
		for (int j = n; j>= i;j--){
			if (a[i] > a[j]){
				des[i] = max(des[i], des[j] + a[i]);
			}
		}
	}
	int res = 0;
	for (int i = 1; i<= n;i++){
		res = max(res, asc[i] + des[i] - a[i]);
	}
	cout << res;
	return 0;
}