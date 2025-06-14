// Tèo có N thẻ bài, mỗi thẻ ghi một con số từ 1 tới N. Không có 2 thẻ nào ghi hai số trùng nhau. Tèo muốn xếp thứ tự các thẻ bài sao cho không có hai con số nào liền kề nhau ở cạnh nhau.

// Input Format

// Số nguyên dương N

// Constraints

// 4<=N<=10;

// Output Format

// In ra các cấu hình thỏa mãn theo thứ tự từ điển tăng dần

// Sample Input 0

// 4
// Sample Output 0

// 2413
// 3142
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(string s) {
    for (int i = 0; i < s.length() - 1; ++i) {
        if (abs(s[i] - s[i + 1]) == 1) {
            return false;
        }
    }
    return true;
}

void in(int n) {
    string temp;
    for (int i = 1; i <= n; ++i) {
        temp += to_string(i);
    }

    do {
        if (check(temp)) {
            cout << temp << endl;
        }
    } while (next_permutation(temp.begin(), temp.end()));
}

int main() {
    int n;
    std::cin >> n;

    in(n);

    return 0;
}
