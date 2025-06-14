// Bạn được cung cấp một số nguyên n. Trên mỗi bước, bạn có thể trừ một trong các chữ số khỏi số. Cần thực hiện bao nhiêu bước để số đó bằng 0?

// Input Format

// Dòng duy nhất chứa số nguyên n

// Constraints

// 1<=n<=10^6;

// Output Format

// In ra số bước tối thiểu

// Sample Input 0

// 4
// Sample Output 0

// 1
// Sample Input 1

// 27
// Sample Output 1

// 5
// Explanation 1

// Các bước thực hiện : 27→20→18→10→9→0
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n > 0) {
        int d = 0;
        int temp = n;
        while (temp > 0) {
            d = max(d, temp % 10);
            temp /= 10;
        }
        n -= d;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}