// Nhiệm vụ của bạn là tính N^K, kết quả được chia dư với 10^9 + 7

// Input Format

// Dòng duy nhất chứa 2 số N và K

// Constraints

// 1<=N<=10^6; 1<=K<=10^9;

// Output Format

// Kết quả của bài toán

// Sample Input 0

// 9 9
// Sample Output 0

// 387420489
// Sample Input 1

// 994402 999992619
// Sample Output 1

// 925329307
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
using ll = long long;
ll lt(ll x, ll y){
    if (y==1){
        return x;
    }
    ll res = lt(x, y/2);
    if (y%2==0){
        return (res * res)%MOD;
    }else return (res%MOD * res%MOD * x)%MOD;
}
int main() {
    int n, k; cin >> n >> k;
    cout << lt(n, k);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
