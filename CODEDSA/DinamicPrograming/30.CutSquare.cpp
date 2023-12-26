// Cho một hình chữ nhật a × b, nhiệm vụ của bạn là cắt nó thành các hình vuông. Trên mỗi lần cắt, bạn có thể chọn một hình chữ nhật và cắt nó thành hai hình chữ nhật sao cho tất cả độ dài các cạnh vẫn là số nguyên. Số lần di cắt tối thiểu có thể là bao nhiêu?

// Input Format

// Dòng duy nhất chứa 2 số nguyên a và b.

// Constraints

// 1<=a,b<=500;

// Output Format

// In ra số lần cắt tối thiểu

// Sample Input 0

// 3 5
// Sample Output 0

// 3
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
int n, m;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    cin >> n >> m;
    int res = 0;
    while (n>0 && m > 0){
        int t = 0;
        int c = 0;
        if (m==2){
            n-=2;
            c = 1;
            res += 1;
        }else if (n==2){
            m-=2;
            c = 1;
            res+=1;
        }
        if (c) break;
        if (n > m){
             t += n/m;
            n -= t * m;
            res += t;
        }
        else{
            t += m/n;
            m -= n * t;
            res += t;
        }
        debug(res, n, m);
    }
    if (n + m>0)
    cout << ++res;
    return 0;
}