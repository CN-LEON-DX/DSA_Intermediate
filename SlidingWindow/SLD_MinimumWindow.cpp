// Cho 2 xâu kí tự S và T, nhiệm vụ của bạn là tìm xâu con ngắn nhất của S chứa đầy đủ mọi kí tự của xâu T.
// Ví dụ S = ADOBECODEBANCC, T = CABC thì xâu con BANCC là xâu con ngắn nhất của S chứa đầy đủ mọi kí tự của T

// Input Format
// Dòng 1 là xâu S
// Dòng 2 là xâu T
// Constraints
// 1<=len(T),len(S)<=10^6
// S, T chỉ chứa các kí tự in thường
// Output Format

// In ra xâu con nhỏ nhất thỏa mãn và xuất hiện đầu tiên nếu có nhiều xâu thỏa mãn. Nếu không tồn tại đáp án in ra -1

// Sample Input 0
// dbcddbaaccacb
// ab
// Sample Output 0
// ba

// Sample Input 1
// ccaadcdcdbdabddb
// dbb
// Sample Output 1
// bdab

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fore(i,b,a) for(int i = b; i<a; i++)
#define null NULL
#define nl '\n'
#define yes "YES\n"
#define no "NO\n"
using namespace std;

int d[256], dp[256];
void solve(){
    string s; cin >> s;
    string pt; cin >> pt;
    for (char x : pt){
      dp[x]++;
    }
    int n = s.size();
    int l = 0;
    int pos = l;
    int minlenght = 1e9;
    for (int i = 0;i<n;i++){
        d[s[i]]++;
        int ok = 1;
        for (char x = 'a'; x <= 'z'; x++){
            if (d[x] < dp[x]){
                ok = 0;
                break;
            }
        }
        while (d[s[l]] > dp[s[l]]){
            d[s[l]]--;
            l++;
        }
        if (ok){
            if (minlenght > i - l + 1){
                minlenght = i - l + 1;
                pos = l;
            }
        }
    }
    if (minlenght == 1e9){
        cout << -1;
    }else {
        cout << s.substr(pos, minlenght);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    ll t;  t = 1;
    while (t--){
        solve();
    }
}