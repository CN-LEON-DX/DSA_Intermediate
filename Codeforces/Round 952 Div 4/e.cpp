#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        ll in[3]; 
        ll k;
        for (ll i = 0; i < 3; i++) {
            cin >> in[i];
        }
        sort(in, in + 3); 
        cin >> k;

        ll ans = 0;

        for (ll a = 1; a <= in[0]; a++) {
            if (k % a == 0) {
                ll re = k / a; 

                for (ll b = 1; b <= in[1]; b++) {
                    if (re % b == 0) {
                        ll c = re / b;
                        if (c > 0 && c <= in[2]) {
                            ll res = (in[0] - a + 1) * (in[1] - b + 1) * (in[2] - c + 1);
                            ans = max(ans, res); 
                        }
                    }
                }
            }
        }

        cout << ans << endl; 
    }

    return 0;
}
