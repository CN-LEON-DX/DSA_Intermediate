// Bạn hãy sinh ra các biểu thức dấu ngoặc hợp lệ từ các cặp dấu ngoặc "()", "[]", "{}" có độ dài N. Kết quả được in ra theo thứ tự từ điển tăng dần, nếu không tồn tại biểu thức hợp lệ thỏa mãn thì in ra NOT FOUND

// Input Format

// Dòng duy nhất chứa số nguyên N
// Constraints

// 2<=N<=15
// Output Format

// In ra đáp án của bài toán
// Sample Input 0

// 2
// Sample Output 0

// () [] {} 
// Sample Input 1

// 4
// Sample Output 1

// (()) ()() ()[] (){} ([]) ({}) [()] [[]] []() [][] []{} [{}] {()} {[]} {{}} {}() {}[] {}{} 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> res;
string a = "()[]{}";

bool check(string s) {
    vector<char> stack;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push_back(c);
        } else {
            if (stack.empty()) {
                return false;
            }
            char top = stack.back();
            stack.pop_back();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return stack.empty();
}

void Try(int i, string crr) {
    if (crr.size() == N) {
        if (check(crr)) {
            res.push_back(crr);
        }
    } else {
        for (int j = 0; j < a.size(); j++) {
            Try(i + 1, crr + a[j]);
        }
    }
}

int main() {
    cin >> N;
    if (N % 2 != 0) {
        cout << "NOT FOUND";
    } else {
        Try(0, "");
        sort(res.begin(), res.end());
        for (string r : res) {
            cout << r <<  " ";
        }
    }
    return 0;
}