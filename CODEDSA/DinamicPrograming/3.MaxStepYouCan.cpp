// Cho mảng A[] gồm N số nguyên. Nhiệm vụ của bạn là sắp xếp lại mảng số với số lượng bước là ít nhất. Tại mỗi bước, bạn chỉ được phép chèn phần tử bất kỳ của mảng vào vị trí bất kỳ trong mảng. Ví dụ A[] = {2, 3, 5, 1, 4, 7, 6 }sẽ cho ta số phép chèn ít nhất là 3 bằng cách lấy số 1 chèn trước số 2, lấy số 4 chèn trước số 5, lấy số 6 chèn trước số 7 ta nhận được mảng được sắp.

// Input Format

// Dòng đầu tiên là N; Dòng thứ 2 gồm N phần tử của mảng A;

// Constraints

// 1<=N<=1000; 1<=A[i]<=1000;

// Output Format

// Đưa ra kết quả trên 1 dòng.

// Sample Input 0

// 13
// 143 340 571 845 211 228 274 443 666 594 491 814 24 
// Sample Output 0

// 6
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<int>& A) {
    int N = A.size();
    vector<int> dp(N, 1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return N - *max_element(dp.begin(), dp.end());
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << find(A) << endl;
    return 0;
}