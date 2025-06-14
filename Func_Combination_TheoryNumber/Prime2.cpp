#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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
    int n; cin >> n;
    sang();
    for (int i = 0;i<=n;i++){
        if (a[i]) cout << i << " ";
    }
}

int main() {
    solve();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
// Cho số nguyên không âm N, liệt kê các số nguyên tố không vượt quá N.

// Input Format

// Số nguyên N

// Constraints

// 0≤n≤10^7

// Output Format

// In ra các số nguyên tố không vượt quá N trên 1 dòng, các số cách nhau một khoảng trắng.

// Sample Input 0

// 13
// Sample Output 0

// 2 3 5 7 11 13 