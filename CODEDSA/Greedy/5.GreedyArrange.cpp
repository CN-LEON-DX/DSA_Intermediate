// Cho mảng A[] gồm N số và thực hiện các thao tác theo nguyên tắc dưới đây: 1. Ta chọn một mảng con sao cho phần tử ở giữa của mảng con cũng là phần tử ở giữa của mảng A[] (trong trường hợp N lẻ). 2. Đảo ngược mảng con đã chọn trong mảng A[]. Ta được phép chọn mảng con và phép đảo ngược mảng con bao nhiêu lần tùy ý. Ví dụ với mảng A[] = {1, 6, 3, 4, 5, 2, 7} ta có câu trả lời là YES vì: ta chọn mảng con {3, 4, 5} và đảo ngược để nhận được mảng A[]={1, 6, 5, 4, 3, 2, 7}, chọn tiếp mảng con {6, 5, 4, 3, 2} và đảo ngược ta nhận được mảng A[]={1, 2, 3, 4, 5, 6, 7}. Hãy cho biết ta có thể sắp xếp được mảng A[] bằng cách thực hiện các thao tác kể trên hay không?

// Input Format

// Dòng 1 chứa số nguyên dương N là số lẻ.
// Dòng 2 chứa N số nguyên của mảng A[]

// Constraints

// 1<=N<=10^6; 0<=A[i]<=10^9;

// Output Format

// In ra YES hoặc NO là đáp án của bài toán

// Sample Input 0

// 5
// 1 3 8 7 3 
// Sample Output 0

// NO
// Sample Input 1

// 5
// 1 4 3 2 5
// Sample Output 1

// YES
// Y tuong cua bai nay la ta se chon cac mang con co do dai la 3, 5, 7, 9, ... va doi chieu voi mang A[] de xem co phai la mang doi xung hay khong. Neu la mang doi xung thi YES, nguoc lai la NO.
code
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
#define INT 1000000007
int main() {
    int n; cin >> n;
    int a[n];
    for (int &i : a) cin >> i;
    for (int i = 3;i<=n;i+=2){
        int l = (n-i)/2;
        int r = l+i-1;
        if (a[mid] < a[mid-1] || a[mid] < a[mid+1]){
            cout << "NO";
            return 0;
        }
        if (a[l] < a[l+1] || a[r] < a[r-1]){
            cout << "NO";
            return 0;
        }
        
    }
    if (cnt) cout << "YES";
    else cout << "NO";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}