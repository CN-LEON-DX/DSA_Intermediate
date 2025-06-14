// Đếm số lượng các số chính phương trong đoạn từ a tới b

// Input Format

// 2 số nguyên dương a, b

// Constraints

// 1≤a≤b≤10^18

// Output Format

// Số lượng số chính phương trong đoạn [a, b]

// Sample Input 0

// 1 1000000000
// Sample Output 0

// 31622
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    ll a, b; cin >> a >> b;
    ll l = sqrt(a);
    ll r = sqrt(b);
    int cnt = 0;
    for (int i = l;i<=r;i++){
        if (i*i>=a && i*i <=b) cnt++;
    }
    cout << cnt << endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}