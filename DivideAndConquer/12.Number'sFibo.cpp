// Tìm số Fibonacci thứ N sau khi chia dư kết quả cho 10^9 + 7

// Input Format

// Dòng duy nhất chứa số nguyên dương N;

// Constraints

// 1<=N<=10^10

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 58
// Sample Output 0

// 286725742
// Sample Input 1

// 36
// Sample Output 1

// 14930352
// Với số N Lớn n <= 10^10 thì không thể làm theo cách thông thường được, ta phải tìm cách khác.
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

void multiply(ll F[2][2], ll M[2][2]) {
    ll x =  ((F[0][0]*M[0][0])%MOD + (F[0][1]*M[1][0])%MOD)%MOD;
    ll y =  ((F[0][0]*M[0][1])%MOD + (F[0][1]*M[1][1])%MOD)%MOD;
    ll z =  ((F[1][0]*M[0][0])%MOD + (F[1][1]*M[1][0])%MOD)%MOD;
    ll w =  ((F[1][0]*M[0][1])%MOD + (F[1][1]*M[1][1])%MOD)%MOD;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
void power(ll F[2][2], ll n) {
    if(n == 0 || n == 1)
        return;
    ll M[2][2] = {{1,1},{1,0}};
 
    power(F, n/2);
    multiply(F, F);
 
    if (n%2 != 0)
        multiply(F, M);
}

ll fib(ll n) {
    ll F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1);
    return F[0][0];
}

int main() {
    ll n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

// Cach 2:
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int const MOD = 1000000007;
ll n;
struct matran{
    ll A[2][2];
    friend matran operator * (matran x, matran y){
        matran z;
        for (int i = 0;i<2;i++){
            for (int j = 0;j<2;j++){
                z.A[i][j] = 0;
                for (int k = 0;k<2;k++){
                    z.A[i][j] += x.A[i][k] * y.A[k][j];
                    z.A[i][j]%=MOD;
                }
            }
        }
        return z;
    }
};
matran pow1(matran x, ll n){
    if (n==1) return x;
    matran res = pow1(x, n/2);
    if (n%2==0) return res * res;
    else return res*res*x;
}
int main() {
    cin >> n;
    matran x; 
    x.A[0][0] = 1;
    x.A[0][1] = 1;
    x.A[1][0] = 1;
    x.A[1][1] = 0;
    x = pow1(x, n);
    cout << x.A[0][1];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
