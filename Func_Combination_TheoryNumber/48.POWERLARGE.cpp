// Ở bài toán này, bạn cần tìm kết quả của phép toán a^(b^c) % (1e9+7). Hãy cẩn thận vì b^c có thể rất lớn ! Chú ý 0^0=1

// Input Format

// Dòng đầu tiên là số lượng bộ test Mỗi bộ test gồm 3 số a, b, c

// Constraints

// 1≤n≤10^5; 0≤a,b,c≤10^9

// Output Format

// In ra kết quả mỗi test trên 1 dòng

// Sample Input 0

// 1
// 2 3 2
// Sample Output 0

// 512
// Explanation 0

// 2^(3^2) = 2^9 = 512 % (1e9 + 7) = 512
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y >> 1;
        x = (x*x) % p;
    }
    return res;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll exponent = power(b, c, MOD-1);
        ll result = power(a, exponent, MOD);
        cout << result << endl;
    }
    return 0;
}