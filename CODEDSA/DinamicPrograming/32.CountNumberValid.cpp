// Cho 2 số nguyên không âm a và b, nhiệm vụ của bạn là đếm xem trong đoạn từ a tới b có bao nhiêu số thỏa mãn điều kiện : Không có 2 chữ số liền kề nào của nó giống nhau.

// Input Format

// Dòng duy nhất chứa 2 số nguyên a và b.

// Constraints

// 0≤a≤b≤10^18;

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 123 321
// Sample Output 0

// 171
#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

string s;
int n;
ll dp[19][11][2][2];
// leading_zeroes Z : cac so 0 dung dang truoc -> xu ly rieng
ll solve(int i, int lst, bool Z, bool smaller) {
    if (i == n) return 1;
    if (dp[i][lst][Z][smaller] != -1) return dp[i][lst][Z][smaller];

    ll res = 0;
    int ub = (smaller? 9 : (s[i] - '0'));

    for (int d = 0; d <= ub; ++d) {
        if (d == lst && Z == 0) continue;
        bool n_Z = Z && (d == 0);

        bool n_smaller = (smaller || (d < (s[i] - '0')));
        res += solve(i + 1, d, n_Z, n_smaller);
    }

    return dp[i][lst][Z][smaller] = res;
}

ll F(ll x) {
    if (x < 0) return 0;
    s = to_string(x);
    n = s.size();

    memset(dp, -1, sizeof dp);
    return solve(0, 10, 1, 0);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    ll a, b;
    cin >> a >> b;
    cout << F(b) - F(a - 1) << "\n";
}

