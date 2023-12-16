// Cho xâu kí tự S chỉ bao gồm chữ cái và chữ số, bạn có thể thay đổi các chữ cái trong xâu thành kiểu in hoa hoặc in thường tương ứng của nó nhưng không được thay đổi vị trí ban đầu. Bạn hãy liệt kê mọi xâu khác nhau có thể tạo thành bằng cách trên và liệt kê theo thứ tự từ điển tăng dần.

// Input Format

// Dòng duy nhất chứa xâu S
// Constraints

// 1<=len(S)<=12
// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 28TeCH
// Sample Output 0

// 28TECH
// 28TECh
// 28TEcH
// 28TEch
// 28TeCH
// 28TeCh
// 28TecH
// 28Tech
// 28tECH
// 28tECh
// 28tEcH
// 28tEch
// 28teCH
// 28teCh
// 28tecH
// 28tech
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string S;
vector<string> res;

void Try(int i, string crr) {
    if (i == S.size()) {
        res.push_back(crr);
    } else {
        if (isalpha(S[i])) {
            Try(i + 1, crr + (char)toupper(S[i]));
            Try(i + 1, crr + (char)tolower(S[i]));
        } else {
            Try(i + 1, crr + S[i]);
        }
    }
}

int main() {
    cin >> S;
    Try(0, "");
    sort(res.begin(), res.end());
    for (string r : res) {
        cout << r << endl;
    }
    return 0;
}