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


map<char, int> dp;
void slove(){
    string s; cin >> s;
    set<char> se(s.begin(), s.end());
    int r = 0, l = 0, cnt = 0;
    int n = s.size();
    int minsize = s.size();
    while (r < n){
        dp[s[r]]++;
        if (dp[s[r]]==1){ 
            cnt++;  
        }
        while (dp[s[l]] > 1){
            dp[s[l]]--;         
            l++;
        }
        if (cnt == se.size())  minsize = min(minsize, r - l + 1);
        r++;
    }
    cout << minsize << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t = 1;
    while (t--){
        slove();
    }
}
// Cho xâu S chỉ gồm chữ cái in thường, nhiệm vụ của bạn là tìm chiều dài của xâu con liên tiếp nhỏ nhất có chứa đầy đủ các kí tự khác nhau của S. Ví dụ S = abcaaaabcad thì xâu con bcad có độ dài nhỏ nhất và chứa đầy đủ các kí tự khác nhau của S.

// Input Format

// Dòng duy nhất chứa xâu S

// Constraints

// 1<=len(S)<=10^6

// Output Format

// In ra độ dài xâu con nhỏ nhất tìm được

// Sample Input 0

// bcceedeeaedda
// Sample Output 0

// 9