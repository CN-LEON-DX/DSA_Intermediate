
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
	// #ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        unordered_map<int, vector<int>> a;

        for (int i = 0; i < k; i++) {
            int bi, ci;
            cin >> bi >> ci;
            a[bi].push_back(ci);
        }

        vector<int> all_costs;

        for (auto& it : a) {
            vector<int>& costs = it.second;
            sort(costs.rbegin(), costs.rend()); 
            for (int i = 0; i < min(n, (int)costs.size()); ++i) {
                all_costs.push_back(costs[i]);
            }
        }

        sort(all_costs.rbegin(), all_costs.rend()); 

        ll max_earnings = 0;
        for (int i = 0; i < min(n, (int)all_costs.size()); ++i) {
            max_earnings += all_costs[i];
        }

        cout << max_earnings << endl;
    }

    return 0;

    return 0;
}