#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector <int> a(n + 5);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector <int> dp;
    for (int i = 1; i <= n; ++i) {
        int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        // tim vi tri dau tien >= a(i) trong vector dp
        if (pos == (int) dp.size()) {
            // a(i) > moi phan tu trong dp -> tao ra duoc day con tang moi
            dp.push_back(a[i]);
        }
        else {
            // tham lam de tao ra duoc day con dai hon
            dp[pos] = a[i];
        }
    }
    // vector dp ko chua cac phan tu thuoc dap an toi uu
    cout << (int) dp.size() << "\n";
    
}

