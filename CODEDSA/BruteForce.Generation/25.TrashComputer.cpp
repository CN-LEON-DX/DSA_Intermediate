// Số lượng máy tính ở các phòng thực hành tăng lên nhanh chóng. Để gán mã cho các máy tính của trường đó người ta sử dụng mã gồm 2*N ký tự, trong đó: N ký tự đầu tiên là hoán vị của N chữ cái in hoa đầu tiên, tính từ A. N ký tự tiếp theo là các ký tự số bất kỳ từ 1 đến N (có thể trùng nhau). Người ta ước tính chỉ cần N = 5 là đủ để gán mã cho toàn bộ máy tính kể cả khi mở rộng quy mô các phòng thực hành. Hãy viết chương trình liệt kê các mã tạo được với giá trị N cho trước.

// Input Format

// Số nguyên dương N

// Constraints

// 1 < N < 6

// Output Format

// Ghi ra lần lượt các mã khác nhau tạo được theo thứ tự từ điển, mỗi mã ghi trên một dòng

// Sample Input 0

// 2
// Sample Output 0

// AB11
// AB12
// AB21
// AB22
// BA11
// BA12
// BA21
// BA22
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void in(int N, string s) {
    if (s.length() == 2*N) {
        cout << s << endl;
        return;
    }
    if (s.length() < N) {
        for (char i = 'A'; i < 'A' + N; ++i) {
            if (s.find(i) == string::npos) {
                in(N, s + i);
            }
        }
    } else {
        for (char i = '1'; i <= '1' + N - 1; ++i) {
            in(N, s + i);
        }
    }
}

int main() {
    int N;
    cin >> N;
    in(N, "");
    return 0;
}