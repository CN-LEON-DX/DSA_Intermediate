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
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    for(ll i = 2;i*i<=n;i++){
        if (n%i==0){
            cnt+=i;
            if (i*i != n){
                cnt+=n/i;
            }
        }
    }
    cnt+=n;
    cout << cnt;
    return 0;
}
// Tính tổng ước của 1 số nguyên dương N.

// Input Format

// 1 số nguyên dương N

// Constraints

// 1≤N≤10^12.

// Output Format

// Tổng ước số của N

// Sample Input 0

// 100
// Sample Output 0

// 217