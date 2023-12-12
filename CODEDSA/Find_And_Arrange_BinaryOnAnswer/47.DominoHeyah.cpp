// Trong lớp học của Tèo có các thanh domino hình chữ nhật có chiều rộng a và có chiều cao b. 
//Tèo hiện là học sinh lớp 1, thầy giáo có giao cho Tèo một bài 
//toán đó là hãy tìm 1 bảng hình vuông có cạnh nhỏ nhất sao cho 
//có thể xếp n thanh domino vào hình vuông này. Tèo không nhất 
//thiết phải xếp kín cái bảng hình vuông này nhưng không được 
//phép xoay ngang thanh domino. Dưới đây là một ví dụ về cách xếp
// thanh domino có a = 2, b = 3 vào bảng hình vuông có cạnh 9

// image

// Input Format

// 3 số a, b, n trên 1 dòng

// Constraints

// 1<=n,a,b<=10^9;

// Output Format

// In ra chiều dài cạnh của hình vuông nhỏ nhất tìm được.

// Sample Input 0

// 2 3 10
// Sample Output 0

// 9
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
ll a, b, n; 

bool check(ll mid){
    return (mid/a)*(mid/b)>=n;// dien tich lon hon thi t con tim tiep
}
int main() {
    cin >> a >> b >> n;
    ll l = 1;
    ll r = max(a, b)*n;
    ll res = -1;
    while (l<=r){
        ll mid = (l+r)/2;
        if (check(mid)){
            res = mid;
            r = mid-1;
        }else{
            l = mid + 1;
        }
    }
    cout << res;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}