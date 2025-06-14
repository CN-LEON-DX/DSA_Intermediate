// Bạn được cung cấp một mảng chứa n số nguyên dương. 
// Nhiệm vụ của bạn là chia mảng thành k mảng con liên tiếp sao cho tổng lớn nhất trong một mảng con càng nhỏ càng tốt. 
// (Gợi ý sử dụng binary search on answer. Binary search trên tổng lớn nhất của 1 mảng con)
// Input Format
// Dòng đầu tiên chứa hai số nguyên n và k: kích thước của mảng và số mảng con trong phép chia. Dòng tiếp theo chứa n số nguyên x1, x2,…, xn: nội dung của mảng.
// Constraints
// 1≤n≤2⋅10^5; 1≤k≤n; 1≤xi≤10^9;
// Output Format
// In một số nguyên: tổng lớn nhất trong một mảng con trong phép chia tối ưu.
// Sample Input 0
// 5 3
// 2 4 7 3 5
// Sample Output 0
// 8
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll a[], ll n, ll k, ll mid){
    ll cnt = 0;
    ll temp = 0;
    for (ll i = 0;i<n;i++){
        temp += a[i];
        if (temp>mid){
            temp = a[i];
            ++cnt; 
        }
    }
    ++cnt;
    return cnt<=k;
}
int main() {
    ll n, k; cin >> n >> k;
    ll a[n];
    for (ll &x : a) {
        cin >> x;
    }
    ll left = *max_element(a, a+n);
    ll right = accumulate(a, a+n, 0ll);
    ll res = -1;
    while (left <= right){
        ll mid = (left + right)/2;
        if (check(a, n, k, mid)){
            res = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    cout << res;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}


