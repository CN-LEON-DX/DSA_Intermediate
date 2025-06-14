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
// Ta tìm các bậc của các đỉnh 
// Sau đó ta tìm dùng bfs tìm các đỉnh với điểu kiện nếu đỉnh bậc 0 thì đưa vào queue
// Nếu duyệt đỉnh có giá trị bậc là 0 đó thì kề với đỉnh nào thì trừ giá trị đỉnh kề đó đi
vector<int> a[1001];
int bac[1001];
void in(){
	memset(bac, 0, sizeof(bac));
	cin >> n >> m;
	for (int i = 1; i<= m;i++){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		bac[y]++;
	}
}
void bfs(){
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (bac[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int x : a[v]){
            bac[x]--;
            if (bac[x] == 0){
                q.push(x);
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
	bfs();
	return 0;
}