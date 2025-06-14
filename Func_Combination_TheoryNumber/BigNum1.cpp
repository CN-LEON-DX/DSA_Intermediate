// Tính a^b%1000000007 với a,b nguyên không âm.

// Input Format

// 2 số nguyên không âm a và b

// Constraints

// 1≤a,b≤10^12

// Output Format

// Kết quả của bài toán

// Sample Input 0

// 2 10
// Sample Output 0

// 1024
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int INT = 1000000007;
ll recur(ll a, ll b){
    if (b==0) return 1;
    ll temp = recur(a, b/2);
    if (b%2==0) return (temp % INT) * (temp %INT)%INT;
    else  return ((temp % INT) * (temp %INT)%INT * (a%INT))%INT;
    
}
int main() {
    ll a, b; cin >> a >> b;
    cout << recur(a, b);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}