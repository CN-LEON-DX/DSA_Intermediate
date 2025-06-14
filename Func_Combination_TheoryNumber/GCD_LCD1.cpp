#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b, a%b);
}
int main() {
    ll n, m; cin >> n >> m;
    cout << gcd(n, m) << " ";
    cout << n / gcd(n, m) * m;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

// Tìm ước chung lớn nhất và bội chung nhỏ nhất của 2 số nguyên

// Input Format

// 2 số nguyên a, b

// Constraints

// 1≤a,b≤10^12

// Output Format

// Ước chung lớn nhất và bội chung nhỏ nhất, dữ liệu đảm bảo BCNN của 2 số không vượt quá số int 64bit

// Sample Input 0

// 20 50
// Sample Output 0

// 10 100