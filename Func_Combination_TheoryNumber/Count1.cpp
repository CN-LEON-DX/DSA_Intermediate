#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
#define INT  1000000007
int n;
ll x, y;
void solve(){
    cin >> n;
    ll sum = 1;
    while (n--){
        cin >> x >> y;
        sum = (sum * (y + 1)) % INT;
    }
    cout << sum << endl;
}
int main() {
    solve();
    return 0;
}