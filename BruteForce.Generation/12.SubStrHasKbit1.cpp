// Cho số nguyên dương N và K, nhiệm vụ của bạn là liệt kê các xâu nhị phân có độ dài N và có K bit 1 theo thứ tự từ điển tăng dần. Sau đó tiếp tục liệt kê các xâu nhị phân mà chỉ có duy nhất K bit 1 liên tiếp.

// Input Format

// 1 dòng chứa 2 số nguyên dương N và K.

// Constraints

// 1<=K<=N<=15;

// Output Format

// Dòng đầu tiên in ra các xâu nhị phân có K bit 1. Dòng thứ 2 in ra các xâu nhị phân có duy nhất K bit 1 liên tiếp.

// Sample Input 0

// 3 2
// Sample Output 0

// 011 101 110 
// 011 110 


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
bool check(string s) {
    int cnt = 0;
    int max_count = 0;
    int time = 0;

    for (char c : s) {
        if (c == '1') {
            cnt++;
            if (cnt > max_count) {
                max_count = cnt;
            }
            if (cnt == k) time++;
        } else {
            cnt = 0;
        }
    }

    return max_count == k && time==1;
}
int main() {
    cin >> n >> k;
    vector<string> vt, vt1;
    for (int i = 0;i<(1<<n);i++){
        string temp = "";
        int cnt = 0;
        for (int j = 0;j<n;j++){
            if ((i & (1<<j))!=0){
                temp+="1";
                cnt++;
            }else{
                temp+="0";
            }
        }
        vt1.push_back(temp);
        if (cnt==k) vt.push_back(temp);
    }
    sort(vt.begin(), vt.end());
    for (string x : vt){
        cout << x << " ";
    }
    cout << endl;
    sort(vt1.begin(), vt1.end());
    for (string x : vt1){
        if (check(x)) cout << x<< " ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

