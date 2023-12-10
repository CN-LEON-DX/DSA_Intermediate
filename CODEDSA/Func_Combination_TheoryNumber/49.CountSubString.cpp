// Bạn đã từng nghe tới Multinomial coefficient bao giờ chưa? Lý thuyết đó có thể giúp bạn giải quyết được bài toán sau đây. Cho một chuỗi, nhiệm vụ của bạn là tính toán số lượng các chuỗi khác nhau có thể được tạo bằng cách sử dụng các ký tự của nó. Nếu bạn chưa học xâu kí tự, có thể tìm hiểu 1 chút về xâu kí tự sau đó quay trở lại và giải bài tập này nhé !

// Input Format

// Một chuỗi kí tự chỉ bao gồm các chữ cái từ a-z có độ dài n

// Constraints

// 1≤n≤10^6

// Output Format

// In ra kết quả lấy dư với (10^9 + 7)

// Sample Input 0

// aab
// Sample Output 0

// 3
// Explanation 0

// Các xâu kí tự có thể là : aab, aba, baa

// CÁCH GIẢI: Ở ĐÂY TA CÓ THỂ NGHĨ NGAY DÙNG HỆ SỐ MULTINOMIAL COEFFICIENT
// VỚI 3 CHỮ CÁI A, A, B THÌ CÓ 3!/(2!*1!) = 3 CÁCH SẮP XẾP
// VỚI 4 CHỮ CÁI A, A, B, B THÌ CÓ 4!/(2!*2!) = 6 CÁCH SẮP XẾP
// TỪ ĐÓ ta sẽ dùng map giải quyết bài này
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

ll fact[1000001], inv[1000001];

ll power(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = inv[0] = 1;
    for(ll i = 1; i <= 1000000; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
        inv[i] = power(fact[i], MOD-2);
    }
}

int main() {
    precompute();
    string s;
    cin >> s;
    ll freq[26] = {0};
    for(char c : s) freq[c-'a']++;
    ll res = fact[s.size()];
    for(ll i = 0; i < 26; i++) {
        if(freq[i]) res = (res * inv[freq[i]]) % MOD;
    }
    cout << res << endl;
    return 0;
}