// Cho dãy số Tribonacci với F[0] = 0, F[1] = 0, F[2] = 1, F[n] = F[n - 1] + F[n - 2] + F[n - 3] với n >= 3. Hãy tính F[n] chia dư cho 10^9 + 7.

// Input Format

// Dòng 1 là số bộ test T

// T dòng tiếp theo mỗi dòng là 1 số nguyên không âm N

// Constraints

// 1<=T<=10000

// 0<=N<=10^6

// Output Format

// Đưa ra kết quả của mỗi test trên 1 dòng

// Sample Input 0

// 7
// 8
// 14
// 12
// 7
// 9
// 7
// 12
// Sample Output 0

// 24
// 927
// 274
// 13
// 44
// 13
// 274
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
    F[1] = 0;
    F[2] = 1;
    for (ll i = 3;i<=1000000;i++){
        F[i] = (F[i-1]+F[i-2] + F[i-3])%MOD;
    }
    while (n--){
        cin >> k;
        cout << F[k] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}