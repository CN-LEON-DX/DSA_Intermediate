// Nhiệm vụ của bạn ở bài tập này là sinh ra các xâu chỉ bao gồm 2 kí tự A và B theo thứ tự từ điển giảm dần.

// Input Format

// Dòng duy nhất chứa số nguyên dương N là độ dài của xâu.

// Constraints

// 1<=N<=10;

// Output Format

// In ra các xâu AB, mỗi xâu được in trên 1 dòng.

// Sample Input 0

// 3
// Sample Output 0

// BBB
// BBA
// BAB
// BAA
// ABB
// ABA
// AAB
// AAA


#include <bits/stdc++.h>
using namespace std;

int n;
char S[1001];
int check = 0;

void init() {
    for (int i = 1; i <= n; i++) {
        S[i] = 'A';
    }
}

void sinh() {
    int i = n;
    while (i >= 1 && S[i]=='B') {
        S[i] = 'A';
        --i;
    }
    if (i == 0) {
        check = 1;
    } else {
        S[i] = 'B';
    }
}

int main() {
    cin >> n;
    init();
    vector<string> vt;
    while (!check) {
        string s = "";
        for (int i = 1; i <= n; i++) {
            s += S[i];
        }
        vt.push_back(s);
        sinh();
    }
    for (int i = vt.size() - 1; i >= 0; i--) {
        cout << vt[i] << endl;
    }
    return 0;
}
