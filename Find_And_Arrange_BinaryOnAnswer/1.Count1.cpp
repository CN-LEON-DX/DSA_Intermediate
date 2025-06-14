// Cho mảng số nguyên gồm N phần tử. Hãy đếm xem mảng có bao nhiêu phần tử riêng biệt

// Input Format

// Dòng đầu tiên là N Dòng thứ 2 là các phần tử trong mảng a1, a2, ... aN

// Constraints

// 1≤n≤2.10^5; 1≤ai≤10^9

// Output Format

// In ra số lượng phần tử riêng biệt trong mảng.

// Sample Input 0

// 10
// 2 2 2 1 3 2 5 1 4 2
// Sample Output 0

// 5
// Explanation 0

// 5 phần tử khác nhau trong mảng là 1, 2, 3, 4, 5
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    set<int> se;
    while (n--){
        int k; cin >> k;
        se.insert(k);
    }
    cout << se.size();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}