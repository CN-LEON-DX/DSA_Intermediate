// Cho mảng số nguyên A[] gồm N phần tử và số nguyên dương S, nhiệm vụ của bạn hãy xác định xem có thể tạo ra một tập con các phần tử trong mảng có tổng bằng S hay không? Chú ý mỗi phần tử trong mảng chỉ được sử dụng một lần.
// Input Format
// Dòng đầu tiên gồm 2 số N và S; Dòng thứ 2 gồm N số của mảng A;
// Constraints
// 1<=N<=200; 1<=S<=50000; 1<=A[i]<=500;
// Output Format
// In ra 1 nếu có tập con của A có tổng bằng S, ngược lại in ra 0
// Sample Input 0
// 8 92
// 69 16 82 170 31 24 45 112 
// Sample Output 0
// 1
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
int n, s;

int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("in.txt", "r", stdin);
    // for writing output to output.txt
    freopen("out.txt", "w", stdout);
    #endif
    cin >> n >> s;
    int a[n+1];
    for (int i = 1;i<=n;i++) cin >> a[i];
    vector<int> dp(s+1, 0);
    dp[0] = 1;
    for (int i = 1;i<=n;i++){
        for (int j = s;j>= 1;--j){
            if (j >= a[i]){
                if (dp[j - a[i]]) dp[j] = 1;
            }
        }
    }
    cout << dp[s];
    return 0;
}