// Hãy phân tích một số nguyên dương N thành thừa số nguyên tố

// Input Format

// Số nguyên dương N

// Constraints

// 2≤N≤10^16

// Output Format

// Phân tích thừa số nguyên tố của N, xem ví dụ để rõ hơn format.

// Sample Input 0

// 60
// Sample Output 0

// 2^2 * 3^1 * 5^1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
using ll = long long;
vector<ll> pr;

void sang(ll n){
    vector<bool> a(n+1, true);
    a[0] = a[1] = false;
    for (ll i=2; i * i<=n; i++){
        if (a[i]){
            for (ll j = i * i; j<=n; j += i){
                a[j] = false;
            }
        }
    }
    for (ll i = 2; i<=n; i++){
        if (a[i]){
            pr.push_back(i);
        }
    }
}

void solve(){
    ll n; cin >> n;
    map<ll, ll> mp;
    sang(sqrt(n));
    for (ll i = 0; i < pr.size() && pr[i] * pr[i] <= n; i++){
        while (n % pr[i] == 0){
            mp[pr[i]]++;
            n /= pr[i];
        }
    }
    if (n > 1) mp[n]++;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it != prev(mp.end())) {
            cout << it->first << "^" << it->second << " * ";
        } else {
            cout << it->first << "^" << it->second;
        }
    }
}

int main() {
    solve();
    return 0;
}