// Cho mảng số nguyên A[] có N phần tử đã được sắp xếp theo thứ tự giảm dần. Có Q truy vấn, mỗi truy vấn yêu cầu bạn kiểm tra xem phần tử X có xuất hiện trong mảng hay không?

// Cách 1 : Sắp xếp mảng tăng dần rồi dùng binary_search để tìm kiếm nhanh

// Cách 2 : Đưa các phần tử trong mảng vào set để tìm kiếm nhanh

// Mỗi truy vấn chỉ mất O(logN)

// Input Format

// Dòng đầu tiên là số nguyên dương N. Dòng thứ 2 là N phần tử trong mảng, các phần tử viết cách nhau một dấu cách. Dòng thứ 3 là số lượng truy vấn Q. Q dòng tiếp theo mỗi dòng là một số nguyên dương X.

// Constraints

// 1<=N<=10^6; 1<=Q<=10^3; 0<=A[i],X<=10^9

// Output Format

// Đối với truy vấn in ra YES trên 1 dòng nếu X xuất hiện trong mảng, ngược lại in ra NO.

// Sample Input 0

// 5
// 5 4 3 2 1
// 2
// 2
// 8
// Sample Output 0

// YES
// NO
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool bnr(int a[],int l, int r, int k){
    while (l <= r){
        int mid = (l + r)/2;
        if (a[mid]==k) return true;
        else if (a[mid]>k){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return 0;
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    int test; cin >> test;
    while (test--){
        int k; cin >> k;
        if (bnr(a, 0, n-1, k)){
            cout << "YES" << endl;
        }else cout << "NO" << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}