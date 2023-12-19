// Cho dãy số Fibonacci với F[0] = 0, F[1] = 1, F[n] = F[n - 1] + F[n - 2] với n >= 2. Hãy tính F[n] chia dư cho 10^9 + 7.

// Input Format

// Dòng 1 là số bộ test T

// T dòng tiếp theo mỗi dòng là 1 số nguyên không âm N

// Constraints

// 1<=T<=10000

// 0<=N<=10^6

// Output Format

// Đưa ra kết quả của mỗi test trên 1 dòng

// Sample Input 0

// 6
// 5
// 13
// 10
// 14
// 8
// 11
// Sample Output 0

// 5
// 233
// 55
// 377
// 21
// 89
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
using ll = long long;
int main() {
    int n; cin >> n;
    int k;
    ll F[1000001];
    F[0] = 0;
    F[1] = 1;
    F[2] = 1;
    for (ll i = 3;i<=1000000;i++){
        F[i] = (F[i-1]+F[i-2])%MOD;
    }
    while (n--){
        cin >> k;
        cout << F[k] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}