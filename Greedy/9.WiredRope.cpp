// Cho N sợi dây, biết chi phí nối 2 sợ dây là tổng độ dài của 2 sợi dây đó. Nhiệm vụ của bạn là nối N sợi dây này thành 1 sao cho chi phí nối dây là nhỏ nhất

// Input Format

// Dòng 1 chứa số nguyên N; Dòng 2 chứa N số nguyên là độ dài các sợ dây

// Constraints

// 1<=N<=10^5; Các sợi dây có độ dài không quá 10^5;

// Output Format

// In ra chi phí nối dây tối thiểu

// Sample Input 0

// 7
// 7 7 6 10 4 8 3 
// Sample Output 0
// 124
// Sample Input 1
// 4
// 4 3 2 6
// Sample Output 1

// 29
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    cout << accumulate(vt.begin(), vt.end(), 0ll);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

