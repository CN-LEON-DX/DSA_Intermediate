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

    vector <int> dp(n + 5, 0);
    vector <int> tr(n + 5, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = a[i];
        tr[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (a[j] < a[i]) {
                if (dp[j] + a[i] > dp[i]) {
                    tr[i] = j;
                    dp[i] = dp[j] + a[i];
                }
            }
        }
    }

    debug(tr);

    int ans = 0;
    int x = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] > ans) {
            ans = dp[i];
            x = i;
        }
    }

    vector <int> id;
    
    while (tr[x] != x) {
        id.push_back(x);
        x = tr[x];
    }
    
}

