// Có n quả táo và m cái hộp, 28Tech muốn tìm số cách chia n quả táo này vào m hộp sao cho hộp nào cũng có ít nhất 1 quả táo. Bạn hãy giúp anh ta nhé.

// Input Format

// 2 số nguyên n, m

// Constraints

// 1 ≤ m ≤ n ≤ 1000

// Output Format

// Kết quả của bài toán lấy dư với 1000000007 (1e9 + 7)

// Sample Input 0

// 6 3
// Sample Output 0

// 10
// Explanation 0

// Có 10 cách cách chia như sau (2, 2, 2) (1, 1, 4) (1, 4, 1) (4, 1, 1) (1, 2, 3) (1, 3, 2) (2, 1, 3) (2, 3, 1) (3, 1, 2) (3, 2, 1)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INT = 1000000007;
const int MAX = 1001;
ll a[MAX+1][MAX+1];
void pascal(){
    for (int i = 1;i<=MAX;i++){
        for (int j = 1;j<=i;j++){
            if (j==1 || j==i){
                a[i][j] = 1ll;
            }else{
                a[i][j] = (a[i-1][j]+a[i-1][j-1])%INT;
             }
        }
    }
}
int main(){
    int n, m; cin >> n >> m;
    pascal();
    int k = n - m;
    // (K)C(M-K+1) nhung do ta de cac chu mang bat dau la 1 nen ta can phai them vao 1 don vi
    cout << a[m+k][k+1]%INT;
    return 0;
}