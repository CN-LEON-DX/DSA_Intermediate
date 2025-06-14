// In ra tam giác pascal với chiều cao là n. Nếu các giá trị của tam giác pascal quá lớn, in ra giá trị trong tam giác này lấy dư với 1e9+7

// Input Format

// Số nguyên dương n

// Constraints

// 1≤n≤10^2

// Output Format

// Tam giác pascal

// Sample Input 0

// 6
// Sample Output 0

// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1 
// 1 5 10 10 5 1 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
        ll n; cin >> n;
        ll a[n+1][n+1];
        const ll INT = 1e9+7;
        for (ll i = 0; i <= n; i++){
            for (ll j = 0; j <= i; j++){
                if (j == 0 || j == i) a[i][j] = 1;
                else a[i][j] = (a[i-1][j-1]  % INT + a[i-1][j]  % INT) % INT;
            }
        }
        for (ll i = 0; i < n; i++){
            for (ll j = 0; j <= i; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
        cout << endl;
    }