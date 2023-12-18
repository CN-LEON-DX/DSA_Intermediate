// Cho dãy số A gồm N phần tử là các số nguyên. Hãy tính tích lớn nhất của 2 hoặc 3 phần tử trong dãy.

// Input Format

// Dòng đầu tiên là N; Dòng thứ 2 là N phần tử của mảng A

// Constraints

// 1<=N<=1000; 0<=abs(A[i])<=10^6

// Output Format

// In ra tích lớn nhất của 2 hoặc 3 phần tử trong mảng

// Sample Input 0

// 5
// -9 4 3 -3 1 
// Sample Output 0

// 108
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    ll max_product = max(A[N-1]*A[N-2]*A[N-3], A[0]*A[1]*A[N-1]);
    cout << max_product << endl;

    return 0;
}