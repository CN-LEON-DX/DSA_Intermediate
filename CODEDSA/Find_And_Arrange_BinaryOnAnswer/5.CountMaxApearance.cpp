// Cho mảng số nguyên A[] có N phần tử, hãy tìm số xuất hiện nhiều nhất trong mảng.

// Input Format

// Dòng đầu tiên là số nguyên dương N. Dòng thứ 2 là N phần tử trong mảng, các phần tử viết cách nhau một dấu cách.

// Constraints

// 1<=N<=10^5; -10^9<=A[i]<=10^9

// Output Format

// In ra số có số lần xuất hiện nhiều nhất và tần suất tương ứng, nếu có nhiều số có cùng số lần xuất hiện thì in ra số nhỏ nhất.

// Sample Input 0

// 5
// 1 2 2 1 3
// Sample Output 0

// 1 2

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


int main() {
    int n; cin >> n;
    map<int, int> mp;
    while (n--){
        int k; cin >> k;
        mp[k]++;
    }
    int maxtime = -1;
    for (auto x : mp){
        maxtime = max(x.second, maxtime);
    }
    for (auto x : mp){
        if (x.second == maxtime){
            cout << x.first << " " << x.second;
            return 0;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}