// Cho 2 số nguyên dương N và K, bạn hãy liệt kê các các tổ hợp K phần tử các số có 1 chữ số mà có tổng bằng N. Mỗi tổ hợp chỉ tính 1 lần và được in ra theo thứ tự từ bé đến lớn, các tổ hợp cũng được liệt kê theo thứ tự từ điển tăng dần. Nếu không tồn tại tổ hợp K phần tử thỏa mãn có tổng bằng N in ra NOT FOUND

// Input Format

// Dòng duy nhất chứa N và K
// Constraints

// 2<=K<=9

// 1<=N<=60

// Output Format

// In ra các cấu hình thỏa mãn trên từng dòng

// Sample Input 0

// 25 9
// Sample Output 0

// NOT FOUND
// Sample Input 1

// 38 7
// Sample Output 1

// 1 + 2 + 5 + 6 + 7 + 8 + 9
// 1 + 3 + 4 + 6 + 7 + 8 + 9
// 2 + 3 + 4 + 5 + 7 + 8 + 9
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> X;
bool found = false;

void Try(int i, int sum) {
    if (X.size() == K) {
        if (sum == N) {
            found = true;
            for (int j = 0; j < K; j++) {
                if (j > 0) {
                    cout << " + ";
                }
                cout << X[j];
            }
            cout << endl;
        }
    } else {
        for (int j = i; j <= 9; j++) {
            if (sum + j <= N) {
                X.push_back(j);
                Try(j + 1, sum + j);
                X.pop_back();
            }
        }
    }
}

int main() {
    cin >> N >> K;
    Try(1, 0);
    if (!found) {
        cout << "NOT FOUND";
    }
    return 0;
}