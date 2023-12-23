// Cho mảng số nguyên A[] gồm N phần tử, hãy tìm dãy con (không nhất thiết các phần tử phải liên tiếp) tăng chặt dài nhất của mảng A.

// Input Format

// Dòng đầu tiên là N; Dòng thứ 2 gồm N phần tử của mảng A;

// Constraints

// 1<=N<=1000; 1<=A[i]<=1000;

// Output Format

// In ra độ dài của dãy con tăng dài nhất

// Sample Input 0

// 14
// 128 104 53 876 660 961 754 775 290 231 224 915 392 994 
// Sample Output 0

// 6
// Voi bai nay ta co the lam theo cach sau:
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    vector<int> F(n, 1);
    for (int i=1;i<n;i++){
        for (int j = 0;j<i;j++){
            if (a[i] > a[j]) F[i]=max(F[i], F[j]+1);
        }
    }
    cout << *max_element(F.begin(), F.end());
    return 0;
}