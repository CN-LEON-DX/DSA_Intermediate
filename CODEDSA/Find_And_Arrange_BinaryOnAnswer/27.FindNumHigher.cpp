// Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là tìm giá trị nhỏ nhất (phải thuộc mảng A[]) lớn hơn A[i] (i=0, 1, 2,.., n-1). Đưa ra ‘_’ nếu A[i] không có phần tử lớn hơn nó. Ví dụ với mảng A[] = {13, 6, 7, 12}, ta có kết quả là { _ , 7 . 12, 13}.

// Input Format

// Dòng đầu tiên đưa vào n là số phần tử của mảng A[]; Dòng kế tiếp đưa vào n số A[i] của mảng; các số được viết cách nhau một vài khoảng trống.

// Constraints

// 1≤ N ≤10^5; 1≤ A[i] ≤10^5.

// Output Format

// Đưa ra kết quả trên 1 dòng

// Sample Input 0

// 9
// 6 3 9 8 10 2 1 15 7
// Sample Output 0

// 7 6 10 9 15 3 2 _ 8
#include <iostream>
#include <algorithm>
using namespace std;

int bnr(int b[], int n, int l, int r, int index){
    int res = -1;
    while (l <= r){
        int mid = (l + r)/2;
        if (b[mid]>index){
            res = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return res;
}

int main() {
    int n; cin >> n;
    int a[n];
    int b[n];
    for (int i = 0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = 0;i<n;i++){
        int ok = bnr(b, n, 0, n-1, a[i]);
        if (ok != -1 && b[ok] != a[i]){
            cout << b[ok] << " ";
        }else{
            cout << "_" << " ";
        }
    }
    return 0;
}