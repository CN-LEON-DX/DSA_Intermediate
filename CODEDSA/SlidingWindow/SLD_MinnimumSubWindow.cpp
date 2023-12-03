// Cho mảng A[] có N phần tử, bạn hãy tìm ra dãy con các phần tử liên tiếp có tổng tối thiểu bằng K. Nếu có nhiều dãy con thỏa mãn hãy in ra dãy con ngắn nhất xuất hiện đầu tiên, trong trường hợp không tồn tại dãy con thỏa mãn in ra -1.

// Input Format

// Dòng 1 là N và K

// Dòng 2 gồm N số trong mảng A[]

// Constraints

// 1<=N<=10^6

// 0<=A[i]<=10^6

// 0<=K<=10^9

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 11 7
// 2 4 0 4 2 3 3 2 0 0 3 
// Sample Output 0

// 4 0 4 
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

void solve(){
    int n, k; cin >> n >> k;
    int a[n];
    fore(i, 0, n) cin >> a[i];
    ll cnt = 0;
    int pos = 0;
    int l = 0;
    int minl = 1e9;
    for (int i = 0;i < n;i++){
        cnt += a[i];
        while (cnt - a[l] >= k){
            cnt-=a[l];
            l++;
        }
        if (minl > i - l + 1 && cnt >= k){
            pos = l;
            minl = i - l + 1;
        }
    }
    if (minl == 1e9){
        cout << -1;
    }else{
        for (int i = pos;i<pos+minl;i++){
            cout << a[i] << " ";
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t=1;
    while (t--){
        solve();
    }
}