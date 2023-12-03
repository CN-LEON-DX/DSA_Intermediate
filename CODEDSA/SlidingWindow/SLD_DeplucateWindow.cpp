// Cho mảng A[] gồm N phần tử và số nguyên K, 
//bạn hãy xác định xem trong mảng có tồn tại 2 phần tử A[i], A[j] với i khác j sao cho A[i] = A[j] và abs(i - j) <= K hay không. Nếu con in ra YES, ngược lại in ra NO. Bài này các bạn có thể sử dụng sort hoặc sliding window

// Input Format

// Dòng 1 gồm N và K

// Dòng 2 gồm N số trong mảng A[]

// Constraints

// 1<=K<=N<=10^6

// 1<=A[i]<=10^6

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 5 5
// 9 10 7 8 4 
// Sample Output 0

// NO
// Sample Input 1

// 13 7
// 2 8 6 8 1 3 7 8 5 6 3 9 4 
// Sample Output 1

// YES

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
// Cach 1 dung map tim kiem 
void solve(){
    map<int, int> mp;
    int n, k; cin >> n >> k;
    int a[n]; 
    fore (i, 0, n) cin >> a[i];
    int ok = 0;
    for (int i = 0;i<n;i++){
        if (mp.count(a[i]) > 0){
            if (i - mp[a[i]] <= k){
                ok = 1;
                break;
            }
        }else {
            mp[a[i]] = i;
        }
    }
    if (ok) cout << yes;
    else cout << no;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t = 1;
    while (t--){
        solve();
    }
}