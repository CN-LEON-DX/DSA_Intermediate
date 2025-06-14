// Có n quả táo với khối lượng đã biết. Nhiệm vụ của bạn là chia táo thành hai nhóm sao cho sự khác biệt giữa trọng lượng của 2 nhóm là nhỏ nhất.

// Input Format

// Dòng 1 là số nguyên dương N : số lượng quả táo. Dòng thứ 2 là N số nguyên p1,p2,...,pn là trọng lượng tương ứng của các quả táo.

// Constraints

// 1<=N<=20; 1<=pi<=10^9;

// Output Format

// In ra độ chênh lệch nhỏ nhất giữa 2 nhóm táo.

// Sample Input 0

// 5
// 3 2 7 4 1
// Sample Output 0

// 1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, S[21], check = 0;
void init(){
    for (int i = 1;i<=n;i++){
        S[i] = 0;
    }
}
void sinh(){
    int i = n;
    while (i>=1 && S[i] == 1){
        S[i] = 0;
        --i;
    }
    if (i==0) check = 1;
    else {
        S[i] = 1;
    }
}
int main() {
    cin >> n; 
    init();
    int a[n+1];
    for (int i = 1;i<=n;i++) cin >> a[i];
    ll res = 1e18;
    while (!check){
        ll s1 = 0;
        ll s2 = 0;
        for (int i = 1;i<=n;i++){
            if (S[i]==0){
                s1+=a[i];
            }else{
                s2+=a[i];
            }
        }
        res = min(res, abs(s1-s2));
        sinh();
    }
    cout << res;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
// CÁC TEST CASE KHÁC NHƯ SAU:
// CÁCH 2: DÙNG BIT