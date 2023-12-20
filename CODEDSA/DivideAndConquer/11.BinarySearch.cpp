// Cho dãy A[] gồm N phần tử đã được sắp xếp và số nguyên dương K. Hãy kiểm tra xem K có xuất hiện trong mảng hay không, nếu có in ra YES, ngược lại in ra NO

// Input Format

// Dòng 1 chứa 2 số N và K; Dòng 2 chứa N số nguyên của mảng A[]

// Constraints

// 1<=N<=10^5; 1<=A[i], K<=10^6;

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 7 2
// 1 8 9 10 10 12 17 
// Sample Output 0

// NO
// Sample Input 1

// 6 4
// 4 8 9 16 19 20 
// Sample Output 1

// YES
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n-1;
    while (l <= r){
        int mid = (l+r)/2;
        if (a[mid] == k){
            cout << "YES";
            return 0;
        }else if (a[mid] < k){
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << "NO";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
