
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


int x[100][100];
vector<pair<ii, char>>  step = { {{-1, 0}, 'U'}, {{0, -1}, 'L'},  {{0, 1}, 'R'}, {{1, 0}, 'D'}};
vector<string> vt;
string temp = "";
int hasPath = 0;

void Try(int i, int j){
	if (i==n && j == n){
		vt.push_back(temp);
		hasPath = 1;
		return;
	}

	for (auto t : step){
		int i1 = i + t.first.first;
		int j1 = j + t.first.second;

		if (i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= n && x[i1][j1] == 1){
			x[i1][j1] = 0;
			temp += t.second;
			Try(i1, j1);
			x[i1][j1] = 1;
			temp.pop_back();
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
        		cin >> x[i][j];
        	}
        }

    x[1][1] = 0;

    Try(1, 1);
    if (!hasPath){
    	cout << -1; 
    }
    sort(vt.begin(), vt.end());
    for (auto it: vt) cout << it << endl;
    return 0;
}

// 4
// 1 1 0 1
// 1 1 1 1
// 0 1 1 1

// Result sample:

// DDRDRR
// DDRRDR
// ......