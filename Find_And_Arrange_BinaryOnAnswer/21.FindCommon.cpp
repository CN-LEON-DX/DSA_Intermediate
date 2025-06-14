// Cho 2 mảng số nguyên, thực hiện tìm hợp và giao của 2 mảng. Các phần tử trong mỗi mảng khác nhau đôi một.

// Input Format

// Dòng đầu tiên là số lượng phần tử của 2 dãy n và m. Dòng thứ 2 là n phần tử trong dãy số 1. Dòng thứ 3 là m phần tử trong dãy thứ 2.

// Constraints

// 1<=n,m<=10^5; -10^6<=a[i]<=10^6;

// Output Format

// Dòng đầu tiên in ra giao của 2 mảng. Dòng thứ 2 in ra hợp của 2 mảng

// Sample Input 0

// 3 5
// 1 2 3 
// 1 2 9 5 3
// Sample Output 0

// 1 2 3
// 1 2 3 5 9

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


int main() {
    int n, m; cin >> n >> m;
    int a[n], b[m];
    map<int, int> mp;
    for (int &x : a) {
        cin >> x;
        mp[x]++;
    }
    map<int, int> mp1;
    for (int &y : b) {
        cin >> y;
        mp[y]++;
        mp1[y]++;
    }
    for (auto x : a){
        if (mp1[x]){
            cout << x << " ";
            mp1[x] = 0;
        }
    }
    cout << endl;
    for (auto [x, y] : mp){
        cout << x << " ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
