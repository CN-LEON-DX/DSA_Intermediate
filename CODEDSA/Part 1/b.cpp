
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

// test
ll solve(vector<ll> h) {
    ll n = h.size();
    stack<ll> st;
    ll minr = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[i] < st.top()) {
            st.pop();
        }
        if (st.empty() || h[i] > st.top()) {
            minr++;
            st.push(h[i]);
        }
    }

    return minr;
}

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // #endif
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int res = solve(h);
    cout << res << endl;

    return 0;
}
