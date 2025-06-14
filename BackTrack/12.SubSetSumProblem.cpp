// Cho mảng A[] gồm n phần tử, hãy xác định xem có thể chia mảng A[] thành 2 tập sao cho tổng của 2 tập bằng nhau hay không?

// Input Format

// Dòng đầu tiên là số nguyên n; Dòng thứ 2 gồm n số nguyên của mảng A[]

// Constraints

// 1<=n<=20; 1<=A[i]<=100;

// Output Format

// In ra 1 nếu có thể chia mảng thành 2 phần bằng nhau, ngược lại in 0.

// Sample Input 0

// 5
// 9 9 4 4 5 
// Sample Output 0

// 0
// Sample Input 1

// 4
// 1 2 3 4
// Sample Output 1

// 1

// Cac buoc giai la:
// - Buoc 1: Tinh tong cac phan tu trong mang A[] va kiem tra xem tong co chia het cho 2 hay khong. Neu khong thi khong the chia duoc
// - Buoc 2: Sap xep mang A[] theo thu tu giam dan
// - Buoc 3: Tinh tong cac phan tu trong mang A[] chia cho 2, goi la sum. Khoi tao mang B[] gom 2 phan tu voi gia tri ban dau la sum
// - Buoc 4: Goi ham Try(i) de chia cac phan tu trong mang A[] vao 2 tap con sao cho tong cac phan tu trong moi tap con bang sum
// - Buoc 5: Neu co the chia duoc thi in ra 1, nguoc lai in ra 0
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, a[21], b[3];
int check = 0;
void Try(int i) {
    if (check == 1) return;
    if (i > n) {
        if (b[1] == 0 && b[2] == 0) {
            check = 1;
        }
        return;
    }
    if (b[1] >= a[i]) {
        b[1] -= a[i];
        Try(i + 1);
        b[1] += a[i];
    }
    if (b[2] >= a[i]) {
        b[2] -= a[i];
        Try(i + 1);
        b[2] += a[i];
    }
}
int main() {
    cin >> n;
    for (int i = 1;i<=n;i++) cin >> a[i];
    int sum = accumulate(a+1, a+n+1, 0);
    sort(a+1, a+n+1, greater<int>());
    for (int i = 1;i<=2;i++){
        b[i] = sum/2;
    }
    if (sum%2==0){
        Try(1);
        if (check){
            cout << 1;
        }else cout << 0;
    }else cout << 0;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

