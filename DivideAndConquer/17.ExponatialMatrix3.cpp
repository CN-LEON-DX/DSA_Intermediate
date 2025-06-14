// Cho ma trận vuông A[][] kích thước N x N. Nhiệm vụ của bạn là hãy tính ma trận A^K với K là số nguyên cho trước. Sau đó, tính tổng các phần tử của cột cuối cùng. Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 10^9+7.

// Input Format

// Dòng đầu tiên chứa 2 số nguyên dương N và K; N dòng tiếp theo là các phần tử trong ma trận A

// Constraints

// 1<=N<=10; 1<=K<=10^9; 0<=A[i][j]<=1000

// Output Format

// In ra đáp án của bài toán theo yêu cầu

// Sample Input 0

// 2 2
// 216 71 
// 923 906 
// Sample Output 0

// 966031
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
                for (int k = 1;k<=n;k++){
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
    if (k%2==0) return res * res;
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
    x=bpow(x, k);
    ll res = 0;
    for (int i = 1;i<=n;i++){
        res += x.A[i][n];
        res %= MOD;
    }
    cout << res;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
