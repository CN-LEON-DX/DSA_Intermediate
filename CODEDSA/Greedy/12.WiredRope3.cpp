// Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[].
// Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí nối dây là nhỏ nhất.
// Biết chi phí nối sợi dây thứ i và sợi dây thứ j là tổng độ dài hai sợi dây A[i] và A[j] 
//Gợi ý : Sử dụng hàng đợi ưu tiên, priority_queue Tutorial : https://www.youtube.com/watch?v=DRcAJNhtwbY&t=559s&ab_channel=andrew2804

// Input Format

// Dòng thứ nhất đưa vào số lượng sợi dây N; Dòng tiếp theo đưa vào N số A[i] là độ dài của các sợi dây; Các số được viết cách nhau một vài khoảng trống.

// Constraints

// 1≤N≤10^6; 1≤A[i]≤10^9.

// Output Format

// In ra chi phí nhỏ nhất lấy dư với (10^9 + 7).

// Sample Input 0

// 5
// 4 2 7 6 9
// Sample Output 0

// 62
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INT 100000007
int main() {
    int n; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while (n--){
        ll k; cin >> k;
        pq.push(k);
    }
    ll res = 0;
    vector<ll> vt;
    while (pq.size()!=1){
        res += pq.top();
        pq.pop();
        res += pq.top();
        pq.pop();
        vt.push_back(res);
        pq.push(res);
        res = 0;
    }
    ll result = 0;
    for (ll x : vt){
        result = result % INT + x % INT;
    }
    cout << result%INT;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
