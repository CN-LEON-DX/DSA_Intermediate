// Nhiệm vụ của bạn là hãy liệt kê các xâu nhị phân thuận nghịch có độ dài chẵn theo thứ tự từ điển với chiều dài không quá n kí tự.

// Input Format

// Dòng duy nhất chứa số nguyên N.

// Constraints

// 2<=N<=30

// Output Format

// In ra các xâu nhị phân đối xứng có độ dài chẵn theo thứ tự từ điển.

// Sample Input 0

// 4
// Sample Output 0

// 00
// 0000
// 0110
// 1001
// 11
// 1111
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> vt;
void in(int n) {
    int sl = n / 2;
    for (int i = 0; i < (1<<sl); ++i) {
        string s = "";
        int num = i;
        for (int j = 0; j < sl; ++j) {
            if (num & (1<<j)) {
                s = "1" + s;
            } else {
                s = "0" + s;
            }
        }
        string s1(s.rbegin(), s.rend());
        vt.push_back(s+s1);
    }
}

int main() {
    int n;
    cin >> n;
    for (int len = 2; len <= n; len += 2) {
        in(len);
    }
    sort(vt.begin(), vt.end());
    for (string x : vt) cout << x<< endl;
    return 0;
}