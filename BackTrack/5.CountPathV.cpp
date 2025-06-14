// Cho ma trận A[M][N]. Nhiệm vụ của bạn là đếm tất cả các đường đi từ phần tử A[0][0] đến phần tử A[M-1][N-1]. Bạn chỉ được phép dịch chuyển xuống dưới hoặc sang phải phần tử liền kề với vị trí hiện tại.

// Input Format

// Dòng 1 là hai số M, N tương ứng với số hàng và số cột của ma trận; Dng tiếp theo đưa vào các phần tử của ma trận A[][]; các số được viết cách nhau một vài khoảng trống.

// Constraints

// 1≤M, N, <=10; A[i][j]≤100;

// Output Format

// Đưa ra số cách di chuyển

// Sample Input 0

// 3 5
// 4 6 8 3 1 
// 9 8 8 9 1 
// 10 6 3 4 5 
// Sample Output 0

// 15
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[11][11];
int res = 0;
pair<int, int> d[2] = {{1, 0}, {0, 1}};
void init(){
    cin >> n >> m;
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            cin >> a[i][j];
        }
    }
}

void Try(int i, int j){
    if (i==n && j==m){
        res++;
        return;
    }
    if (i+1<=n) Try(i+1, j);
    if (j+1<=m) Try(i, j+1);
}

int main() {
    init();
    Try(1, 1);
    cout << res;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
