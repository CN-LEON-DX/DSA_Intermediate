// Cho mảng A[] gồm N phần tử, hãy đếm số lượng cặp A[i], A[j] sao cho i < j và A[i] > A[j];

// Input Format

// Dòng đầu tiên chứa số nguyên dương N; Dòng thứ 2 gồm N phần tử của mảng A

// Constraints

// 1<=N<=10^6; 1<=A[i]<=10^6;

// Output Format

// In ra đáp án của bài toán

// Sample Input 0
// 9
// 16 14 10 13 19 14 17 18 16 
// Sample Output 0
// 12
// Cac buoc giai:
#include <bits/stdc++.h>
using namespace std;
long long cnt = 0;
void merge(int a[], int l, int m, int r){
    int l1 = m - l + 1, l2 = r - m;
    vector<int> v1(a+l, a+m+1);
    vector<int> v2(a+m+1, a+r+1);
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()){
        if (v1[i] <= v2[j]){
            a[l] = v1[i];
            ++l; ++i;
        }
        else {
            cnt += v1.size() - i;
            a[l] = v2[j];
            l++; j++;
        }
    }
    while (i < v1.size()){
        a[l] = v1[i];
        ++l; ++i;
    }
    while (j < v2.size()){
        a[l] = v2[j];
        l++; j++;
    }
}
void mergesort(int a[], int l, int r){
    if (l < r){
        int m = (l + r)/2;
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        merge(a, l, m, r);
    }
}
int main(){
    int n; cin >> n;
    int a[n];
    for (int &i : a) cin >> i;
    mergesort(a, 0, n-1);
    cout << cnt;
    return 0;
}