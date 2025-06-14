// Cho xâu kí tự S chỉ bao gồm các số từ 2 tới 9, mỗi chữ số này trên bàn phím của điện thoại cục gạch tương ứng với 3 chữ cái như trong hình bên dưới. Bạn hãy in ra các xâu kí tự có thể tạo thành bằng cách ấn mỗi chữ số trong xâu S đúng 1 lần. Bạn hãy in ra các xâu kết quả theo thứ tự từ điển tăng dần.
// // Input Format

// // Dòng duy nhất chứa xâu S
// // Constraints

// // 2<=len(S)<=9

// // Các kí tự trong S là khác nhau

// // Output Format

// // In ra các xâu thỏa mãn
// // Sample Input 0

// // 23
// // Sample Output 0

// // ad ae af bd be bf cd ce cf 
// // Sample Input 1

// // 2
// // Sample Output 1

// // a b c 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string S;
vector<string> res;
string phone[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void Try(int i, string crr) {
    if (i == S.size()) {
        res.push_back(crr);
    } else {
        for (char c : phone[S[i] - '2']) {
            Try(i + 1, crr + c);
        }
    }
}

int main() {
    cin >> S;
    Try(0, "");
    sort(res.begin(), res.end());
    for (string r : res) {
        cout << r << " ";
    }
    return 0;
}