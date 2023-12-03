// Đếm số lượng các số nguyên tố cùng nhau với n không vượt quá n.

// Input Format

// Số nguyên duy nhất n

// Constraints

// 1≤n≤10^12

// Output Format

// Số lượng các số nằm trong đoạn từ 1 tới n mà nguyên tố cùng nhau với n.

// Sample Input 0

// 55
// Sample Output 0

// 40
// Sample Input 1

// 59
// Sample Output 1

// 58

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n; cin >> n;
    ll cnt = n;
    set<ll> se;
    for (ll i = 2;i*i<=n;i++){
        if (n%i==0){
            se.insert(i);
            while (n%i==0){
                n/=i;
            }
        }
    }
    if(n>1) se.insert(n);
    for (ll x : se){
        cnt = cnt - cnt/x;
    }
    cout << cnt;
}
int main() {
    solve();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}