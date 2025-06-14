
// Một số được coi là số đẹp nếu nó chỉ bao gồm 2 số là 8 và 0. Bạn được cấp một số nguyên dương X, nhiệm vụ của bạn là tìm bội dương nhỏ nhất của X thỏa mãn bội này là số đẹp.

// Input Format

// Dòng đầu tiên là số bộ test T. T dòng tiếp theo mỗi dòng là một số nguyên dương N.

// Constraints

// 1<=T<=300; 1<=N<=300;

// Output Format

// Mỗi test in kết quả trên 1 dòng

// Sample Input 0

// 6
// 240
// 19
// 55
// 47
// 287
// 247
// Sample Output 0

// 8880
// 88008
// 880
// 80088
// 8088808
// 8000000008
// CÁCH 1: DÙNG BFS
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

string solve(int n) {
    vector<int> parent(n, -1), digit(n, -1);
    queue<int> q;
    int start = 8 % n;
    parent[start] = start;
    digit[start] = 8;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == 0) {
            string res;
            while (cur != parent[cur]) {
                res += char(digit[cur] + '0');
                cur = parent[cur];
            }
            res += char(digit[cur] + '0');
            reverse(res.begin(), res.end());
            return res;
        }
        for (int next_digit : {0, 8}) {
            int next = (cur * 10 + next_digit) % n;
            if (parent[next] == -1) {
                parent[next] = cur;
                digit[next] = next_digit;
                q.push(next);
            }
        }
    }
    return "-1";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << solve(N) << endl;
    }
    return 0;
}
