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
    int n, s; cin >> n >> s;
    int a[n];
    fore (i, 0, n) cin >> a[i];
    int l = 0;
    ll cnt = 0;
    ll sum = 0;
    for (int r = 0;r<n;r++){
        sum+=a[r]; 
        while (sum>s){
            sum-=a[l];
            l++;
        }
   
        cnt+=  r - l + 1;
    }
    cout << cnt << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    ll t; t = 1;
    while (t--){
        slove();
    }
}


// Cho mảng A[] gồm N số nguyên và số nguyên S, nhiệm vụ của bạn là đếm xem có bao nhiêu mảng con các phần tử liên tiếp trong mảng mà tổng không vượt quá S.

// Input Format

// Dòng đầu tiên là N và S

// Dòng thứ 2 là N số trong mảng A[]

// Constraints

// 1<=N<=10^6

// 1<=A[i]<=10^6

// 1<=S<=10^9

// Output Format

// In ra số lượng mảng con thỏa mãn

// Sample Input 0

// 13 14
// 5 4 5 2 4 5 1 1 2 5 5 2 2 
// Sample Output 0

// 47