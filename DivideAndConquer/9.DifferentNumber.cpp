// Cho hai mảng đã được sắp xếp A[] và B[] gồm N và N-1 phần tử. Các phần tử của mảng A[] chỉ khác mảng B[] một phần tử duy nhất. Hãy tìm vị trí của phần tử khác nhau giữa A[] và B[].

// Input Format

// Dòng đầu chứa số nguyên dương N; Dòng thứ 2 chứa các phần tử của mảng A[]; Dòng thứ 3 chứa các phần tử của mảng B[];

// Constraints

// 1<=N<=10^5; 1<=A[i], B[i]<=10^6;

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 8
// 1 2 3 4 5 6 7 8 
// 1 2 3 4 5 6 8 
// Sample Output 0

// 7
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n], b[n-1];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < n-1; j++) cin >> b[j];
    int i1 = 0, i2 = 0;
    while (i1 < n && i2 < n-1){
        if (a[i1] != b[i2]){
            cout << i1 + 1 << endl;
            return 0;
        }
        i1++;
        i2++;
    }
    cout << i1 + 1 << endl;
    return 0;
}
