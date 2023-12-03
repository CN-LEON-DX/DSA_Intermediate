// Đưa ra số nguyên tố thứ k trong phân tích thừa số nguyên tố của một số nguyên dương n. Ví dụ n=28, k=3 ta có kết quả là 7 vì 28=2x2x7.

// Input Format

// 2 số n,k

// Constraints

// 1 ≤n,k≤10^9

// Output Format

// In ra thừa số nguyên tố thứ k của n, nếu n không có thừa số nguyên tố thứ k thì in ra -1.

// Sample Input 0

// 28 3
// Sample Output 0

// 7
// Sample Input 1

// 8 5
// Sample Output 1

// -1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void solve(){
    int n, k; cin >> n >> k;
    int ok = 1;
    for (int i = 2;i*i<=n;i++){
        if (n%i==0){
            while (n%i==0){
                if (k==0){
                    cout << i; 
                    return;
                }
                k--;
                n/=i;
            }
            if (k==0){
                    cout << i;
                    return;
                }
        }
    }
    if (n>1) {
        k--;
        if (k==0) {
            cout << n;
            return;
        }
    }
    cout << -1;
}
int main() {
    solve();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}