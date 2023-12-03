#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll N; cin >> N;
    int res = 0;
    for (ll i = 2; i * i <= N; ++i) {
        int cnt = 0;
        if (N % i == 0) {
            while (N % i == 0) {
                cnt++;
                N /= i;
            }
        }
        if (cnt == 2) {
            cout << 0 << '\n';
            return;
        }else if (cnt ==1){
            res++;
        }
    }
    if (N > 1) ++res;
    cout << (res == 3 ? 1 : 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    solve();
    return 0;
}
// Số nguyên dương N được gọi là số Sphenic nếu N được phân tích duy nhất dưới dạng tích của ba thừa số nguyên tố khác nhau. Ví dụ N=30 là số Sphenic vì 30 = 2×3×5; N = 60 không phải số Sphenic vì 60 = 2×2×3×5. Cho số tự nhiên N, nhiệm vụ của bạn là kiểm tra xem N có phải số Sphenic hay không?

// Input Format

// Một số nguyên dương N

// Constraints

// 1≤N≤10^18

// Output Format

// Đưa ra 1 hoặc 0 tương ứng với N là số Sphenic hoặc không.

// Sample Input 0

// 999923001838986077
// Sample Output 0

// 1
// Sample Input 1

// 30