#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int x, y; cin >> x >> y;
    for (int i = x ;i<=y;i++){
        for (int j = 2;j*j<=i;j++){
            if (i%j==0 && i%(j*j)==0){
                cout << i << " ";
                break;
            }
        }
    }
}

int main() {
    solve();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
// Một số được coi là số đẹp khi nó đồng thời vừa chia hết cho một số nguyên tố và chia hết cho bình phương của số nguyên tố đó. Viết chương trình liệt kê các số đẹp như vậy trong đoạn giữa hai số nguyên dương cho trước.

// Input Format

// 2 số nguyên dương a, b

// Constraints

// 1≤a≤b≤10^6

// Output Format

// In ra các số đẹp trong đoạn từ a tới b

// Sample Input 0

// 4 50
// Sample Output 0

// 4 8 9 12 16 18 20 24 25 27 28 32 36 40 44 45 48 49 50