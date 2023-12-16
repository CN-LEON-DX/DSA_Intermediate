// Cho một số nguyên dương N có không quá 16 chữ số, bạn được phép tách các chữ số của N thành các số nhỏ hơn và phải đảm bảo các số tách được đều là số thuận nghịch, bạn cũng ko được phép đảo thứ tự các chữ số của N. Hãy in ra mọi cách tách như vậy.

// Input Format

// Dòng duy nhất chứa N
// Constraints

// 1<=N<=10^16
// Output Format

// In ra các cách tách N thành các số nhỏ thuận nghịch nhỏ hơn

// Sample Input 0

// 282882
// Sample Output 0

// 2 8 2 8 8 2 
// 2 8 2 88 2 
// 2 8 2882 
// 2 828 8 2 
// 282 8 8 2 
// 282 88 2 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string N;
vector<string> res;

bool check(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

void Try(int i, string crr) {
    if (i == N.size()) {
        res.push_back(crr);
    } else {
        for (int j = i; j < N.size(); j++) {
            string sub = N.substr(i, j - i + 1);
            if (check(sub)) {
                Try(j + 1, crr + (crr.empty() ? "" : " ") + sub);
            }
        }
    }
}

int main() {
    cin >> N;
    Try(0, "");
    for (string r : res) {
        cout << r << endl;
    }
    return 0;
}