// Kiểm tra một số nguyên không âm N có phải là số nguyên tố hay không?

// Input Format

// Dòng duy nhất chứa số nguyên dương N

// Constraints

// 0≤N≤10^9

// Output Format

// In ra YES nếu n là số nguyên tố, ngược lại in NO.

// Sample Input 0

// 999999999
// Sample Output 0

// NO
// Sample Input 1

// 17
// Sample Output 1

// YES
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool check(int n){
    if (n<2) return 0;
    for (int i = 2;i<=sqrt(n);i++){
        if (n%i==0) return 0;
    }
    return 1;
}
void solve(){
    int n; cin >> n;
    if (check(n)) cout <<"YES";
    else cout << "NO";
}
int main() {
    solve();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
