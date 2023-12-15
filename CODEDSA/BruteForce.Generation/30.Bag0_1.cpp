// Một tên trộm đột nhập vào 28techland và muốn lấy đi 1 số đồ vật có giá trị lớn nhất. Ở 28techland tồn tại n đồ vật, đồ vật thứ i sẽ có trọng lượng w[i] và có giá trị là v[i], tên trộm mang theo cái balo có thể chứa được trọng lượng tối đa là S, nhiệm vụ của bạn là hãy giúp tên trộm lựa chọn các đồ vật sao cho tổng trọng lượng của chúng không vượt quá S và có giá trị lớn nhất. Chú ý tên trộm chỉ có thể chọn hoặc không chọn 1 đồ vật.

// Input Format

// Dòng đầu tiên là N và S; Dòng thứ 2 là N số tương ứng với trọng lượng của các đồ vật; Dòng thứ 3 là N số tương ứng với giá trị của các đồ vật;

// Constraints

// 1<=N<=15; 1<=S<=800; 1<=w[i]<=200; 1<=v[i]<=200;

// Output Format

// In ra tổng giá trị của các đồ vật trong balo.

// Sample Input 0

// 12 356
// 174 153 127 156 156 5 132 161 170 26 181 50 
// 103 32 102 85 54 166 187 173 137 54 24 91 
// Sample Output 0

// 61
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> w(N), v(N);
    for (int i = 0; i < N; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(S+1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= S; ++j) {
            if (w[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j-w[i-1]]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[N][S] << endl;
    return 0;
}