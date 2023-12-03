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

// Sample Input 0
// dabacdadbbdd
// Sample Output 0
// 4
void solve(){
    string s; cin >> s;
    int n = s.size();
    map<char, int> mp;
    int r = 0;
    int l = 0;
    int max_cnt = 1;
    while (r < n){
        mp[s[r]]++;
        while (mp[s[r]]>1){
            mp[s[l]]--;
            l++;
        }
        max_cnt = max(max_cnt, r - l + 1);
        r++;
    }
    cout << max_cnt << endl;
}
int main() {
    ll t; t = 1;
    while (t--){
        solve();
    }
}
// Cho xâu kí tự S, Tèo là một người khá kì quặc, anh ta chỉ thích những thứ không trùng lặp. Vì thế anh ta yêu cầu bạn tìm ra độ dài xâu con dài nhất mà các kí tự trong xâu con đó không có bất cứ một kí tự nào được lặp lại.

// Input Format

// Dòng duy nhất chứa xâu S

// Constraints

// 1<=len(S)<=10^6

// S chỉ bao gồm chữ cái in thường

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// dabacdadbbdd
// Sample Output 0

// 4