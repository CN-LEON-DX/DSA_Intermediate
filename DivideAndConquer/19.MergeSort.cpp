// Cho mảng A[] có N phần tử, bạn hãy cài đặt thuật toán Merge Sort - Sắp xếp trộn để sắp dãy số tăng dần sau đó in ra màn hình.

// Input Format

// Dòng 1 là N : Số phần tử trong mảng

// Dòng 2 gồm N phần tử trong mảng A[]

// Constraints

// 1<=N<=10^6

// 0<=A[i]<=10^9

// Output Format

// In ra dãy số sau khi sắp xếp

// Sample Input 0

// 10
// 231 449 632 324 260 898 609 654 950 700 
// Sample Output 0

// 231 260 324 449 609 632 654 700 898 950 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int a[], int l, int m, int r){
    int l1 = m - l + 1, l2 = r - m;
    vector<int> v1(a+l, a+m+1);
    vector<int> v2(a+m+1, a+r+1);
    int i = 0, j = 0;
    while (i < v1.size() && j <v2.size()){
        if (v1[i] <= v2[j]){
            a[l] = v1[i];
            ++l; i++;
        }else{
            a[l] = v2[j];
            l++; j++;
        }
    }
    while (i < v1.size()){
        a[l] = v1[i];
        l++; i++;
    }
    while (j < v2.size()){
        a[l] = v2[j];
        l++;j++;
    }
}
void mergesort(int a[], int l, int r){
    if (l < r){
        int mid = (l + r)/2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}
int main() {
    int n; cin >> n;
    int a[n];
    for (int &i : a) cin >> i;
    mergesort(a, 0, n-1);
    for (int i : a) cout << i << " ";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
