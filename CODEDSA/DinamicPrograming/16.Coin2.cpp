// Hãy xem xét một hệ thống tiền tệ của ngân hàng XYZ bao gồm n đồng xu. Mỗi đồng xu có một giá trị nguyên dương. Nhiệm vụ của bạn là tính số cách riêng biệt mà bạn có thể tạo ra số tiền x bằng cách sử dụng số xu có sẵn. Ví dụ: nếu số xu là {2,3,5} và tổng mong muốn là 9, có 8 cách: 2 + 2 + 5; 2 + 5 + 2; 5 + 2 + 2; 3 + 3 + 3; 2 + 2 + 2 + 3; 2 + 2 + 3 + 2; 2 + 3 + 2 + 2; 3 + 2 + 2 + 2;

// Input Format

// Dòng nhập đầu tiên có hai số nguyên n và x: số xu và số tiền mong muốn. Dòng thứ hai có n số nguyên phân biệt c1, c2,…, cn: giá trị của mỗi đồng xu.

// Constraints

// 1≤n≤100; 1≤x≤10^6; 1≤ci≤10^6;

// Output Format

// In ra kết quả lấy dư với 10^9 + 7

// Sample Input 0

// 3 9
// 2 3 5
// Sample Output 0

// 8
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
typedef long long ll;
int n, s;

int main(){
    cin >> n >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> dp(s + 1, 0ll);
    dp[0] = 1;
    for (int i = 1; i <= s; i++){
        for (int j = 0; j < n; j++){
            if (i - a[j] >= 0){
                dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
            }
        }
    }
    cout << dp[s];
    return 0;
}