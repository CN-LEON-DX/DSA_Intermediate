// Cho mảng A[] có N phần tử, bạn hãy cài đặt thuật toán Quick sort - Sắp xếp nhanh để sắp dãy số tăng dần sau đó in ra màn hình. Sử dụng phân hoạch Lomuto

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
// 139 871 801 611 301 713 413 970 786 659 
// Sample Output 0

// 139 301 413 611 659 713 786 801 871 970 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1000007];
int lomuto(int a[], int l, int r){
    int pivot = a[r];
    int j = l - 1;
    for (int i = l;i<r;i++){
        if (a[i] <= pivot){
            j++;
            swap(a[j], a[i]);
        }
    }
    swap(a[r], a[j+1]);
    return j + 1;
}
void qs(int a[], int l, int r){
    if (l < r){
        int p = lomuto(a, l , r);
        qs(a, l, p-1);
        qs(a, p+1, r);
    }
}   
int main() {
    cin >> n;
    for (int i = 0;i<n;i++) cin >> a[i];
    qs(a, 0, n-1);
    for (int i = 0;i<n;i++) cout << a[i] << " ";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
