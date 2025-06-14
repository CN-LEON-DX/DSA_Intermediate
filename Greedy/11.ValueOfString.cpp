// Cho xâu ký tự S[] bao gồm các ký tự in hoa [A, B, …,Z]. Ta định nghĩa giá trị của xâu S[] là tổng bình phương số lần xuất hiện mỗi ký tự trong xâu. Ví dụ với xâu S[] = “AAABBCD” ta có F(S) = 3^2 + 2^2 + 1^2 + 1^2 = 15. Hãy tìm giá trị nhỏ nhất của xâu S[] sau khi loại bỏ K ký tự trong xâu.

// Input Format

// Dòng đầu tiên đưa vào số lượng test T. Mỗi test được tổ chức thành 2 dòng. Dòng thứ nhất ghi lại số K. Dòng thứ 2 ghi lại xâu ký tự S[] có độ dài không vượt quá 10^6.

// Constraints

// T≤100; 1<=K<=10^6; 1<=len(S)<=10^6; Xâu S chỉ bao gồm các kí tự in hoa hoặc in thường.

// Output Format

// Đưa ra giá trị nhỏ nhất của mỗi test theo từng dòng.

// Sample Input 0

// 2
// 0
// ABCC
// 1
// ABCC
// Sample Output 0

// 6
// 3
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void solve() {
    int k;
    string s;
    cin >> k >> s;

    unordered_map<char, int> count;
    for (char c : s) {
        count[c]++;
    }

    priority_queue<int> pq;
    for (auto& [c, freq] : count) {
        pq.push(freq);
    }

    while (k > 0 && !pq.empty()) {
        int top = pq.top();
        pq.pop();
        top--;
        k--;
        if (top > 0) {
            pq.push(top);
        }
    }

    long long res = 0;
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        res += (long long)top * top;
    }

    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
