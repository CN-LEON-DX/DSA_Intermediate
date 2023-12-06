// Cho n, in ra chữ số cuối cùng của 1378^n.

// Input Format

// Số nguyên không âm n

// Constraints

// 0≤n≤10^18

// Output Format

// Chữ số cuối cung của 1378^n

// Sample Input 0

// 2
// Sample Output 0

// 4
// Explanation 0

// (1378^2)%10 = 1898884 % 10 = 4
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll recur(ll a, ll n){
    if (n==0) return 1;
    ll temp = recur(a, n/2);
    if (n%2==0) return (temp%10)*(temp)%10;
    else  return (temp%10)*(temp%10)*(a%10);
}
int main() {
    ll n; cin >> n;
    cout << recur(1378, n)%10;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
