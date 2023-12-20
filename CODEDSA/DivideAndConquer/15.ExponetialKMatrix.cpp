// Cho ma trận A[][] là ma trận vuông cỡ N x N. Hãy tính kết quả A^K và chia dư các phần tử trong ma trận kết quả cho 10^9 + 7

// Input Format

// Dòng đầu tiên chứa 2 số nguyên dương N và K; N dòng tiếp theo là các phần tử trong ma trận A

// Constraints

// 1<=N<=10; 1<=K<=10^9; 0<=A[i][j]<=1000

// Output Format

// In ra ma trận đáp án

// Sample Input 0

// 2 3
// 712 141 
// 55 619 
// Sample Output 0

// 376787593 188740908 
// 73622340 252298909


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
int n, k;
struct matran{
    ll A[11][11];
    friend matran operator * (matran x, matran y){
        matran z; 
        for (int i = 1;i<=n;i++){
            for (int j = 1;j<=n;j++){
                z.A[i][j] = 0;
                for (int k = 1; k<=n;k++){
                    z.A[i][j] += x.A[i][k] * y.A[k][j];
                    z.A[i][j] %= MOD;
                }
            }
        }
        return z;
    }
};

matran bpow(matran x, int k){
    if (k==1) return x;
    matran res = bpow(x, k/2);
    if (k %2==0) return res * res;
    else return res * res * x;
}
int main() {
    cin >> n >> k;
    matran x;
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            cin >> x.A[i][j];
        }
    }
    x = bpow(x, k);
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            cout <<  x.A[i][j] << " ";
        }
        cout << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
