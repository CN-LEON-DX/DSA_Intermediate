// Cho xâu kí tự S chỉ bao gồm các kí tự in thường, hãy kiểm tra xem có thể sắp đặt lại các kí tự trong xâu sao cho không có 2 kí tự kề nhau nào giống nhau hay không?

// Input Format

// Dòng duy nhất chứa xâu S

// Constraints

// 1<=len(S)<=10000;

// Output Format

// Nếu có thể sắp đặt lại xâu kí tự in ra YES, ngược lại in ra NO.

// Sample Input 0

// aqeaaqwq
// Sample Output 0

// YES
// Cach giai 
// 1. Duyet qua xau S, dem so lan xuat hien cua tung ki tu
// 2. Sap xep lai mang dem theo thu tu giam dan
// 3. Neu phan tu dau tien > (n+1)/2 thi NO
// 4. Neu khong thi YES
// Tại sao lại là (n+1)/2? Vì nếu có 2 kí tự kề nhau giống nhau thì số lần xuất hiện của kí tự đó phải lớn hơn (n+1)/2
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
    string s; cin >> s;
    int n = s.size();
    int a[26] = {0};
    for (char c : s) a[c-'a']++;
    sort(a, a+26, greater<int>());
    if (a[0] > (n+1)/2) cout << "NO";
    else cout << "YES";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}