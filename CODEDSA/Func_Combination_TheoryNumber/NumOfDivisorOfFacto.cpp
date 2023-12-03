#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INT = 1000000007;
const int MAX = 1000001;
// Toi uu 
// Legendre
int a[MAX+1];
vector<ll> vt;
void sang(){
    for (int i = 2;i<=MAX;i++){
        a[i] = 1;
    }
    a[0] = 0; a[1] = 0;
    for (int i = 2;i<=sqrt(MAX);i++){
        if (a[i]){
            for (int j = i*i;j<=MAX;j+=i){
                a[j] = 0;
            }
        }
    }
    for (int i = 0;i<=MAX;i++){
        if (a[i]){
            vt.push_back(i);
        }
    }
}
void solve(int n){
// For each prime number, p find the largest power of it that divides n!. 
// We use Legendre’s formula for this purpose. 
// The value of largest power that divides n! is ?n/p? + ?n/(p2)? + ?n/(p3)? + …… 
// Let these values be exp1, exp2, exp3,… Using the above formula, we get the below values for n = 6.
// The largest power of 2 that divides 6!, exp1 = 4.
// The largest power of 3 that divides 6!, exp2 = 2.
// The largest power of 5 that divides 6!, exp3 = 1.
// The result is (exp1 + 1) * (exp2 + 1) * (exp3 + 1) … for all prime numbers,
//  For n = 6, the values exp1, exp2, and exp3 are 4 2 and 1 respectively 
// (computed in above step 2). So our result is (4 + 1)*(2 + 1) * (1 + 1) = 30
    sang();
    ll result = 1;
    for (int i = 0;i<vt.size();i++){
        ll p = vt[i];
        ll exp = 0;
        while (p<=n){
            exp = exp + (n/p);
            p = p*vt[i];
        }
        result = ((result%INT)*((exp+1)%INT))%INT;
    }
    cout << result;
}
int main() {
    int n; cin >> n;
    solve(n);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
