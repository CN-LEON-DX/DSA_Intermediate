// Cho 2 số nguyên dương N và K, bạn hãy liệt kê các các tổ hợp K phần tử các số nguyên tố mà có tổng bằng N. Mỗi tổ hợp chỉ tính 1 lần và được in ra theo thứ tự từ bé đến lớn, các tổ hợp cũng được liệt kê theo thứ tự từ điển tăng dần. Nếu không tồn tại tổ hợp K phần tử thỏa mãn có tổng bằng N in ra NOT FOUND

// Input Format

// Dòng duy nhất chứa N và K
// Constraints

// 1<=K<=9

// 1<=N<=500

// Output Format

// In ra các cấu hình thỏa mãn trên từng dòng

// Sample Input 0

// 91 3
// Sample Output 0

// 3 + 5 + 83
// 3 + 17 + 71
// 3 + 29 + 59
// 3 + 41 + 47
// 5 + 7 + 79
// 5 + 13 + 73
// 5 + 19 + 67
// 7 + 11 + 73
// 7 + 13 + 71
// 7 + 17 + 67
// 7 + 23 + 61
// 7 + 31 + 53
// 7 + 37 + 47
// 7 + 41 + 43
// 11 + 13 + 67
// 11 + 19 + 61
// 11 + 37 + 43
// 13 + 17 + 61
// 13 + 19 + 59
// 13 + 31 + 47
// 13 + 37 + 41
// 17 + 31 + 43
// 19 + 29 + 43
// 19 + 31 + 41
// 23 + 31 + 37
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> X;
bool found = false;
vector<int> a;

bool pr(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void in() {
    for (int i = 2; i <= N; i++) {
        if (pr(i)) {
            a.push_back(i);
        }
    }
}

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
        for (int j = i; j < a.size(); j++) {
            if (sum + a[j] <= N) {
                X.push_back(a[j]);
                Try(j + 1, sum + a[j]);
                X.pop_back();
            }
        }
    }
}

int main() {
    cin >> N >> K;
    in();
    Try(0, 0);
    if (!found) {
        cout << "NOT FOUND";
    }
    return 0;
}