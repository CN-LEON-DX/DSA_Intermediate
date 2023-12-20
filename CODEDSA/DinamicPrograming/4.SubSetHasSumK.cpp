// Cho mảng số nguyên A[] gồm N phần tử và số nguyên dương S, nhiệm vụ của bạn hãy xác định xem có thể tạo ra một tập con các phần tử trong mảng có tổng bằng S hay không? Chú ý mỗi phần tử trong mảng chỉ được sử dụng một lần.

// Input Format

// Dòng đầu tiên gồm 2 số N và S; Dòng thứ 2 gồm N số của mảng A;

// Constraints

// 1<=N<=200; 1<=S<=50000; 1<=A[i]<=500;

// Output Format

// In ra 1 nếu có tập con của A có tổng bằng S, ngược lại in ra 0

// Sample Input 0
// 8 92
// 69 16 82 170 31 24 45 112 
// Sample Output 0
// 1
#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>& A, int S) {
    int N = A.size();
    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    for (int i = 0; i <= N; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= S; j++) {
            if (A[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][S];
}

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << (subsetSum(A, S) ? 1 : 0) << endl;
    return 0;
}