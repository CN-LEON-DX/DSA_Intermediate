// Cho một mê cung được mô tả dưới dạng một ma trận nhị phân có N hàng và N cột. Một con chuột bắt đầu tử ô (1, 1) và muốn di chuyển tới ô (N, N). Con chuột chỉ được di chuyển sang trái, sang phải, lên trên và xuống dưới và chỉ được di chuyển tới ô nào đó nếu ô đó có giá trị là 1. Bạn hãy in ra các cách đi hợp lệ của con chuột, trong đó nếu con chuột đi sang phải thì nước đi được mô tả là chữ R, và nếu con chuột đi xuống dưới thì nước đi được mô tả là chữ D, nếu đi sang trái thì nước đi được mô tả là chữ L, nếu đi lên trên thì nước đi được mô tả là chữ U. Nếu con chuột không thể đi xuống ô (N, N) thì in ra -1. Chú ý trên mỗi đường đi con chuột chỉ có thể đi qua 1 ô nào đó đúng 1 lần.

// Input Format

// Dòng thứ nhất đưa vào N; N dòng tiếp theo mỗi dòng gồm N số;

// Constraints

// 1<=N<=8; Dữ liệu đảm bảo ô (1, 1) là số 1.

// Output Format

// Đưa ra các đường đi hợp lệ theo thứ tự từ điển tăng dần trên từng dòng.

// Sample Input 0

// 4
// 1 1 1 1 
// 1 1 0 1 
// 1 1 1 1 
// 0 1 1 1 
// Sample Output 0

// DDRDRR
// DDRDRURD
// DDRRDR
// DDRRRD
// DDRUURRDDD
// DDRUURRDDLDR
// DRDDRR
// DRDDRURD
// DRDRDR
// DRDRRD
// DRURRDDD
// DRURRDDLDR
// DRURRDDLLDRR
// RDDDRR
// RDDDRURD
// RDDRDR
// RDDRRD
// RDLDRDRR
// RDLDRDRURD
// RDLDRRDR
// RDLDRRRD
// RRRDDD
// RRRDDLDR
// RRRDDLLDRR
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[10][10];
string s = "";
int t = 0;
void Try(int i, int j){
    if (i==n && j == n){
        cout << s << endl;
        t = 1;
        return;
    }
    if (i + 1 <=n && a[i+1][j] == 1){
        s+="D";
        a[i+1][j] = 0;
        Try(i+1, j);
        s.pop_back();
        a[i+1][j] = 1;
    }
    if (j - 1>=1 && a[i][j-1] == 1){
        s+="L";
        a[i][j-1] = 0;
        Try(i, j-1);
        a[i][j-1] = 1;
        s.pop_back();
    }
    if (j + 1<=n && a[i][j+1]==1){
        s+="R";
        a[i][j+1] = 0;
        Try(i, j+1);
        s.pop_back();
        a[i][j+1] = 1;
    }
    if (i - 1>=1 && a[i-1][j] == 1){
        s+="U";
        a[i-1][j] = 0;
        Try(i-1, j);
        a[i-1][j] = 1;
        s.pop_back();
    }
}
int main() {
    cin >> n;
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    // Khong de con chuot quay lai nua 
    a[1][1] = 0;
    Try(1, 1);
    if (!t) cout << -1;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

// CACH 2 LOANG NGAN GON HON 
#include <bits/stdc++.h>
using namespace std;

int n; 
pair<int, int> d[4] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
int a[9][9];
// DLRU
int check = 0;
string S = "DLRU";
string s = "";
void Try(int i, int j){
    if (i==n && j == n) {
        cout << s << endl;
        check = 1;
        return;
    }
    for (int k = 0;k<4;k++){
        int x1 = d[k].first + i;
        int y1 = d[k].second + j;
        if (x1 >=1 && x1 <= n && y1 >=1 && y1 <= n && a[x1][y1]==1){
            s+=S[k];
            a[x1][y1] = 0;
            Try(x1, y1);
            s.pop_back();
            a[x1][y1] = 1;
        }
    }
}
int main(){
    cin >> n;
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++) cin >> a[i][j];
    a[1][1] = 0;
    Try(1, 1);
    if (!check){
        cout << -1;
    }
    return 0;
}