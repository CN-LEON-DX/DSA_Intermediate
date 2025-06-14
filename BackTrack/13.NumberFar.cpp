// Cho số nguyên dương N (2 < N <10). Một số nguyên dương K có N chữ số được gọi là số xa cách nếu thỏa mãn: K không chứa chữ số 0. Tất cả các chữ số từ 1 đến N đều xuất hiện trong K đúng 1 lần. Không có hai chữ số liên tiếp nào trong K có hiệu bằng 1.

// Input Format

// 1 dòng duy nhất chứa số nguyên dương N

// Constraints

// 3<=N<=9

// Output Format

// In ra các số thỏa mãn theo thứ tự tăng dần

// Sample Input 0

// 4
// Sample Output 0

// 2413
// 3142
#include <iostream>
#include <cmath>
using namespace std;

int n, a[10], mark[10];

void print() {
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << endl;
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (!mark[j] && (i == 1 || abs(a[i - 1] - j) != 1)) {
            a[i] = j;
            mark[j] = 1;
            if (i == n) {
                print();
            } else {
                Try(i + 1);
            }
            mark[j] = 0;
        }
    }
}

int main() {
    cin >> n;
    Try(1);
    return 0;
}