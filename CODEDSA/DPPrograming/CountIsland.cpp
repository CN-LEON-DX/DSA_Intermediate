#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 1 , 0};
int dy[4] = {0, 1, 0, -1};
bool mark[1001][1001];
int cnt = 0;

void loang(int x, int y, int a[][1001], int n, int m){
    a[x][y] = -1;
    for (int i = 0;i<4;i++){
        if(x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m && a[x + dx[i]][y + dy[i]] == 1 && !mark[x + dx[i]][y + dy[i]]){
            mark[x + dx[i]][y + dy[i]] = true;
            loang(x + dx[i], y + dy[i], a, n, m);
        }
    }
}

void lg( int a[][1001], int n , int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]==1 && !mark[i][j]){
                mark[i][j] = true;
                loang(i, j, a, n, m);
                cnt++;
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    int a[n][1001];
    for (int i = 0;i<n;i++)
        for (int j = 0;j<m;j++){
            cin >> a[i][j];
        }
    lg(a, n, m);
    cout << cnt << endl;
    return 0;
}
Cho ma trận nhị phân gồm N hàng và M cột chỉ bao gồm các số 0 và 1.
 Hãy đếm số lượng miền các số 1 trong ma trận, các ô số 1 được coi là cùng miền nếu chúng có chung cạnh.

Input Format

Dòng đầu tiên N và M. N dòng tiếp theo mỗi dòng gồm M phần tử.

Constraints

1≤N,M≤50.

Output Format

In ra số lượng miền số 1 trong ma trận.

Sample Input 0

4 7
0 1 1 0 1 1 0 
1 1 1 1 1 1 1 
1 0 0 0 0 1 1 
1 1 0 1 0 0 0 
Sample Output 0

2
Sample Input 1

8 8
1 1 0 1 1 1 1 0 
0 1 1 1 0 0 0 1 
1 1 0 0 0 0 1 1 
0 1 0 1 0 0 1 1 
1 0 0 1 0 0 0 1 
0 1 0 1 1 1 1 0 
0 0 0 0 1 0 1 1 
1 0 0 0 0 0 0 0 
Sample Output 1

6