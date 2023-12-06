// Có n đứa trẻ và m quả táo, 
// 28Tech muốn đếm số cách chia táo cho n đứa trẻ,
// nhưng trong trường hợp này không nhất thiết đứa trẻ nào cũng phải có táo.
// Ví dụ, có 3 đứa trẻ và 2 quả táo, có những cách chia như sau
// (0, 0, 2), (0, 2, 0), (2, 0, 0), (1, 1, 0), (0, 1, 1), (1, 0 ,1). Bạn hãy giúp anh ấy nhé ! 
//Ở đây n với m, mình cho <= 25, vậy bạn thử nghĩ xem trong trường hợp n,m <= 1000, 
// hoặc n,m <= 10^6, và yêu cầu in ra kết quả của bài toán chia dư với 10^9 + 7 thì hướng giải như thế nào?

// Input Format

// 2 số n và m

// Constraints

// 1 ≤ m, n ≤ 25

// Output Format

// Đáp án của bài toán

// Sample Input 0

// 3 2
// Sample Output 0

// 6

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAX = 1001;
ll a[MAX+1][MAX+1];
void pascal(){
    for (int i = 1;i<MAX;i++){
        for (int j = 1;j<=i;j++){
            if (i==j||j==1) a[i][j] = 1;
            else{
                a[i][j] = a[i-1][j]+a[i-1][j-1];
            }
        }
    }
}
int main() {
    pascal();
    int n, m; cin >> m >> n;
    cout << a[m+n][n+1] << endl;
    return 0;
}
