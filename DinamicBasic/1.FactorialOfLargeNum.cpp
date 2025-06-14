// Đề bài rất đơn giản, bạn hãy tính N! chia dư cho (10^9 + 7).

// Gợi ý : Xây dựng mảng F[], trong đó F[i] lưu i! chia dư cho 10^9 + 7, mỗi test nhập n thì chỉ cần in ra F[n].

// Input Format

// Dòng 1 là số bộ test T

// T dòng tiếp theo mỗi dòng là 1 số nguyên không âm N

// Constraints

// 1<=T<=10000

// 0<=N<=10^6

// Output Format

// Đưa ra kết quả của mỗi test trên 1 dòng

// Sample Input 0

// 5
// 11
// 6
// 8
// 10
// 13
// Sample Output 0

// 39916800
// 720
// 40320
// 3628800
// 227020758
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
    F[2] = 2;
    for (ll i = 3;i<=1000000;i++){
        F[i] = (F[i-1]%MOD*i%MOD)%MOD;
    }
    while (n--){
        cin >> k;
        cout << F[k] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
