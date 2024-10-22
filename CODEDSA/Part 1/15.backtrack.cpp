
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

const int MAX = 1001;
int n, k;
int a[MAX];
int X[MAX] = {-1};
int sum = 0;

void in(int q) {
    for (int i = 1; i <= q; i++) {
        if (X[i] != -1) {
            cout << X[i] << " ";
        }
    }
    cout << endl;
}
int q = 0;
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        // Đảm bảo không chọn lại các phần tử trước
        if (i > 1 && a[j] <= X[i - 1]) continue;

        X[i] = a[j];
        sum += a[j];
        q++;
        
        if (sum == k) {
            in(q);
        } else if (sum < k) {
            Try(i + 1);
        }
        
        X[i] = -1;
        q--;
        sum -= a[j];
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    Try(1);
    return 0;
}
// Test 1
// 5 50
// 5 10 15 20 25

// Test 2
// 8 53
// 15 22 14 26 32 9 16 8

// 15 16 22 
// 8 14 15 16 
// 8 9 14 22 

