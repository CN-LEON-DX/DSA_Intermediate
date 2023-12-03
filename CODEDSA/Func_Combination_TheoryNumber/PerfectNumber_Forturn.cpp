//     Một số được gọi là “lộc phát” nếu chỉ có các chữ số 0,6,8. Nhập vào một số nguyên hãy kiểm tra xem đó có phải số lộc phát hay không. Nếu đúng in ra 1, sai in ra 0.

// Input Format

// Số nguyên n

// Constraints

// 0≤n≤10^18

// Output Format

// In ra 1 nếu n là số lộc phát, ngược lại in 0

// Sample Input 0

// 60806
// Sample Output 0

// 1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    string s; cin >> s;
    map<char, int> mp;
    mp['0']++;
    mp['6']++;
    mp['8']++;
    for (int i = 0;i<s.size();i++){
        if (!mp[s[i]]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
