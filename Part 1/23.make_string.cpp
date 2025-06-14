
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
int n, m;
vector<ll> BIT(max_int, 0);
vector<int> a(max_int, 0);
char x[10][10];
int vst[10][10];
int ok = 0;
string s; 
string tmp = "";
void Try(int i, int j){
	cout << tmp << endl;
	if (ok) return;
	if (tmp == s){
		ok = 1;
		return;
	}
	for (int t = 1;t<= 4; t++){
		int i1 = i + dx[t-1];
		int j1 = j + dy[t-1];

		if (!vst[i1][j1] && i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m){
			vst[i1][j1] = 1;
			tmp+=x[i1][j1];
			if (tmp == s) {
				ok = 1;
			}else if (s.find(tmp) != string::npos){
				Try(i1, j1);
			}
			vst[i1][j1] = 0;
			tmp.pop_back();
		}
	}
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> n >> m;
    for (int i = 1;i<=n;i++){
        	for(int j =1;j<=m;j++){
        		cin >> x[i][j];
        	}
        }
    cin >> s;
    for (int i = 1;i<=n;i++){
        	for(int j =1;j<=m;j++){
        		if (s[0] == x[i][j]){
        			tmp = "";
        			tmp += x[i][j];
        			vst[i][j] = 1;
        			Try(i, j);
        			if (ok){
        				cout << "YES";
        				return 0;
        			}
        		}
        	}
        }
    if (ok){
    	cout << "YES";
    }else {
    	cout << "NO";
    }

    return 0;
}


// 79 _ Leetcode Wordsearch
// class Solution {
// public:
//     int vst[7][7];
//     int ok = 0;
//     string s;
//     string tmp = "";
//     int n, m; 
//     int dx[4] = {-1, 0, 1, 0};
//     int dy[4] = {0, 1, 0, -1};
//     void Try(int i, int j, auto a){
//         if (ok) return;
//         if (tmp == s){
//             ok = 1;
//             return;
//         }
//         for (int t = 0; t< 4; t++){
//             int i1 = i + dx[t];
//             int j1 = j + dy[t];
//             if (i1 >= 0 && i1 < m && j1 >= 0 &&  j1 < n && !vst[i1][j1] ){
//                 vst[i1][j1] = 1;
//                 tmp += a[i1][j1];
//                 if (i1 == 2 && j1 == 0){
//                     cout << tmp << endl;
//                 }
//                 if (tmp == s){
//                     ok = 1;
//                     return;
//                 }
//                 else if (s.find(tmp) != string::npos){
//                     Try(i1, j1, a);
//                 }
//                 // backtrack
//                 vst[i1][j1] = 0;
//                 tmp.pop_back();
//             }
//         }
//     }
//     bool exist(vector<vector<char>>& a, string word) {
//         s = word;
//         m = a.size();
//         n = a[0].size();
//         for (int i = 0;i<m;i++){
//             for (int j = 0;j< n; j++){
//                 if (a[i][j] == s[0]){
//                     tmp = "";
//                     vst[i][j] = 1;
//                     tmp += a[i][j];
//                     Try(i, j, a);
//                     if (ok){
//                         return true;
//                     }
//                     vst[i][j] = 0;
//                 }
//             }
//         }
//         return ok;
//     }
// };