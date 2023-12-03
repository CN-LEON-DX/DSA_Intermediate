// Viết chương trình đếm xem trong đoạn giữa 2 số a và b có bao nhiêu số là số nguyên tố và tất cả các chữ số của nó cũng là số nguyên tố. Gợi ý : viết hàm 2 là hàm số nguyên tố và hàm kiểm tra tất 
// cả các chữ số của nó là số nguyên tố sau đó duyệt từ a đến b và kết hợp 2 hàm này để kiểm tra.
// Input Format

// Gồm 2 số nguyên dương a và b.

// Constraints

// 1≤a≤b≤10^7

// Output Format

// Ghi ra số lượng số thỏa mãn trên một dòng.

// Sample Input 0

// 1234 5678
// Sample Output 0

// 26
// Cho số nguyên không âm N, liệt kê các số nguyên tố không vượt quá N.

// Input Format

// Số nguyên N

// Constraints

// 0≤n≤10^7

// Output Format

// In ra các số nguyên tố không vượt quá N trên 1 dòng, các số cách nhau một khoảng trắng.

// Sample Input 0

// 13
// Sample Output 0

// 2 3 5 7 11 13 
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
    while (n){
        if (!a[n%10]) return 0;
        n/=10;
    }
    return 1;
}
void solve(){
    int n, k; cin >> n >> k;
    sang();
    for (int i = n;i<=k;i++){
        if (a[i] && check(i)) cout << i << " ";
    }
}

int main() {
    solve();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}