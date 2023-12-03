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
    int n, k; cin >> n >> k;
    int a[n];
    fore (i, 0, n) cin >> a[i];
    sort(a, a+n);
    for (int i = 0;i<n-2;i++){
        int l = i + 1, r = n - 1;
        while (l < r){
            if (a[l]+a[r] == k - a[i]){
                cout << yes;
                return;
            }
            else if (a[l]+a[r] < k - a[i]){
                l++;
            }
            else{
                r--;
            }
        }
    }
    cout << no;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t=1;
    while (t--){
        slove();
    }
}


// Cho mảng A[] gồm N phần tử và số nguyên K, hãy kiểm tra xem trong mảng có 3 phần tử A[i], A[j], A[k] với i, j, k khác nhau và A[i] + A[j] + A[k] = K hay không ?

// Input Format

// Dòng đầu tiên là N và K

// Dòng thứ 2 là N số trong mảng A[]

// Constraints

// 1<=N<=10^5

// 1<=A[i],K<=10^9

// Output Format

// In ra YES nếu tồn tại, ngược lại in ra NO

// Sample Input 0

// 7 5
// 7 2 5 10 10 8 8 
// Sample Output 0

// NO
// Sample Input 1

// 7 13
// 1 7 6 3 3 1 8 
// Sample Output 1

// YES