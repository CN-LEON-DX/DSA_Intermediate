// Cho mảng A[] gồm N phần tử, nhiệm vụ của bạn là tính tổng lớn nhất của dãy con trong mảng với một điều kiện đó là trong dãy con này không được có 2 phần tử nằm liền kề nhau.

// Input Format

// Dòng đầu tiên là N : số lượng phần tử trong mảng; Dòng thứ 2 là A[i];

// Constraints

// 1<=N<=10^6; 1<=A[i]<=1000;

// Output Format

// In ra kết quả của bài toán

// Sample Input 0

// 7
// 314 514 148 451 896 589 296 
// Sample Output 0

// 1706
// Khởi tạo mảng dp với dp[0] = A[0] và dp[1] = max(A[0], A[1]).

// Duyệt qua mỗi phần tử i từ 2 đến N-1.

// Với mỗi phần tử i, cập nhật dp[i] = max(dp[i-1], dp[i-2] + A[i]).

// Sau khi duyệt xong, dp[N-1] sẽ là tổng lớn nhất có thể đạt được mà không chọn hai phần tử liền kề.
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
    vector<ll> dp(n+1);
    vector<ll> a(n+1);
    for (int i = 1;i<=n;i++){
        cin >> a[i];
    }
    dp[1] = a[1];
    dp[2] = max(a[1], a[2]);
    for (int i = 3; i<=n;i++){
        dp[i] = max(dp[i-1], dp[i-2] + a[i]);
    }
    cout << dp[n];
    return 0;
}