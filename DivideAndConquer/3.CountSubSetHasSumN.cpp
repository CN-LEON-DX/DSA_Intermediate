// Cho số nguyên dương n, bạn được phép sử dụng không giới hạn các số tự nhiên từ 1 tới n. Hỏi có bao nhiêu cách chọn ra 1 dãy có tổng các phần tử bằng n.

// Input Format

// Dòng duy nhất chứa số nguyên dương n

// Constraints

// 1<=n<=10^12

// Output Format

// In ra đáp án của bài toán sau khi chia dư với 10^9 + 7

// Sample Input 0
// 6
// Sample Output 0
// 32
#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll power(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    cout << power(2, n - 1) << endl;
    return 0;
}