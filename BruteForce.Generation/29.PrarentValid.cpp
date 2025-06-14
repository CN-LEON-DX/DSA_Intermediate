// Cho biểu thức chỉ bao gồm dấu '(' và ')', nhiệm vụ của bạn là hãy sinh ra các xâu biểu thức cân bằng, ví dụ về biểu thức cân bằng (), ()()(), ((())), (())((())), ví dụ về biểu thức không cân bằng (()))(, ()()))

// Input Format

// Dòng duy nhất chứa số nguyên dương N là độ dài của biểu thức

// Constraints

// 2<=N<=14, N là số chẵn

// Output Format

// In ra các biểu thức cân bằng theo thứ tự từ điển. Nếu không tồn tại biểu thức hợp lệ có độ dài N thì in ra NOT FOUND.

// Sample Input 0

// 4
// Sample Output 0

// (())
// ()()
#include <iostream>
#include <vector>
using namespace std;

void in(int open, int close, string str) {
    if (open == 0 && close == 0) {
        cout << str << endl;
    }
    if (open > 0) {
        in(open - 1, close, str + "(");
    }
    if (close > open) {
        in(open, close - 1, str + ")");
    }
}

int main() {
    int N;
    cin >> N;
    if (N % 2 != 0) {
        cout << "NOT FOUND" << endl;
    } else {
        in(N / 2, N / 2, "");
    }
    return 0;
}