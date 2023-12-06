// Đếm số cách đặt 2 con mã trên bàn cờ vua cỡ k × k với
//  k = 1, 2, 3, .. n sao cho chúng không ăn nhau, 2 con mã này được coi là giống nhau.

// Input Format

// Số nguyên dương n duy nhất

// Constraints

// 1≤n≤10000

// Output Format

// Gồm n dòng, mỗi dòng là đáp án của bài toán.

// Sample Input 0

// 7
// Sample Output 0

// 0
// 6
// 28
// 96
// 252
// 550
// 1056
// Explanation 0

// Giải thích : với bàn cờ cỡ 1 x 1, 
// không có cách nào. 
// Với bàn cờ cỡ 2x2 có 6 cách đặt 2 con mã sao cho chúng không ăn nhau
// . Tương tự với các cỡ từ 3 tới 7.
// 
// Dùng cách đếm số hình chữ nhật 2 * 3 trên bàn cờ n * n để giải bài này.
// code     
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n; cin >> n;
    for (ll i = 1;i<=n;i++){
        if (i==1){
            cout << 0 << endl;
        }else if (i==2){
            cout << 6 << endl;
        }else{
            // (k*k)C2 - (k-1)*(k-2)*2*2;
            ll result = (i*i)*(i*i-1)/2 - (i-1)*(i-2)*2*2;
            cout << result << endl;
        }
    }
    return 0;
}
