// Cho số tự nhiên N. Nhiệm vụ của bạn là in ra ước số nguyên tố nhỏ nhất của các số từ 1 đến N. Ước số nguyên tố nhỏ nhất của 1 là 1. Ước số nguyên tố nhỏ nhất của các số chẵn là 2. Ước số nguyên tố nhỏ nhất của các số nguyên tố là chính nó.

// Input Format

// Một số N được ghi trên một dòng.

// Constraints

// 1≤N≤100000

// Output Format

// Đưa ra kết quả theo từng dòng

// Sample Input 0

// 6
// Sample Output 0

// 1
// 2
// 3
// 2
// 5
// 2
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> spf(100001);

void sang() {
    for (int i = 1; i <= 100000; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= 100000; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= 100000; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

int main() {
    sang();
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cout << spf[i] << endl;
    }
    return 0;
}
