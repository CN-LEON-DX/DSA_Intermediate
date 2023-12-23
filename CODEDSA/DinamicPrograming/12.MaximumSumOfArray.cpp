// Cho dãy số A[] gồm N số. Nhiệm vụ của bạn là tìm tổng lớn nhất của dãy con được sắp theo thứ tự tăng dần của dãy A[]. Ví dụ với dãy A[] = {1, 101, 2, 3, 100, 4, 5} ta có kết quả là 106 = 1 + 2 + 3 + 100. Với dãy A[] = {10, 7, 5} ta có kết quả là 10. Với dãy A[] = {1, 2, 3, 5} ta có kết quả là 11.

// Input Format

// Dòng đầu tiên đưa vào N là số phần tử của dãy A[]; Dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.

// Constraints

// 1≤N≤1000; 0≤A[i]≤1000.

// Output Format

// Đưa ra kết quả của bài toán trên 1 dòng

// Sample Input 0

// 8
// 2 12 3 15 3 16 11 4 
// Sample Output 0
// 45
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
typedef long long ll;
int n;

int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("in.txt", "r", stdin);
    // for writing output to output.txt
    freopen("out.txt", "w", stdout);
    #endif

    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i<=n;i++) cin >> a[i];
    vector<ll> dp(n+1);
    for (int i = 1;i<=n;i++) {
        dp[i] = a[i];
    }
    for (int i = 2;i<=n;i++){
        for (int j = i-1;j>=1;j--){
            if (a[i] > a[j]){
                dp[i] = max(dp[i], a[i] + dp[j]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}