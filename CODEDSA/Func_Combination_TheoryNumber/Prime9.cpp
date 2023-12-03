#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
int a[10000000];
void sang(){
    for (int i = 0;i<=10000000;i++) a[i] = 1;
    a[0] = 0;
    a[1] = 0;
    for (int i = 2;i<=sqrt(10000000);i++){
        if (a[i])
        for (int j = i * i;j<=10000000;j+=i){
            a[j] = 0;
        }
    }
}
void solve(){
    ll n; cin >> n;
    sang();
    for (ll i = 2;i<=sqrt(n);i++){
        if (a[i]){
            cout << i*i << " ";
        }
    }
}
int main() {
    solve();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

// Cho số tự nhiên N. Nhiệm vụ của bạn là hãy liệt kê tất cả các số có đúng ba ước số không vượt quá n. Ví dụ n=100, ta có các số 4, 9, 25, 49.

// Input Format

// Số nguyên dương N

// Constraints

// 1≤N≤10^12

// Output Format

// Đưa ra kết quả trên một dòng

// Sample Input 0

// 100
// Sample Output 0

// 4 9 25 49