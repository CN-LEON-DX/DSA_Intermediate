// Cho chữ cái c in hoa và số nguyên K; Hãy tìm cách liệt kê tất cả các xâu có K ký tự khác nhau được tạo ra bởi các chữ cái tính từ ‘A’ đến ký tự c. Các ký tự được phép lặp lại nhưng không tính các xâu là hoán vị của xâu nào đó đã liệt kê trước đó.

// Input Format

// Chữ cái c và K

// Constraints

// 'A' < c <='H'; 0 < K < (c – ‘A’);

// Output Format

// Ghi ra lần lượt các xâu ký tự kết quả theo thứ tự từ điển trên từng dòng.

// Sample Input 0

// C 2
// Sample Output 0

// AA
// AB
// AC
// BA
// BB
// BC
// CA
// CB
// CC
#include <iostream>
#include <vector>
using namespace std;

void in(char c, int K, string s) {
    if (s.length() == K) {
        cout << s << endl;
        return;
    }
    for (char i = 'A'; i <= c; ++i) {
        in(c, K, s + i);
    }
}

int main() {
    char c;
    int K;
    cin >> c >> K;
    in(c, K, "");
    return 0;
}