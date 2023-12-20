// Cho số nguyên dương N. Mỗi bước, bạn sẽ biến đổi N thành [N/2], N mod 2, [N/2]. Sau khi thực hiện một cách triệt để, ta thu được một dãy số chỉ toàn số 0 và 1. Nhiệm vụ của bạn là hãy đếm các số bằng 1 trong đoạn [L, R] của dãy số cuối cùng.

// Input Format

// Dòng duy nhất chứa 3 số nguyên N, L, R;

// Constraints

// 1<=N,L<=R<=10^10; 0<=R-L<=100000;

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 7 2 5
// Sample Output 0

// 4
// Explanation 0

// Test : [7] => [3, 1, 3] => [1, 1, 1, 1, 3] => [1, 1, 1, 1, 1, 1, 1].
// code
#include <iostream>
using namespace std;
typedef long long ll;

ll len(ll n) {
    if (n == 0) return 0;
    else return 2 * len(n / 2) + 1;
}

ll DAC(ll n, ll l, ll r) {
    if (l > r || n == 0) return 0;
    ll m = len(n / 2) + 1;
    if (r < m) return DAC(n / 2, l, r);
    else if (l > m) return DAC(n / 2, l - m, r - m);
    else return DAC(n / 2, l, m - 1) + DAC(n / 2, 1, r - m) + n % 2;
}

int main() {
    ll N, L, R;
    cin >> N >> L >> R;
    cout << DAC(N, L, R) << endl;
    return 0;
}