// Đếm số lượng ước của 1 số nguyên dương N

// Input Format

// Số nguyên dương N

// Constraints

// 1≤N≤10^14

// Output Format

// Số lượng ước của số nguyên dương N.

// Sample Input 0

// 100
// Sample Output 0

// 9
// Sample Input 1

// 28
// Sample Output 1

// 6
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
int main() {
    ll n; cin >> n;
    ll cnt = 1;
    for (ll i = 2;i*i<=n;i++){
        if (n%i==0){
            cnt++;
            if (i*i != n){
                cnt++;
            }
        }
    }
    if (n>1) cnt++;
    cout << cnt;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}