// Cho dãy số nguyên A[] gồm N phần tử, nhiệm vụ của bạn là tính tổng của dãy con có tổng lớn nhất.

// Input Format

// Dòng đầu tiên chứa số nguyên dương N; Dòng thứ 2 chứa N số nguyên của dãy A[]

// Constraints

// 1<=N<=10^5; 1<=abs(A[i])<=10^6

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 5
// -3 6 1 -3 6 
// Sample Output 0

// 10
// Cach lam:
// D[i] la tong day con lien tiep lon nhat ket thuc tai vi tri i
// D[i] = max(D[i-1] + a[i], a[i])
// D[1] = a[1]
// D[2] = max(D[1] + a[2], a[2])
// D[3] = max(D[2] + a[3], a[3])
// ...
// D[n] = max(D[n-1] + a[n], a[n])
// Dap an cua bai toan la max(D[i]) voi 1<=i<=n
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    long long a[n+1];
    for (int i = 1;i<=n;i++) cin >> a[i];
    long long dp[n+1];
    dp[1] = a[1];
    for (int i = 2;i<=n;i++){
        dp[i] = max(dp[i-1]+a[i], a[i]);
    }
    cout << *max_element(dp+1, dp+n+1);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
