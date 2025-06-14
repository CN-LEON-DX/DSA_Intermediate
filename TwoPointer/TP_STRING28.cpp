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

void slove(){
    string s; cin >> s;
    int n = s.size();
    int maxlength = 0;
    int cnt2 = 0;
    int cnt8 = 0;
    int l = 0;
    int x, y; cin >> x >> y;
    for (int i = 0;i<n;i++){
        if (s[i]=='2'){
            cnt2++;
        }else cnt8++;
        while (cnt2 > x || cnt8 > y){
            if (s[l]=='2'){
                cnt2--;
            }else{cnt8--;}
            l++;
        }
        maxlength = max(maxlength, i - l + 1);
    }
    cout << maxlength << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t = 1;
    while (t--){
        slove();
    }
}

// 28tech rất yêu thích con số 28 vì thế anh ta có bài toán sau và nhờ bạn tìm lời giải. Cho một xâu kí tự S chỉ bao gồm kí tự 2 và kí tự 8, bạn hãy tìm xâu con liên tiếp có độ dài lớn nhất mà trong đó chứa nhiều nhất X kí tự 2 và Y kí tự 8.

// Input Format

// Dòng 1 chứa xâu S

// Dòng 2 chứa 2 số X, Y

// Constraints

// 2 <=len(S) <= 10^6
// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 8228282888
// 3 3
// Sample Output 0

// 6