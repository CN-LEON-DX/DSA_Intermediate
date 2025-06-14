// Cho số tự nhiên K và xâu ký tự các chữ số S. Nhiệm vụ của bạn là đưa ra số lớn nhất bằng cách thực hiện nhiều nhất K lần đổi chỗ các ký tự trong S. Ví dụ K =3 và S = “1234567” ta được “7654321”.

// Input Format

// Dòng 1 đưa vào số nguyên K; Dòng 2 đưa vào xâu kí tự S;

// Constraints

// 1<=K<=10; 1<=len(S)<=8;

// Output Format

// Đưa ra đáp án là số lớn nhất tìm được
#include <iostream>
#include <algorithm>
using namespace std;

int k;
string s, res;

void Try(int i, int count) {
    if (count == k) {
        res = max(res, s);
        return;
    }
    for (int j = i; j < s.size(); j++) {
        for (int l = j + 1; l < s.size(); l++) {
            if (s[l] > s[j]) {
                swap(s[j], s[l]);
                Try(i + 1, count + 1);
                swap(s[j], s[l]);
            }
        }
    }
}

int main() {
    cin >> k;
    cin >> s;
    res = s;
    Try(0, 0);
    cout << res << endl;
    return 0;
}