// Cho mảng A[] gồm N phần tử, liệt kê các tập con (giữ đúng thứ tự trước sau) của mảng A[] có tổng các phần tử là số lẻ, mỗi phần tử chỉ được lấy 1 lần. Chú ý nếu 2 tập hợp chứa 2 phần tử có giá giống nhau nhưng ở vị trí khác nhau thì được tính 2 tập hợp khác nhau.

// Input Format

// Dòng 1 là N : số lượng phần tử trong mảng

// Dòng 2 gồm N số trong mảng A[]

// Constraints

// 2 <= N <= 15

// 1 <= A[i] <= 1000

// Output Format

// In ra các tập con thỏa mãn theo thứ tự từ điển tăng dần, nếu không tồn tại dãy con in ra NOT FOUND
// Sample Input 0

// 4
// 9 7 9 9 
// Sample Output 0

// 7 
// 7 9 9 
// 9 
// 9 
// 9 
// 9 7 9 
// 9 7 9 
// 9 9 9 
// Sample Input 1

// 6
// 3 5 4 5 4 2 
// Sample Output 1

// 3 
// 3 2 
// 3 4 
// 3 4 
// 3 4 2 
// 3 4 2 
// 3 4 4 
// 3 4 4 2 
// 3 5 4 5 
// 3 5 4 5 2 
// 3 5 4 5 4 
// 3 5 4 5 4 2 
// 3 5 5 
// 3 5 5 2 
// 3 5 5 4 
// 3 5 5 4 2 
// 4 5 
// 4 5 2 
// 4 5 4 
// 4 5 4 2 
// 5 
// 5 
// 5 2 
// 5 2 
// 5 4 
// 5 4 
// 5 4 
// 5 4 2 
// 5 4 2 
// 5 4 2 
// 5 4 4 
// 5 4 4 2 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int A[16];
vector<int> X;
vector<vector<int>> results;

void Try(int i, int sum) {
    if (sum % 2 != 0) {
        results.push_back(X);
    }
    for (int j = i; j < N; j++) {
        X.push_back(A[j]);
        Try(j + 1, sum + A[j]);
        X.pop_back();
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    Try(0, 0);
    if (results.empty()) {
        cout << "NOT FOUND";
    } else {
        sort(results.begin(), results.end());
        for (const auto& result : results) {
            for (int x : result) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}