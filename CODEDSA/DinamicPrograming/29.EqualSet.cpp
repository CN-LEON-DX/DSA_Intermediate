// Nhiệm vụ của bạn là đếm số cách các số 1,2,…, n có thể chia thành hai tập có tổng bằng nhau. Các phần tử trong tập không xét đến thứ tự Ví dụ, nếu n = 7, có bốn nghiệm: {1,3,4,6} và {2,5,7}. {1,2,5,6} và {3,4,7}. {1,2,4,7} và {3,5,6}. {1,6,7} và {2,3,4,5}.

// Input Format

// Dòng duy nhất chứa số nguyên dương n

// Constraints

// 1<=n<=500

// Output Format

// In ra kết quả sau khi chia dư với 10^9 + 7

// Sample Input 0

// 7
// Sample Output 0

// 4
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int t = n * (n + 1) / 2;
    if (t % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    t /= 2;
    vector<vector<int>> dp(n+1, vector<int>(t+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= i) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
            }
        }
    }
    int res = dp[n][t];
    res = (long long)res * (MOD + 1) / 2 % MOD;
    cout << res << endl;
    return 0;
}