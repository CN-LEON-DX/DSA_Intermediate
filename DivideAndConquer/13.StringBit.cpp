// Xâu nhị phân S được định nghĩa như sau :

// S[1] = “0”.

// S[2] = “1”.

// S[i] = S[i-2] + S[i-1] với i>2.

// Với phép cộng (+) là phép nối hai xâu với nhau. Hãy xác định ký tự thứ K trong xâu S[N] là ký tự ‘0’ hay ký tự ‘1’.

// Input Format

// 1 Dòng duy nhất chứa 2 số nguyên N và K

// Constraints

// 2<=N<=92; 1<=K<=7e18 và đảm bảo là một vị trí hợp lệ trong xâu S

// Output Format

// In ra kí tự là đáp án của bài toán

// Sample Input 0

// 7 7
// Sample Output 0

// 0
// Sample Input 1

// 8 6
// Sample Output 1

// 1
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> F(93);

ll find(ll n, ll k) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (k <= F[n-2]) return find(n-2, k);
    else return find(n-1, k - F[n-2]);
}

int main() {
    ll n, k;
    cin >> n >> k;
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i <= 92; i++) {
        F[i] = F[i-1] + F[i-2];
    }
    cout << find(n, k);
    return 0;
}
