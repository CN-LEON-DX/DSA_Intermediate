// // Cho số tự nhiên N. Nhiệm vụ của bạn là hãy kiểm tra N có phải là số Smith hay không. Một số được gọi là số Smith nếu N không phải là số nguyên tố và có tổng các chữ số của N bằng tổng các chữ số của các thừa số nguyên tố trong phân tích của N. 
// // Ví dụ N = 666 có các thừa số nguyên tố là 2, 3, 3, 37 có tổng các chữ số là 18.
// Input Format

// Số nguyên dương N

// Constraints

// 1≤N≤10^8.

// Output Format

// In ra YES nếu N là số Smith, ngược lại in ra NO.

// Sample Input 0

// 22
// Sample Output 0

// YES
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;

int sumN(ll n){
    int sum = 0;
    while (n){
        sum += n%10;
        n/=10;
    }
    return sum;
}
bool isPrime(ll n){
    if (n < 2) return 0;
    for (int i = 2;i<=sqrt(n);i++){
        if (n%i==0) return 0;
    }
    return 1;
}
bool smith(ll n){
    ll sum = 0;
    ll temp = n;
    multiset<ll> se;
    if (isPrime(n)) return 0;
    for (int i = 2;i*i<=n;i++){
        while (n%i==0){
            se.insert(i);
            n/=i;
        }
    }
    if (n>1) se.insert(n);
    for (int x : se){
        sum+=sumN(x);
    }
    return sum == sumN(temp);
}
void solve(){
    ll n; cin >> n;
    if (smith(n)) cout << "YES";
    else cout << "NO";
}
int main() {
    solve();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}