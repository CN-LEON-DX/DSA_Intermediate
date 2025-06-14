// Cho xâu kí tự S gồm N chữ cái khác nhau, hãy liệt kê tổ hợp lặp chập K của N kí tự trên và in ra theo thứ tự từ điển tăng dần.

// Input Format

// Dòng 1 chứa 2 số nguyên N và K

// Dòng 2 chứa xâu S

// Constraints

// 1<=K<=N<=15

// Output Format

// In ra đáp án của bài toán
// Sample Input 0

// 4 2
// ABCD
// Sample Output 0

// AA
// AB
// AC
// AD
// BB
// BC
// BD
// CC
// CD
// DD
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
string S;
vector<char> X;

void Try(int i) {
    if (X.size() == K) {
        for (char c : X) {
            cout << c;
        }
        cout << endl;
    } else {
        for (int j = i; j < N; j++) {
            X.push_back(S[j]);
            Try(j);
            X.pop_back();
        }
    }
}

int main() {
    cin >> N >> K;
    cin >> S;
    sort(S.begin(), S.end());
    Try(0);
    return 0;
}