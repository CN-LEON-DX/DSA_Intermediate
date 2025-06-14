
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
int n, k;
vector<ll> BIT(max_int, 0);
vector<int> a(max_int, 0);


// Test
// 1<=n<=500 k<= 10
// find the array has unique element with sum == n and the element is prime number

vector<int> prime;
vector<vector<int>> vt;
vector<int> tmp;
bool nt(int t){
	for (int i = 2; i<= sqrt(t);i++){
		if (t % i == 0){
			return false;
		}
	}
	return true;
}
void Try(int i, int sum){
	for (int j = i;j< prime.size();j++){
		tmp.push_back(prime[j]);
		sum += prime[j];
		if (sum == n && tmp.size() == k){
			vt.push_back(tmp);
		}else if (sum < n && tmp.size() < k){
			Try(j+1, sum);
		}
		sum -= prime[j];
		tmp.pop_back();
	}
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> n >> k;
    for (int i = 2;i<= n;i++){
    	if (nt(i)){
    		prime.push_back(i);
    	}
    }

    Try(0, 0);

    for (auto it : vt){
    	for (int i : it){
    		cout << i << " ";
    	}
    	cout << endl;
    }
    if (vt.size() == 0){
    	cout << "NOT FOUND";
    }

    return 0;
}