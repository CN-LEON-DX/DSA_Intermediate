// Cho số nguyên dương N, hãy tính tích các số nguyên tố trong đoạn từ 0 đến N. Khi N = 0 hoặc 1 thì đáp án là 0.

// Input Format

// Dòng 1 là số bộ test T

// T dòng tiếp theo mỗi dòng là 1 số nguyên không âm N

// Constraints

// 1<=T<=10000

// 0<=N<=10^6

// Output Format

// Đưa ra kết quả của mỗi test trên 1 dòng, vì kết quả quá lớn nên hãy chia dư cho 10^9 + 7.

// Sample Input 0

// 5
// 20
// 16
// 10
// 22
// 29
// Sample Output 0

// 9699690
// 30030
// 210
// 9699690
// 469693188
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int INT = 1000001;
const int MOD = 1000000007;
int n, k;
int F[INT+1], D[INT+1];
void sang(){
    for (int i = 0;i<=INT;i++) F[i] = 1;
    F[0] = 0;
    F[1] = 0;
    for (int i = 2;i<=sqrt(INT);i++){
        if (F[i]){
            for (int j = i*i;j<=INT;j+=i) F[j]=0;
        }
    }
    D[0] = 0;
    D[1] = 0;
    D[2] = 2;
    D[3] = 6;
    ll temp = 6;
    for (int i = 4;i<=INT;i++){
        if (F[i]){
            temp = (i*temp)%MOD;
            D[i] = temp;
        }else{ D[i] = temp;}
    }
}

int main() {
    cin >> n;
    sang();
    while (n--){
        cin >> k;
        cout << D[k] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}