// Viết chương trình cho phép nhập vào n và liệt kê các số 
// nguyên tố thỏa mãn nhỏ hơn hoặc bằng n và có chữ số cuối cùng lớn nhất. Có bao nhiêu số như vậy?

// Input Format

// Số nguyên dương n

// Constraints

// 1≤n≤10^7

// Output Format

// Dòng đầu tiên liệt kê các số thỏa mãn, và dòng thứ 2 in ra số lượng số thỏa mãn.

// Sample Input 0

// 200
// Sample Output 0

// 2 3 5 7 11 13 17 19 23 29 37 47 59 67 79 89 101 103 107 109 113 127 137 139 149 157 167 179 199
// 29
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX  10000001
int a[MAX];
void sang(){
    for (int i = 0;i<=MAX;i++) a[i] = 1;
    a[0] = 0;
    a[1] = 0;
    for (int i = 2;i<=sqrt(MAX);i++){
        if (a[i])
        for (int j = i * i;j<=MAX;j+=i){
            a[j] = 0;
        }
    }
}
bool check(int n){
    if (n<10) return 1;
    int t = n%10;
    n/=10;
    int ok = 0;
    while (n){
        if (n%10>t) return 0;
        n/=10;
    }
    return 1;
}

void solve(){
    sang();
    int n; cin >> n;
    int cnt = 0;
    for (int i = 2;i<=n;i++){
        if (a[i]){
            if (check(i)){
                cnt++;
                cout << i << " ";
            }
        }
    }
    cout << endl;
    cout << cnt;
}

int main() {
    solve();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}